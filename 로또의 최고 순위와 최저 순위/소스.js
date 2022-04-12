function solution(lottos, win_nums) {
  let minSum = 0;
  const rank = [6, 6, 5, 4, 3, 2, 1];
  const zeroNums = lottos.filter((_) => !_).length;
  for (const win of win_nums)
    for (const lot of lottos) if (win === lot && lot !== 0) minSum++;
  return [rank[minSum + zeroNums], rank[minSum]];
}

(function () {
  const lottos = [0, 0, 0, 0, 0, 0];
  const win_nums = [38, 19, 20, 40, 15, 25];
  const sol = solution(lottos, win_nums);
  console.log(sol);
})();
