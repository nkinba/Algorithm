function solution(cacheSize, cities) {
  let execTime = 0;
  let cache = [];
    for(auto i : cities ){

    }
  cities.forEach((city) => {
    city = city.toLowerCase();
    const cityIdxInCache = cache.indexOf(city);
    if (cityIdxInCache === -1) { // miss
      execTime += 5;
      cache.length < cacheSize
        ? cache.unshift(city)
        : cache.pop() && cache.unshift(city);  
    } else {  // hit
      execTime += 1;
      cache.splice(cityIdxInCache, 1);
      cache.unshift(city);
    }
  });

  return execTime;
}

console.log(
  solution(5, [
    "Jeju",
    "Pangyo",
    "Seoul",
    "NewYork",
    "LA",
    "SanFrancisco",
    "Seoul",
    "Rome",
    "Paris",
    "Jeju",
    "NewYork",
    "Rome",
  ])
);
