function solution(files) {
  const f1 = (file, index) => {
    //   const HEAD = file.match(/^[^0-9|\s|\.]+/)[0];
    const NUMBER = file.match(/[0-9]{1,5}/)[0];
    const TAIL = file.split(NUMBER).slice(1).join(NUMBER);
    const HEAD = file.split(NUMBER)[0];
    return { HEAD, NUMBER, TAIL, INDEX: index };
  };

  const f2 = (a, b) => {
    return a.HEAD.toLowerCase() === b.HEAD.toLowerCase()
      ? parseInt(a.NUMBER) === parseInt(b.NUMBER)
        ? a.INDEX - b.INDEX
        : parseInt(a.NUMBER) - parseInt(b.NUMBER)
      : a.HEAD.toLowerCase() < b.HEAD.toLowerCase()
      ? -1
      : 1;
  };

  const f3 = (file) => [file.HEAD, file.NUMBER, file.TAIL].join("");

  const parsed = files.map(f1).sort(f2);
  const answer = parsed.map(f3);
  return answer;
}

console.log(
  solution([
    "F-5 Freedom Fighter",
    "B-50 Superfortress",
    "A-10 Thunderbolt II",
    "F-14 Tomcat",
  ])
);
