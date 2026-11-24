/* 공통: 풀이 기록·작성 중인 코드 저장 (이 브라우저의 localStorage 에만 저장, 어디로도 보내지 않아요) */
(function () {
  var PKEY = 'bp.progress.v1';   // { s1q1: {passed, total, at} }
  var CKEY = 'bp.code.v1';       // { s1q1: "코드" }
  var mem = { p: {}, c: {} };

  function read(key, slot) {
    try {
      var raw = window.localStorage.getItem(key);
      var obj = raw ? JSON.parse(raw) || {} : mem[slot];
      if (raw && migrate(obj)) window.localStorage.setItem(key, JSON.stringify(obj));
      return obj;
    } catch (e) { return mem[slot]; }
  }
  /* 2026-11-24: C4~C9 세트(set13~15·17~19)를 C1~C3(set9~11)로 합치면서 바뀐 문제 id. 예전 기록·코드를 새 id 로 옮긴다 */
  var MOVED = {"s13q1": "s9q29", "s13q2": "s9q30", "s13q3": "s9q31", "s13q4": "s9q32", "s13q5": "s9q33", "s13q6": "s9q34", "s13q7": "s9q35", "s13q8": "s9q36", "s13q9": "s9q37", "s13q10": "s9q38", "s13q11": "s9q39", "s13q12": "s9q40", "s17q1": "s9q41", "s17q2": "s9q42", "s17q3": "s9q43", "s17q4": "s9q44", "s17q5": "s9q45", "s17q6": "s9q46", "s17q7": "s9q47", "s17q8": "s9q48", "s14q1": "s10q29", "s14q2": "s10q30", "s14q3": "s10q31", "s14q4": "s10q32", "s14q5": "s10q33", "s14q6": "s10q34", "s14q7": "s10q35", "s14q8": "s10q36", "s14q9": "s10q37", "s14q10": "s10q38", "s14q11": "s10q39", "s14q12": "s10q40", "s18q1": "s10q41", "s18q2": "s10q42", "s18q3": "s10q43", "s18q4": "s10q44", "s18q5": "s10q45", "s18q6": "s10q46", "s18q7": "s10q47", "s18q8": "s10q48", "s15q1": "s11q17", "s15q2": "s11q18", "s15q3": "s11q19", "s15q4": "s11q20", "s15q5": "s11q21", "s15q6": "s11q22", "s19q1": "s11q23", "s19q2": "s11q24", "s19q3": "s11q25", "s19q4": "s11q26"};
  function migrate(obj) {
    var changed = false;
    Object.keys(MOVED).forEach(function (o) {
      if (obj[o] != null) { if (obj[MOVED[o]] == null) obj[MOVED[o]] = obj[o]; delete obj[o]; changed = true; }
    });
    return changed;
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
