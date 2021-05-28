function solution(m, musicinfos) {
  const findNoteRegex = /[A-G][#]*/g;

  m = m
    .match(findNoteRegex)
    .map((note) => (note.length > 1 ? note[0].toLowerCase() : note))
    .join("");

  const musicArr = musicinfos.map((info, inserted) => {
    const infoArr = info.split(",");
    const endTime = infoArr[1].split(":");
    const startTime = infoArr[0].split(":");
    const playingTime =
      (endTime[0] - startTime[0]) * 60 + (endTime[1] - startTime[1]);

    return {
      inserted,
      playingTime,
      title: infoArr[2],
      note: infoArr[3],
    };
  });

  let satisfying = musicArr.filter((music) => {
    music.note = music.note.match(findNoteRegex);

    const playingCount = Math.floor(music.playingTime / music.note.length);
    const playingRest = music.playingTime % music.note.length;

    let realNotes = [];
    for (let i = 0; i < playingCount; i++) realNotes.push(...music.note);
    realNotes.push(...music.note.slice(0, playingRest));

    realNotes = realNotes
      .map((note) => (note.length > 1 ? note[0].toLowerCase() : note))
      .join("");

    return realNotes.indexOf(m) !== -1;
  });

  satisfying.sort((a, b) => {
    const rst =
      a.playingTime === b.playingTime
        ? a.inserted - b.inserted
        : b.playingTime - a.playingTime;
    return rst;
  });

  return satisfying.length === 0 ? "(None)" : satisfying[0].title;
}

console.log(
  solution("CC#BCC#BCC#BCC#B", [
    ("03:00,03:30,FOO,CC#B", "04:00,04:08,BAR,CC#BCC#BCC#B"),
  ])
);
