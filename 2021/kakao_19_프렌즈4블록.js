function solution(m, n, board) {
  const turn = () => {
    let deletedCnt = 0;

    let deleted = Array(m * n);
    deleted.fill(false);
    board.forEach((row, rowIdx) => {
      if (rowIdx < board.length - 1) {
        row.split("").forEach((colItem, colIdx) => {
          if (colIdx < row.length - 1 && colItem !== "-") {
            if (
              colItem === row[colIdx + 1] &&
              colItem === board[rowIdx + 1][colIdx] &&
              colItem === board[rowIdx + 1][colIdx + 1]
            ) {
              if (deleted[rowIdx * n + colIdx] === false) {
                deleted[rowIdx * n + colIdx] = true;
                deletedCnt++;
              }
              if (deleted[(rowIdx + 1) * n + colIdx] === false) {
                deleted[(rowIdx + 1) * n + colIdx] = true;
                deletedCnt++;
              }
              if (deleted[rowIdx * n + (colIdx + 1)] === false) {
                deleted[rowIdx * n + (colIdx + 1)] = true;
                deletedCnt++;
              }
              if (deleted[(rowIdx + 1) * n + (colIdx + 1)] === false) {
                deleted[(rowIdx + 1) * n + (colIdx + 1)] = true;
                deletedCnt++;
              }
            }
          }
        });
      }
    });
    deleted.forEach((item, index) => {
      if (item === true) {
        const r = Math.floor(index / n);
        const c = index % n;
        let strArr = board[r].split("");
        strArr[c] = "-";
        board[r] = strArr.join("");
      }
    });

    for (let i = m - 1; i > 0; i--) {
      for (let j = n - 1; j >= 0; j--) {
        if (board[i][j] === "-") {
          for (let k = i - 1; k >= 0; k--) {
            if (board[k][j] !== "-") {
              let iStrArr = board[i].split("");
              let kStrArr = board[k].split("");
              iStrArr[j] = board[k][j];
              kStrArr[j] = "-";
              board[i] = iStrArr.join("");
              board[k] = kStrArr.join("");
              break;
            }
          }
        }
      }
    }

    return deletedCnt;
  };

  let delAcc = 0;
  let dels = -1;

  while (dels !== 0) {
    dels = 0;
    const rst = turn();

    if (rst > 0) dels += rst;
    delAcc += rst;
  }

  return delAcc;
}
