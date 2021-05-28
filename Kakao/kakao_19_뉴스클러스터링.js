function solution(str1, str2) {
  const regex = /[a-zA-Z]{2}/;

  const isElem = (s, index, str) => {
    if (index < str.length - 1) {
      const elem = [s, str[index + 1]].join("");
      if (elem.match(regex) !== null) return elem.toUpperCase();
    }
    return null;
  };

  const getArr = (str) =>
    str
      .split("")
      .map(isElem)
      .filter((elem) => elem !== null)
      .sort();

  const arr1 = getArr(str1);
  console.log(arr1);
  const arr2 = getArr(str2);
  console.log(arr2);

  let i1 = 0;
  let i2 = 0;
  let k = 0;
  let h = 0;

  while (i1 < arr1.length && i2 < arr2.length) {
    if (arr1[i1] === arr2[i2]) {
      i1++;
      i2++;
      k++;
    } else if (arr1[i1] < arr2[i2]) i1++;
    else i2++;
    h++;
  }
  if (i1 !== arr1.length) h += arr1.length - i1;
  if (i2 !== arr2.length) h += arr2.length - i2;

  let answer;
  if (k > 0 && h > 0) answer = Math.floor((k / h) * 65536);
  else if (k === 0 && h === 0) answer = 65536;
  else answer = 0;
  return answer;
}

solution("FRANCE", "french");
