function solution(msg) {
  let alphas = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  let dict = alphas.split("");

  const letters = msg.split("");
  let current;
  const indices = [];

  for (let i = 0; i < letters.length; ) {
    current = letters[i];
    let preIndex;
    let searchIndex = dict.indexOf(current);
    while (searchIndex !== -1) {
      preIndex = searchIndex;
      current += letters[++i];
      searchIndex = dict.indexOf(current);
    }

    indices.push(preIndex + 1);
    dict.push(current);
  }
  return indices;
}

console.log(solution("KAKAO", [11, 1, 27, 15]));
