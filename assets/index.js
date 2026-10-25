/* 대시보드: 트랙(중간고사 · 기말고사 · 코딩테스트) 선택 → 그 트랙의 세트 카드 + 안내 */
(function () {
  var D = window.BP_PROBLEMS;
  var box = document.getElementById('sets');
  if (!D || !box || !window.BP) return;
  var esc = BP.escapeHtml;
  var TKEY = 'bp.track.v1';
  var MID_LEVEL = { 1: '1', 2: '2', 3: '3', 4: '4', 5: '4', 6: '2', 7: '2', 8: '0' };   // 중간 세트 카드 색: A 청록 · B 금 · C 주황 · D·E 크림슨 · 과제·연습 금 · 범위 밖 회색

  /* ── 트랙별 소개 ── */
  var TRACKS = {
    mid: {
      eyebrow: 'PYTHON · MIDTERM', h1: '중간고사 모의테스트', level: '4',
      lead: '엘리스 실습과 같은 형식이에요. 왼쪽 지시사항을 읽고 오른쪽 편집기에 코드를 쓴 뒤 <b>실행</b>으로 확인하고 <b>제출</b>하면 숨겨진 테스트케이스로 바로 채점돼요. 세트마다 10문제, 문제당 10점.',
      facts: ['<b>5</b>세트 <b>50</b>문제 + 엘리스 과제·연습 <b>25</b>문제', '범위 엘리스 <b>2 – 8차시</b>', '난이도 4·8차시 과제 수준', 'import · try · class 없이', '브라우저에서 바로 실행'],
      howto: '<div class="card"><h3>세트마다 같은 10슬롯</h3><p>시험에서 어떤 유형이 나와도 한 번씩은 풀어 본 상태가 되도록, A–E 다섯 세트 모두 아래 순서로 짰어요. <b>과제</b> 세트는 교수님이 시험 난이도의 기준이라고 한 엘리스 4차시·8차시 과제 15문제 원본, <b>연습</b> 세트는 12차시 종합 연습 문제 중 시험 범위 안 10문제예요. <b>범위밖</b>(11차시 과제 등 모듈·클래스·정규식 8문제)은 중간고사엔 안 나오니 시간이 남을 때만 보세요.</p><ul class="slotlist">' +
        D.slots.map(function (s, i) { return '<li><b>' + (i + 1) + '</b>' + esc(s) + '</li>'; }).join('') + '</ul></div>' +
        '<div class="card" style="margin-top:14px"><h3>이렇게 쓰세요</h3><ol><li>시험처럼 풀려면 세트 하나를 골라 1번부터 10번까지 <b>정답 보기 없이</b> 끝까지 제출하고 점수를 확인하세요.</li><li>틀린 문제는 <b>채점 결과</b>의 빨간 줄(기대 출력과 다른 줄)을 보고 고친 뒤 다시 제출하세요. 띄어쓰기·콜론·소수점 자릿수가 가장 흔한 실수예요.</li><li>막히면 <b>입력</b> 탭에 입력 예시를 넣고 <b>실행</b>으로 중간 값을 <code>print()</code>해 보세요. 끝나지 않는 반복문은 5초 뒤 자동으로 멈춰요.</li><li>편집기에서 <code>Ctrl+Enter</code>(Mac은 <code>⌘+Enter</code>)는 실행, <code>Ctrl+Shift+Enter</code>는 제출이에요.</li></ol></div>',
      foot: '엘리스 「기초 프로그래밍」 2~8차시 실습·과제와 엘리스 아카데미 「Do it! 첫 파이썬」의 문제 유형을 바탕으로 새로 만든 문제예요. Python은 브라우저 안에서 실행돼요(Pyodide).'
    },
    final: {
      eyebrow: 'C · FINAL EXAM', h1: '기말고사 대비 (C)', level: '3',
      lead: '엘리스 13차시부터는 C언어예요. 같은 실습 형식으로 <b>Lv1 기본 → Lv2 응용 → Lv3 심화</b> 순서로 풀면, 실습 그대로 수준부터 과제보다 어려운 변별 문제까지 한 번씩 거치게 돼요. 코드는 실행 버튼을 누를 때 Compiler Explorer(godbolt.org)로 보내 gcc로 컴파일해요.',
      facts: ['범위 엘리스 <b>13 · 14차시</b> (매주 화요일 새 차시 추가 예정)', '<b>Lv1</b> 실습 수준 · <b>Lv2</b> 과제 수준 · <b>Lv3</b> 과제 이상', 'gcc <b>-std=c11</b> 로 실행', 'if · for · 배열 · 포인터는 아직 안 씀'],
      howto: '<div class="card"><h3>지금 범위에서 시험이 어렵게 나온다면 여기서 나와요</h3><p>13·14차시엔 조건문도 반복문도 없어요. 그래서 출제자가 난이도를 올릴 수 있는 곳은 정해져 있고, Lv2·Lv3 는 그 지점만 모았어요.</p><ul class="slotlist"><li><b>1</b>printf 폭·정밀도 (<code>%-10s</code> <code>%08.2f</code>)</li><li><b>2</b>scanf 형식 문자열로 파싱 (<code>"%d-%d"</code>)</li><li><b>3</b>정수 나눗셈 vs (double) 캐스팅</li><li><b>4</b>char 산술과 아스키 코드</li><li><b>5</b>int 오버플로 · long long</li><li><b>6</b>fgets 길이 제한과 개행</li><li><b>7</b>이스케이프 시퀀스</li><li><b>8</b>%o %x %X 진법 출력</li></ul></div>' +
        '<div class="card" style="margin-top:14px"><h3>이렇게 쓰세요</h3><ol><li><b>수요일</b>엔 그 주 엘리스 실습을 자료 안 보고 풀고, <b>월요일</b>엔 여기서 같은 범위의 Lv2·Lv3 를 풀어요. Lv1 은 막히는 개념이 있을 때만.</li><li>C 는 Python 과 달리 <b>컴파일 오류</b>가 먼저 나와요. 채점 결과의 오류 메시지에서 <code>main.c:줄번호</code> 를 보고 고치세요. 세미콜론·<code>&amp;</code>·형식 지정자 불일치가 대부분이에요.</li><li>출력이 한 칸이라도 다르면 틀려요. <b>채점 결과</b>의 빨간 줄과 기대 출력을 글자 단위로 비교하세요.</li><li>새 차시가 올라오면 그 범위의 문제가 Lv1·2·3 에 추가돼요. 포인터·배열이 나오는 주부터는 세트가 더 생길 거예요.</li></ol></div>',
      foot: '엘리스 「기초 프로그래밍」 13·14차시 실습을 바탕으로 새로 만든 변형 문제예요. C 코드는 실행할 때만 godbolt.org 로 보내 컴파일해요 (gcc, -std=c11).'
    },
    ct: {
      eyebrow: 'C++ · SAMSUNG SW TEST', h1: '코딩테스트 준비 (C++)', level: '1',
      lead: '겨울에 시작할 삼성 SW역량테스트 A형 준비. 먼저 <b>C++ 워밍업</b> 세트로 cin/cout·string·vector·sort·map·stack·queue 와 격자 BFS 뼈대를 손에 익히고, 그다음 방학특강 때 Python 으로 풀었던 <b>SWEA 문제를 C++ 로 다시</b> 풀어요. 문제를 이미 알아서 언어 차이에만 집중할 수 있어요.',
      facts: ['A형 = <b>완전탐색 · 시뮬레이션 · BFS/DFS · 백트래킹</b>', 'STL 사용 가능 (B형과 다름)', 'g++ <b>-std=c++17 -O2</b> 로 실행', '기말 끝난 뒤 시작, 월·수 2시간'],
      howto: '<div class="card"><h3>SWEA 다시 풀기 로드맵 — 방학특강 solving club 36문제를 C++ 로</h3><p>워밍업 세트가 끝나면 아래 순서로 SWEA 에서 다시 풀어요. 번호로 검색하면 나와요. 풀고 나면 체크해 두세요(이 브라우저에만 저장).</p><div id="roadmap"></div></div>' +
        '<div class="card" style="margin-top:14px"><h3>이렇게 쓰세요</h3><ol><li>C 기말이 끝난 주부터 <b>워밍업 8문제</b>를 두 세션 안에 끝내요. C 에서 바뀌는 건 입출력과 STL 뿐이에요.</li><li>SWEA 문제는 <b>코드를 치기 전에 입출력 예시를 손으로 따라가</b> 보세요. 삼성 유형은 조건 하나 놓치면 끝이에요.</li><li>30분 넘게 막히면 풀이를 보고, <b>다음 세션 첫 15분에 다시</b> 풀어요.</li><li>모의 SW 역량테스트 단계(4단계)부터는 SWEA 에서 시간을 재고 푸세요. A형은 보통 3시간에 1~2문제예요.</li></ol></div>',
      foot: 'C++ 워밍업은 새로 만든 문제예요. SWEA 문제 목록은 사용자의 solving club 「26년 차세대통신 SW 방학특강」 기준이고, 문제 본문은 SWEA 에서 풀어요. C++ 코드는 실행할 때만 godbolt.org 로 보내 컴파일해요 (g++, -std=c++17).'
    }
  };

  /* SWEA 방학특강 solving club 문제 (단계별) */
  var ROADMAP = [
    ['1단계 · 배열·문자열·구현 (D2~D3)', [['1204', '최빈수 구하기', 'D2'], ['4836', '색칠하기', 'D2'], ['4873', '반복문자 지우기', 'D2'], ['4881', '배열 최소 합', 'D2'], ['5174', 'subtree', 'D2'], ['1208', 'Flatten', 'D3'], ['1206', 'View', 'D3'], ['1220', 'Magnetic', 'D3'], ['1244', '최대 상금', 'D3']]],
    ['2단계 · 스택·큐·BFS (D3~D4)', [['1218', '괄호 짝짓기', 'D4'], ['1224', '계산기3', 'D4'], ['1210', 'Ladder1', 'D4'], ['1226', '미로1', 'D4'], ['5105', '미로의 거리', 'D3'], ['1238', 'Contact', 'D4'], ['4871', '그래프 경로', 'D2'], ['7465', '창용 마을 무리의 개수', 'D4']]],
    ['3단계 · 트리·그래프·백트래킹 (D3~D6)', [['5178', '노드의 합', 'D3'], ['1248', '공통조상', 'D5'], ['1865', '동철이의 일 분배', 'D4'], ['1861', '정사각형 방', 'D4'], ['1247', '최적 경로', 'D5'], ['1267', '작업순서', 'D6'], ['1251', '하나로', 'D4'], ['1249', '보급로', 'D4']]],
    ['4단계 · 모의 SW 역량테스트 (A형 기출 수준)', [['4008', '숫자 만들기', '모의'], ['1952', '수영장', '모의'], ['4012', '요리사', '모의'], ['2115', '벌꿀채취', '모의'], ['5644', '무선 충전', '모의'], ['2117', '홈 방범 서비스', '모의'], ['4014', '활주로 건설', '모의'], ['1767', '프로세서 연결하기', '샘플'], ['2112', '보호 필름', '모의'], ['1953', '탈주범 검거', '모의']]]
  ];
  var RKEY = 'bp.swea.v1';
  function loadRoad() { try { return JSON.parse(localStorage.getItem(RKEY) || '{}') || {}; } catch (e) { return {}; } }
  function saveRoad(o) { try { localStorage.setItem(RKEY, JSON.stringify(o)); } catch (e) { /* 무시 */ } }

  /* ── 현재 트랙 ── */
  var qs = new URLSearchParams(location.search);
  var track = qs.get('track');
  if (!TRACKS[track]) { try { track = localStorage.getItem(TKEY); } catch (e) { track = null; } }
  if (!TRACKS[track]) track = 'mid';

  function setLevel(set) {
    if ((set.track || 'mid') === 'mid') return MID_LEVEL[set.n] || '4';
    if (set.level) return String(Math.min(set.level, 4));
    return '1';
  }

  function render() {
    var T = TRACKS[track];
    try { localStorage.setItem(TKEY, track); } catch (e) { /* 무시 */ }
    document.body.setAttribute('data-track', track);
    document.title = '기초프로그래밍 · ' + (D.tracks[track] ? D.tracks[track].name : '') + ' 준비';
    var tabs = document.querySelectorAll('#tracks a');
    for (var i = 0; i < tabs.length; i++) {
      var on = tabs[i].getAttribute('data-track') === track;
      if (on) tabs[i].setAttribute('aria-current', 'page'); else tabs[i].removeAttribute('aria-current');
    }
    document.getElementById('eyebrow').textContent = T.eyebrow;
    document.getElementById('h1').textContent = T.h1;
    document.getElementById('lead').innerHTML = T.lead;
    document.getElementById('facts').innerHTML = T.facts.map(function (f) { return '<span>' + f + '</span>'; }).join('');
    document.getElementById('howto').innerHTML = T.howto;
    document.getElementById('foot').innerHTML = T.foot + '<br>기록은 이 브라우저에만 저장돼요.';
    var hero = document.querySelector('.hero'); if (hero) hero.setAttribute('data-level', T.level);

    var progress = BP.loadProgress();
    var h = '';
    D.sets.forEach(function (set) {
      if ((set.track || 'mid') !== track) return;
      var st = BP.setStats(set, progress);
      var first = 1;
      for (var i = 0; i < set.problems.length; i++) {
        var r = progress[set.problems[i].id];
        if (!r || r.passed !== r.total) { first = i + 1; break; }
        if (i === set.problems.length - 1) first = 1;
      }
      var qsx = set.problems.map(function (q) {
        var r = progress[q.id], cls = !r ? '' : (r.passed === r.total ? 'ok' : 'retry');
        return '<i class="' + cls + '" title="' + esc(q.no + '. ' + q.title) + '">' + q.no + '</i>';
      }).join('');
      h += '<a class="setcard' + (set.outside ? ' outside' : '') + '" data-level="' + setLevel(set) + '" href="practice.html?set=' + set.n + '&q=' + first + '">' +
        '<div class="sc-h"><span class="pno">' + esc(set.label) + '</span><h3>' + esc(set.title) + '</h3>' + (set.level ? '<span class="tag lv">Lv' + set.level + '</span>' : '') + '</div>' +
        '<p>' + esc(set.sub) + '</p>' +
        '<div class="sc-q">' + qsx + '</div>' +
        '<span class="sc-bar"><i class="ok" style="width:' + (st.pass / st.total * 100) + '%"></i><i class="retry" style="width:' + ((st.tried - st.pass) / st.total * 100) + '%"></i></span>' +
        '<div class="sc-foot"><span>통과 <b>' + st.pass + '</b> / ' + st.total + (set.scored ? ' · <b>' + (st.pass * 10) + '</b>점' : '') + '</span><span>' + (st.tried ? (st.pass === st.total ? '완료 ✓' : first + '번부터 이어서 →') : '시작하기 →') + '</span></div>' +
        '</a>';
    });
    if (!h) h = '<p class="toolnote">아직 이 트랙에는 세트가 없어요.</p>';
    box.innerHTML = h;
    renderRoadmap();
  }

  function renderRoadmap() {
    var el = document.getElementById('roadmap');
    if (!el) return;
    var done = loadRoad();
    var total = 0, cnt = 0, h = '';
    ROADMAP.forEach(function (stage, si) {
      var items = stage[1];
      var sd = items.filter(function (it) { return done[it[0]]; }).length;
      total += items.length; cnt += sd;
      h += '<details class="stage"' + (si === 0 || sd < items.length && si > 0 && ROADMAP[si - 1][1].every(function (it) { return done[it[0]]; }) ? ' open' : '') + '><summary>' + esc(stage[0]) + '<span class="res">' + sd + '/' + items.length + '</span></summary><ul class="roadlist">' +
        items.map(function (it) {
          return '<li><label><input type="checkbox" data-id="' + it[0] + '"' + (done[it[0]] ? ' checked' : '') + '><span class="num">' + it[0] + '</span><span class="nm">' + esc(it[1]) + '</span><span class="dl">' + esc(it[2]) + '</span></label></li>';
        }).join('') + '</ul></details>';
    });
    el.innerHTML = '<p class="road-sum">C++ 로 다시 푼 문제 <b>' + cnt + '</b> / ' + total + '</p>' + h;
    el.onchange = function (e) {
      var cb = e.target; if (!cb || cb.type !== 'checkbox') return;
      var d = loadRoad();
      if (cb.checked) d[cb.getAttribute('data-id')] = Date.now(); else delete d[cb.getAttribute('data-id')];
      saveRoad(d); renderRoadmap();
    };
  }

  document.getElementById('tracks').onclick = function (e) {
    var a = e.target.closest('a[data-track]'); if (!a) return;
    e.preventDefault();
    track = a.getAttribute('data-track');
    history.replaceState(null, '', 'index.html?track=' + track);
    render();
    window.scrollTo({ top: 0, behavior: 'smooth' });
  };
  render();

  var reset = document.getElementById('reset');
  reset.onclick = function () {
    if (reset.classList.contains('armed')) { BP.resetAll(); try { localStorage.removeItem(RKEY); } catch (e) {} render(); reset.classList.remove('armed'); reset.textContent = '기록 초기화'; }
    else { reset.classList.add('armed'); reset.textContent = '정말 지울까요? 한 번 더 누르세요'; setTimeout(function () { reset.classList.remove('armed'); reset.textContent = '기록 초기화'; }, 3000); }
  };
})();
