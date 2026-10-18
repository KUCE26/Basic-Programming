/* 대시보드: 세트 카드 5장 + 진행률 */
(function () {
  var D = window.BP_PROBLEMS;
  var box = document.getElementById('sets');
  if (!D || !box || !window.BP) return;
  var esc = BP.escapeHtml;
  var LEVEL = { 1: '1', 2: '2', 3: '3', 4: '4', 5: '4', 6: '2' };   // 카드 테두리 색: A 청록 · B 금 · C 주황 · D·E 크림슨 · 과제 금

  function render() {
    var progress = BP.loadProgress();
    var h = '';
    D.sets.forEach(function (set) {
      var st = BP.setStats(set, progress);
      var first = 1;
      for (var i = 0; i < set.problems.length; i++) {
        var r = progress[set.problems[i].id];
        if (!r || r.passed !== r.total) { first = i + 1; break; }
        if (i === set.problems.length - 1) first = 1;
      }
      var qs = set.problems.map(function (q) {
        var r = progress[q.id], cls = !r ? '' : (r.passed === r.total ? 'ok' : 'retry');
        return '<i class="' + cls + '" title="' + esc(q.no + '. ' + q.title) + '">' + q.no + '</i>';
      }).join('');
      h += '<a class="setcard" data-level="' + LEVEL[set.n] + '" href="practice.html?set=' + set.n + '&q=' + first + '">' +
        '<div class="sc-h"><span class="pno">' + esc(set.label) + '</span><h3>' + esc(set.title) + '</h3></div>' +
        '<p>' + esc(set.sub) + '</p>' +
        '<div class="sc-q">' + qs + '</div>' +
        '<span class="sc-bar"><i class="ok" style="width:' + (st.pass / st.total * 100) + '%"></i><i class="retry" style="width:' + ((st.tried - st.pass) / st.total * 100) + '%"></i></span>' +
        '<div class="sc-foot"><span>통과 <b>' + st.pass + '</b> / ' + st.total + (set.n === 6 ? '' : ' · <b>' + (st.pass * 10) + '</b>점') + '</span><span>' + (st.tried ? (st.pass === st.total ? '완료 ✓' : first + '번부터 이어서 →') : '시작하기 →') + '</span></div>' +
        '</a>';
    });
    box.innerHTML = h;
  }
  render();

  document.getElementById('slots').innerHTML = D.slots.map(function (s, i) { return '<li><b>' + (i + 1) + '</b>' + esc(s) + '</li>'; }).join('');

  var reset = document.getElementById('reset');
  reset.onclick = function () {
    if (reset.classList.contains('armed')) { BP.resetAll(); render(); reset.classList.remove('armed'); reset.textContent = '기록 초기화'; }
    else { reset.classList.add('armed'); reset.textContent = '정말 지울까요? 한 번 더 누르세요'; setTimeout(function () { reset.classList.remove('armed'); reset.textContent = '기록 초기화'; }, 3000); }
  };
})();
