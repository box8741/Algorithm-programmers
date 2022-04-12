function solution(s) {
  let answer = s;
  const arr = [
    "zero",
    "one",
    "two",
    "three",
    "four",
    "five",
    "six",
    "seven",
    "eight",
    "nine",
  ];
  for (const [index, value] of arr.entries())
    answer = answer.replace(new RegExp(value, "gi"), String(index));
  return Number(answer);
}

(function () {
  const s = "one4seveneight";
  const sol = solution(s);
  console.log(sol);
})();
