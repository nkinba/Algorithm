function solution(n, t, m, p) {
  const chars = "0123456789ABCDEF".substring(0, n).split("");
  let turn = 1;
  let tubeCount = 0;
  let tubeNums = [];
  let currentNum = [0];
  let digitIndex = 0;

  const increaseNum = () => {
    let i = currentNum.length - 1;
    while (i >= 0) {
      if (currentNum[i] === n - 1) {
        currentNum[i] = 0;
        i--;
      } else {
        currentNum[i]++;
        break;
      }
    }
    if (i < 0) currentNum.unshift(1);
    digitIndex = 0;
  };

  while (tubeCount < t) {
    const currentTurn = turn % m === 0 ? m : turn % m;
    if (currentTurn === p) {
      tubeCount++;
      tubeNums.push(chars[currentNum[digitIndex]]);
    }

    digitIndex === currentNum.length - 1 ? increaseNum() : digitIndex++;

    turn++;
  }
  return tubeNums.join("");
}

console.log(solution(16, 16, 2, 1));
