function solution(participant, completion) {
  participant.sort();
  completion.sort();
  let answer = participant[participant.length - 1];
  for (const [i, v] of completion.entries())
    if (v != participant[i]) {
      answer = participant[i];
      break;
    }
  return answer;
}

(function () {
  const participant = ["mislav", "stanko", "mislav", "ana"];
  const completion = ["stanko", "ana", "mislav"];
  const sol = solution(participant, completion);
  console.log(sol);
})();
