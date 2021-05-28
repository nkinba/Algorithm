const rotate = (block) => {
  const len = block.length;
  let newBlock = Array.from(Array(len), () => []);

  block.reverse().forEach((line) => {
    line.forEach((e, index) => newBlock[index].push(e));
  });
  return newBlock;
};

function solution(key, lock) {
  const K = key.length;
  const L = lock.length;
  const answer = parseInt(Array.from(Array(L), () => "1").join(""), 2);
  const W = L + 2 * (K - 1);

  let whole = Array.from(Array(W), () => Array(W));
  const LB = K - 1;
  const LE = L + K - 2;

  lock.forEach((line, Lindex) =>
    line.forEach((e, Eindex) => (whole[Lindex + K - 1][Eindex + K - 1] = e))
  );

  for (let rot = 0; rot < 4; rot++) {
    for (let row = 0; row < W - K + 1; row++) {
      const KRB = row;
      const KRE = row + (K - 1);

      for (let col = 0; col < W - K + 1; col++) {
        const KCB = col;
        const KCE = col + (K - 1);

        let lockRow;
        for (lockRow = LB; lockRow <= LE; lockRow++) {
          const lockPart = lock[lockRow - LB];
          const keyPart =
            KRB <= lockRow && lockRow <= KRE
              ? Array.of(...key[lockRow - KRB])
              : ["0"];

          if (KCE < LE) {
            for (let i = 0; i < LE - KCE; i++) keyPart.push("0");
          } else {
            for (let i = 0; i < KCE - LE; i++) keyPart.pop();
          }
          if (KCB < LB) {
            for (let i = 0; i < LB - KCB; i++) keyPart.shift();
          }

          const lockBit = parseInt(lockPart.join(""), 2);
          const keyBit = parseInt(keyPart.join(""), 2);

          if ((lockBit ^ keyBit) !== answer) break;
        }
        if (lockRow > LE) return true;
      }
    }

    key = rotate(key);
  }

  return false;
}

console.log(
  solution(
    [
      [0, 0, 0],
      [1, 0, 0],
      [0, 1, 1],
    ],
    [
      [1, 1, 1],
      [1, 1, 0],
      [1, 0, 1],
    ]
  )
);
