/* 실습 페이지: practice.html?set=1…5&q=1…10
   - 문제 데이터: assets/problems.js (tools/build.py 가 problems/ 에서 생성)
   - Python 실행: Pyodide(CPython 3.12 WebAssembly)를 Web Worker 안에서 돌려요. 무한 반복이면 5초 뒤 worker 를 끊고 다시 띄워요.
   - 채점 규칙은 check.py 와 같아요: 줄 끝 공백과 맨 끝 빈 줄은 무시, 그 외는 글자 하나까지 같아야 통과. */
(function () {
  var D = window.BP_PROBLEMS;
  if (!D || !window.BP || !document.getElementById('ide')) return;

  var PYODIDE = 'https://cdn.jsdelivr.net/pyodide/v0.26.4/full/';
  var TIMEOUT_MS = 5000;
  var esc = BP.escapeHtml;

  /* ── 주소 → 세트·문제 ── */
  var qs = new URLSearchParams(location.search);
  var setNo = parseInt(qs.get('set'), 10);
  if (!(setNo >= 1 && setNo <= D.sets.length)) setNo = 1;
  var S = D.sets[setNo - 1];
  var qNo = parseInt(qs.get('q'), 10);
  if (!(qNo >= 1 && qNo <= S.problems.length)) qNo = 1;
  var Q = S.problems[qNo - 1];

  var progress = BP.loadProgress();
  var codes = BP.loadCode();

  document.title = qNo + '. ' + Q.title + ' · ' + S.title + ' · 기초프로그래밍';

  /* ── 세트 탭 · 문제 번호 · 진행률 ── */
  function renderTabs() {
    var tabs = document.querySelectorAll('#set-tabs a[data-set]');
    for (var i = 0; i < tabs.length; i++) {
      var n = parseInt(tabs[i].getAttribute('data-set'), 10);
      var set = D.sets[n - 1];
      if (!set) { tabs[i].hidden = true; continue; }
      var st = BP.setStats(set, progress);
      tabs[i].title = set.title + ' — ' + set.sub + ' (통과 ' + st.pass + '/' + st.total + ')';
      tabs[i].classList.toggle('done', st.pass === st.total);
      if (n === setNo) tabs[i].setAttribute('aria-current', 'page'); else tabs[i].removeAttribute('aria-current');
    }
  }
  function statusOf(q) {
    var r = progress[q.id];
    if (!r) return '';
    return r.passed === r.total ? 'ok' : 'retry';
  }
  function renderNums() {
    var html = '';
    S.problems.forEach(function (q) {
      var st = statusOf(q);
      html += '<a href="practice.html?set=' + setNo + '&q=' + q.no + '" class="' + st + '"' + (q.no === qNo ? ' aria-current="page"' : '') +
        ' title="' + esc(q.no + '. ' + q.title) + '">' + q.no + '</a>';
    });
    document.getElementById('qnums').innerHTML = html;
    var st = BP.setStats(S, progress);
    document.getElementById('p-ok').textContent = st.pass;
    document.getElementById('p-total').textContent = st.total;
    document.getElementById('p-score').textContent = st.pass * 10;
    document.getElementById('p-score-wrap').hidden = !S.scored;   // 과제·연습 세트는 점수 대신 통과 수만
    document.getElementById('bar-ok').style.width = (st.pass / st.total * 100) + '%';
    document.getElementById('bar-retry').style.width = ((st.tried - st.pass) / st.total * 100) + '%';
  }
  function renderState() {
    var el = document.getElementById('q-state');
    var r = progress[Q.id];
    el.className = 'state';
    if (!r) { el.textContent = '아직 제출 전'; return; }
    if (r.passed === r.total) { el.className = 'state ok'; el.textContent = '통과 ✓ ' + r.passed + '/' + r.total; }
    else { el.className = 'state retry'; el.textContent = '다시 풀기 ' + r.passed + '/' + r.total; }
  }
  renderTabs(); renderNums(); renderState();

  /* ── 문제 본문 ── */
  document.getElementById('q-no').textContent = qNo;
  document.getElementById('q-title').textContent = Q.title;
  document.getElementById('q-slot').textContent = Q.slot;
  document.getElementById('q-lesson').textContent = '엘리스 ' + Q.lesson;
  if (S.outside) { var ob = document.createElement('span'); ob.className = 'tag warn'; ob.textContent = '중간고사 범위 밖'; document.getElementById('q-lesson').after(ob); }
  (function () {
    var h = Q.story + '<h3>지시사항</h3>' + Q.instructions;
    Q.examples.forEach(function (ex, i) {
      h += '<h3>입출력 예시 ' + (i + 1) + '</h3><div class="ex"><div><span class="lbl">입력</span><pre>' + esc(ex['in'].replace(/\n$/, '')) + '</pre></div>' +
        '<div><span class="lbl">출력</span><pre>' + esc(ex.out) + '</pre></div></div>';
    });
    if (Q.tips) h += '<div class="tips"><span class="lbl">TIPS</span>' + Q.tips + '</div>';
    document.getElementById('q-body').innerHTML = h;
  })();
  var prev = document.getElementById('q-prev'), next = document.getElementById('q-next');
  if (qNo <= 1) prev.disabled = true; else prev.onclick = function () { go(qNo - 1); };
  if (qNo >= S.problems.length) next.disabled = true; else next.onclick = function () { go(qNo + 1); };
  function go(n) { saveCodeNow(); location.href = 'practice.html?set=' + setNo + '&q=' + n; }

  /* ── 편집기 (Ace) ── */
  var editor = null, plain = null;
  var startCode = codes[Q.id] != null ? codes[Q.id] : Q.starter;
  if (window.ace) {
    ace.config.set('basePath', 'https://cdnjs.cloudflare.com/ajax/libs/ace/1.36.2/');
    editor = ace.edit('editor', {
      mode: 'ace/mode/python', theme: 'ace/theme/tomorrow_night_eighties',
      fontSize: 14, tabSize: 4, useSoftTabs: true, showPrintMargin: false, wrap: true,
      highlightActiveLine: true, displayIndentGuides: true
    });
    editor.session.setValue(startCode, -1);
    editor.commands.addCommand({ name: 'run', bindKey: { win: 'Ctrl-Enter', mac: 'Cmd-Enter' }, exec: function () { runClick(); } });
    editor.commands.addCommand({ name: 'submit', bindKey: { win: 'Ctrl-Shift-Enter', mac: 'Cmd-Shift-Enter' }, exec: function () { submitClick(); } });
    editor.focus();
  } else {
    // Ace 를 못 불러오면 평범한 textarea 로
    var box = document.getElementById('editor');
    plain = document.createElement('textarea');
    plain.className = 'stdin'; plain.style.height = '100%'; plain.spellcheck = false; plain.value = startCode;
    box.appendChild(plain);
  }
  function getCode() { return editor ? editor.getValue() : plain.value; }
  function setCode(s) { if (editor) editor.session.setValue(s, -1); else plain.value = s; }
  var saveTimer = null;
  function saveCodeNow() {
    codes = BP.loadCode();
    var c = getCode();
    if (c === Q.starter) delete codes[Q.id]; else codes[Q.id] = c;
    BP.saveCode(codes);
  }
  function scheduleSave() { clearTimeout(saveTimer); saveTimer = setTimeout(saveCodeNow, 400); }
  if (editor) editor.session.on('change', scheduleSave); else plain.addEventListener('input', scheduleSave);
  window.addEventListener('pagehide', saveCodeNow);

  document.getElementById('ed-reset').onclick = function () {
    if (this.classList.contains('armed')) { setCode(Q.starter); saveCodeNow(); this.classList.remove('armed'); this.textContent = '시작 코드로 되돌리기'; }
    else { this.classList.add('armed'); this.textContent = '정말 되돌릴까요? 한 번 더 누르세요'; var b = this; setTimeout(function () { b.classList.remove('armed'); b.textContent = '시작 코드로 되돌리기'; }, 3000); }
  };
  var solBox = document.getElementById('sol'), solBtn = document.getElementById('ed-sol');
  document.getElementById('sol-code').textContent = Q.solution;
  solBtn.onclick = function () {
    var open = solBox.hidden;
    solBox.hidden = !open;
    solBtn.setAttribute('aria-pressed', open ? 'true' : 'false');
    solBtn.textContent = open ? '정답 닫기' : '정답 보기';
  };
  document.getElementById('sol-copy').onclick = function () { setCode(Q.solution); saveCodeNow(); if (editor) editor.focus(); };

  /* ── 입력 탭 ── */
  var stdin = document.getElementById('stdin');
  stdin.value = Q.examples.length ? Q.examples[0]['in'] : '';
  (function () {
    var h = '';
    Q.examples.forEach(function (ex, i) { h += '<button class="chip" type="button" data-i="' + i + '">입력 예시 ' + (i + 1) + '</button>'; });
    h += '<button class="chip" type="button" data-i="clear">비우기</button>';
    var box = document.getElementById('in-presets');
    box.innerHTML = h;
    box.onclick = function (e) {
      var b = e.target.closest('button'); if (!b) return;
      var i = b.getAttribute('data-i');
      stdin.value = i === 'clear' ? '' : Q.examples[+i]['in'];
    };
  })();

  /* ── 출력 탭 ── */
  var tabs = document.querySelectorAll('.otab');
  function showTab(name) {
    for (var i = 0; i < tabs.length; i++) {
      var on = tabs[i].getAttribute('data-tab') === name;
      tabs[i].setAttribute('aria-selected', on ? 'true' : 'false');
      document.getElementById('panel-' + tabs[i].getAttribute('data-tab')).hidden = !on;
    }
  }
  for (var t = 0; t < tabs.length; t++) tabs[t].onclick = function () { showTab(this.getAttribute('data-tab')); };

  /* ── Pyodide worker ── */
  var WORKER_SRC = [
    'importScripts(' + JSON.stringify(PYODIDE + 'pyodide.js') + ');',
    'var py = null;',
    'var ready = loadPyodide({ indexURL: ' + JSON.stringify(PYODIDE) + ' }).then(function (p) { py = p; postMessage({ type: "ready", version: p.runPython("import sys; sys.version.split()[0]") }); }, function (e) { postMessage({ type: "fail", error: String(e) }); });',
    'function cleanErr(msg) {',
    '  var lines = String(msg).split("\\n"); var i = 0;',
    '  for (var k = 0; k < lines.length; k++) if (lines[k].indexOf(\'File "<exec>"\') >= 0) { i = k; break; }',
    '  var kept = lines.slice(i).filter(function (l) { return l.trim(); });',
    '  return kept.join("\\n").replace(/File "<exec>", /g, "");',
    '}',
    'function runOne(code, input) {',
    '  var lines = input.split("\\n"); if (input.endsWith("\\n")) lines.pop();',
    '  var i = 0, out = "", err = "";',
    '  py.setStdin({ stdin: function () { return i < lines.length ? lines[i++] + "\\n" : null; }, autoEOF: false, isatty: false });',
    '  var dec = new TextDecoder(), dec2 = new TextDecoder();',
    '  // batched 모드는 줄바꿈 없이 끝난 마지막 줄(print(x, end=" ") 등)을 버리므로 write 모드로 바이트를 그대로 받는다',
    '  py.setStdout({ write: function (b) { out += dec.decode(b, { stream: true }); return b.length; }, isatty: false });',
    '  py.setStderr({ write: function (b) { err += dec2.decode(b, { stream: true }); return b.length; }, isatty: false });',
    '  var ns = py.globals.get("dict")(); ns.set("__name__", "__main__");',
    '  try { py.runPython(code, { globals: ns }); } catch (e) { err += (err ? "\\n" : "") + cleanErr(e.message); } finally { ns.destroy(); }',
    '  try { py.runPython("import sys\\nsys.stdout.flush()\\nsys.stderr.flush()"); } catch (e) {}',
    '  out += dec.decode(); err += dec2.decode();',
    '  // 프로그램이 다 읽지 않은 입력이 다음 실행으로 넘어가지 않게 남은 stdin 을 비운다',
    '  try { py.runPython("import sys\\nsys.stdin.read()"); } catch (e) {}',
    '  return { out: out, err: err.trim() };',
    '}',
    'onmessage = function (e) {',
    '  var m = e.data;',
    '  ready.then(function () {',
    '    if (!py) { postMessage({ type: "result", id: m.id, results: [], error: "Python 을 불러오지 못했어요" }); return; }',
    '    var results = [];',
    '    for (var k = 0; k < m.inputs.length; k++) { postMessage({ type: "progress", id: m.id, k: k }); results.push(runOne(m.code, m.inputs[k])); }',
    '    postMessage({ type: "result", id: m.id, results: results });',
    '  });',
    '};'
  ].join('\n');

  var worker = null, pyReady = false, busy = false, reqId = 0, pending = null, killTimer = null;
  var pystat = document.getElementById('pystat');
  var btnRun = document.getElementById('btn-run'), btnSubmit = document.getElementById('btn-submit');
  function setStat(cls, text) { pystat.className = 'pystat ' + cls; pystat.innerHTML = '<span class="dot"></span>' + esc(text); }
  function setButtons() { var on = pyReady && !busy; btnRun.disabled = !on; btnSubmit.disabled = !on; }

  function startWorker() {
    pyReady = false; busy = false; setButtons();
    setStat('', 'Python 준비 중… (처음 한 번은 10초쯤 걸려요)');
    try {
      worker = new Worker(URL.createObjectURL(new Blob([WORKER_SRC], { type: 'text/javascript' })));
    } catch (e) { setStat('fail', '이 브라우저에서는 실행 환경을 만들 수 없어요'); return; }
    worker.onmessage = function (e) {
      var m = e.data;
      if (m.type === 'ready') { pyReady = true; setStat('ready', 'Python ' + m.version + ' 준비됨'); setButtons(); }
      else if (m.type === 'fail') { setStat('fail', 'Python 을 불러오지 못했어요 — 인터넷 연결을 확인하고 새로고침하세요'); }
      else if (m.type === 'progress') { if (pending && pending.id === m.id) { pending.onProgress(m.k); armKill(); } }
      else if (m.type === 'result') {
        if (!pending || pending.id !== m.id) return;
        clearTimeout(killTimer);
        var p = pending; pending = null; busy = false; setStat('ready', 'Python 준비됨'); setButtons();
        p.done(m.results, m.error);
      }
    };
    worker.onerror = function (e) { setStat('fail', '실행 환경 오류: ' + (e.message || '알 수 없음')); };
  }
  function armKill() {
    clearTimeout(killTimer);
    killTimer = setTimeout(function () {
      if (!pending) return;
      var p = pending; pending = null;
      worker.terminate();
      startWorker();
      p.timeout();
    }, TIMEOUT_MS);
  }
  function execute(code, inputs, handlers) {
    if (!pyReady || busy) return;
    busy = true; setButtons(); setStat('busy', '실행 중…');
    pending = { id: ++reqId, onProgress: handlers.progress || function () {}, done: handlers.done, timeout: handlers.timeout };
    armKill();
    worker.postMessage({ id: pending.id, code: code, inputs: inputs });
  }
  startWorker();

  /* ── 실행 ── */
  var con = document.getElementById('console');
  function runClick() {
    if (btnRun.disabled) return;
    saveCodeNow();
    showTab('run');
    con.className = 'console';
    con.innerHTML = '<span class="meta">실행 중…</span>';
    var input = stdin.value;
    execute(getCode(), [input], {
      done: function (results, error) {
        if (error) { con.innerHTML = '<span class="err">' + esc(error) + '</span>'; return; }
        var r = results[0];
        var h = r.out ? esc(r.out) : '';
        if (r.err) h += (h ? '\n' : '') + '<span class="err">' + esc(r.err) + '</span>';
        if (!h) h = '<span class="meta">(출력이 없어요 — print() 를 빠뜨리지 않았는지 확인하세요)</span>';
        con.innerHTML = h;
      },
      timeout: function () {
        con.className = 'console timeout';
        con.innerHTML = '<span class="err">시간 초과 (' + (TIMEOUT_MS / 1000) + '초)</span>\n<span class="meta">끝나지 않는 반복문이 있는지 확인하세요. while 조건이 바뀌는지, break 가 실행되는지, input() 횟수가 입력 줄 수보다 많지 않은지 보세요.</span>';
      }
    });
  }
  btnRun.onclick = runClick;

  /* ── 제출(채점) ── */
  function norm(s) { return s.replace(/\n+$/, '').split('\n').map(function (l) { return l.replace(/\s+$/, ''); }).join('\n'); }
  function diffPre(mine, expected) {
    // 내 출력을 줄 단위로, 기대 출력과 다른 줄은 표시
    var a = mine.split('\n'), b = expected.split('\n'), h = '';
    var n = Math.max(a.length, b.length);
    for (var i = 0; i < n; i++) {
      if (i >= a.length) h += '<span class="dl miss">(줄 없음 — 기대: ' + esc(b[i]) + ')</span>';
      else if (i >= b.length || a[i] !== b[i]) h += '<span class="dl diff">' + esc(a[i] === '' ? ' ' : a[i]) + '</span>';
      else h += '<span class="dl">' + esc(a[i] === '' ? ' ' : a[i]) + '</span>';
    }
    return h;
  }
  var gradeBox = document.getElementById('grade'), gradeCnt = document.getElementById('grade-cnt');
  function submitClick() {
    if (btnSubmit.disabled) return;
    saveCodeNow();
    showTab('grade');
    gradeBox.innerHTML = '<p class="g-tip">채점 중… (0/' + Q.cases.length + ')</p>';
    var inputs = Q.cases.map(function (c) { return c[0]; });
    execute(getCode(), inputs, {
      progress: function (k) { gradeBox.innerHTML = '<p class="g-tip">채점 중… (' + k + '/' + Q.cases.length + ')</p>'; },
      done: function (results, error) {
        if (error) { gradeBox.innerHTML = '<p class="g-tip">' + esc(error) + '</p>'; return; }
        var passed = 0, h = '';
        results.forEach(function (r, i) {
          var exp = Q.cases[i][1], got = norm(r.out), ok = !r.err && got === exp;
          if (ok) passed++;
          h += '<details class="gcase ' + (ok ? 'ok' : 'bad') + '"' + (ok ? '' : ' open') + '><summary>테스트 ' + (i + 1) +
            '<span class="res">' + (ok ? '통과' : '틀림') + '</span></summary><div class="gbody">' +
            '<div><span class="lbl">입력</span><pre>' + esc(Q.cases[i][0].replace(/\n$/, '') || '(없음)') + '</pre></div>' +
            '<div><span class="lbl">기대 출력</span><pre>' + esc(exp) + '</pre></div>' +
            '<div><span class="lbl">내 출력</span><pre>' + (ok ? esc(got) : (got ? diffPre(got, exp) : '<span class="dl miss">(출력 없음)</span>')) + '</pre></div>' +
            (r.err ? '<div class="err">' + esc(r.err) + '</div>' : '') + '</div></details>';
        });
        finishGrade(passed, results.length, h, false);
      },
      timeout: function () {
        finishGrade(0, Q.cases.length, '<p class="g-tip">시간 초과 (' + (TIMEOUT_MS / 1000) + '초) — 끝나지 않는 반복문이 있는지 확인하세요. 실행 탭에서 입력 예시로 먼저 돌려 보세요.</p>', true);
      }
    });
  }
  function finishGrade(passed, total, body, timedOut) {
    var all = passed === total;
    progress = BP.loadProgress();
    progress[Q.id] = { passed: passed, total: total, at: Date.now() };
    BP.saveProgress(progress);
    renderTabs(); renderNums(); renderState();
    var sum = '<div class="g-sum ' + (all ? 'pass' : 'fail') + '"><span class="big">' + passed + ' / ' + total + '</span>' +
      (all ? '<span>모든 테스트 통과!' + (S.scored ? ' 이 문제는 10점이에요.' : '') + '</span>' : '<span>' + (timedOut ? '시간 초과' : '틀린 테스트가 있어요') + ' — 시험에선 모두 맞아야 점수를 받아요.</span>') +
      '<small>' + (all ? '다음 문제로 넘어가세요.' : '빨간 줄이 기대 출력과 다른 줄이에요. 띄어쓰기·콜론·소수점 자리까지 보세요.') + '</small>' +
      (all && qNo < S.problems.length ? '<button class="tool" type="button" id="g-next">다음 문제 →</button>' : '') + '</div>';
    gradeBox.innerHTML = sum + body;
    gradeCnt.textContent = passed + '/' + total;
    gradeCnt.className = 'cnt ' + (all ? 'ok' : 'bad');
    var gn = document.getElementById('g-next');
    if (gn) gn.onclick = function () { go(qNo + 1); };
  }
  btnSubmit.onclick = submitClick;
})();
