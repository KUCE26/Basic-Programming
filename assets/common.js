/* 공통: 풀이 기록·작성 중인 코드 저장 (이 브라우저의 localStorage 에만 저장, 어디로도 보내지 않아요) */
(function () {
  var PKEY = 'bp.progress.v1';   // { s1q1: {passed, total, at} }
  var CKEY = 'bp.code.v1';       // { s1q1: "코드" }
  var mem = { p: {}, c: {} };

  function read(key, slot) {
    try {
      var raw = window.localStorage.getItem(key);
      return raw ? JSON.parse(raw) || {} : mem[slot];
    } catch (e) { return mem[slot]; }
  }
  function write(key, slot, obj) {
    mem[slot] = obj;
    try { window.localStorage.setItem(key, JSON.stringify(obj)); } catch (e) { /* 저장 못 해도 화면은 그대로 */ }
  }

  function escapeHtml(s) {
    return String(s).replace(/[&<>"']/g, function (c) {
      return { '&': '&amp;', '<': '&lt;', '>': '&gt;', '"': '&quot;', "'": '&#39;' }[c];
    });
  }

  window.BP = {
    loadProgress: function () { return read(PKEY, 'p'); },
    saveProgress: function (p) { write(PKEY, 'p', p); },
    loadCode: function () { return read(CKEY, 'c'); },
    saveCode: function (c) { write(CKEY, 'c', c); },
    resetAll: function () {
      write(PKEY, 'p', {}); write(CKEY, 'c', {});
      try { window.localStorage.removeItem(PKEY); window.localStorage.removeItem(CKEY); } catch (e) { /* 무시 */ }
    },
    escapeHtml: escapeHtml,
    /* 세트별 통과 문제 수 */
    setStats: function (set, progress) {
      var pass = 0, tried = 0;
      set.problems.forEach(function (q) {
        var r = progress[q.id];
        if (!r) return;
        tried++;
        if (r.passed === r.total) pass++;
      });
      return { pass: pass, tried: tried, total: set.problems.length };
    }
  };
})();
