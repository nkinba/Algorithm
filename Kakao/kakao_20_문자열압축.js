function sol(s) {
  let longestDup = Array(s.length);
  longestDup.fill(0);
  s.split("").forEach((e, index) => {
    if (index > 0) {
      let dupLen = 0;
      let dupCnt;
      let sliceCnt;
      let sliceLen;
      for (sliceLen = 1; sliceLen <= (index + 1) / 2; sliceLen++) {
        sliceCnt = 1;
        while (index - sliceLen * (sliceCnt + 1) + 1 >= 0) {
          const r = s.substring(
            index - sliceLen * sliceCnt + 1,
            index * (sliceCnt - 1) + 1
          );
          const l = s.substring(
            index - sliceLen * (sliceCnt + 1) + 1,
            index - sliceLen * sliceCnt + 1
          );
          if (r == l) {
            sliceCnt++;
          } else break;
        }

        if (sliceLen > dupLen) {
          dupLen = sliceLen;
          dupCnt = sliceCnt;
        }
      }
      longestDup[index] = [dupLen, dupCnt];
    }
  });
  console.log(longestDup);
}
aabbaccc;
12121123;
console.log(
  [
    "aabbaccc",
    "ababcdcdababcdcd",
    "abcabcdede",
    "abcabcabcabcdededededede",
    "xababcdcdababcdcd",
  ].map((e) => sol(e))
);
