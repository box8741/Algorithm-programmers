function solution(new_id) {
  let answer = new_id;
  answer = answer.toLowerCase();
  answer = answer.replace(new RegExp(/[^a-z0-9-_.]/, "g"), "");
  answer = answer.replace(new RegExp(/[.]{2,}/, "g"), ".");
  answer = answer.replace(new RegExp(/^[.]|[.]$/, "g"), "");
  if (answer.length <= 0) answer = "a";
  if (answer.length >= 16)
    answer = answer.slice(0, 15).replace(new RegExp(/[.]$/, "g"), "");
  while (answer.length <= 2) answer += answer[answer.length - 1];

  return answer;
}

(function () {
  const new_id = "abcdefghijklmn.p";
  const sol = solution(new_id);
  console.log(sol);
})();
