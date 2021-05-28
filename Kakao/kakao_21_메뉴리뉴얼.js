let foodMap = new Map();

const setMenu = (foods, cur, menu) => {
  menu = menu.split("").sort().join("");
  if (cur === foods.length) {
    if (menu !== "") {
      const menuNum = foodMap.get(menu);
      menuNum !== undefined
        ? foodMap.set(menu, menuNum + 1)
        : foodMap.set(menu, 1);
    }
    return;
  }

  setMenu(foods, cur + 1, menu + foods[cur]);
  setMenu(foods, cur + 1, menu);
  return;
};

function solution(orders, course) {
  orders.forEach((order) => {
    const foods = order.split("");
    setMenu(foods, 0, "");
  });

  let selection = Array.from(Array(21), () => []);
  let answer = [];

  foodMap.forEach((val, key) => {
    selection[key.length].push([val, key]);
  });
  selection.forEach((sel) => sel.sort((a, b) => b[0] - a[0]));
  course.forEach((num) => {
    if (selection[num].length > 0 && selection[num][0][0] >= 2) {
      for (let i = 0; i < selection[num].length; i++) {
        answer.push(selection[num][i][1]);
        if (
          i < selection[num].length - 1 &&
          selection[num][i][0] > selection[num][i + 1][0]
        ) {
          break;
        }
      }
    }
  });
  answer.sort();
  foodMap.clear();

  return answer;
}

[
  [
    ["ABCDE", "AB", "CD", "ADE", "XYZ", "XYZ", "ACD"],
    [2, 3, 5],
  ],
  [
    ["ABCFG", "AC", "CDE", "ACDE", "BCFG", "ACDEH"],
    [2, 3, 4],
  ],
  [
    ["XYZ", "XWY", "WXA"],
    [2, 3, 4],
  ],
].forEach((t) => console.log(solution(...t)));
