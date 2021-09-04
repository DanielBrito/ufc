const { Queue } = require("./Queue");

/* ALGORITHMS: */

const bfs = (s, t) => {
  parents.fill(-1);
  currentPathCapacity.fill(0);

  let q = new Queue();

  q.enqueue(s);

  parents[s] = -2;
  currentPathCapacity[s] = Number.MAX_SAFE_INTEGER;

  while (!q.isEmpty()) {
    let currentNode = q.dequeue();

    for (let i = 0; i < graph[currentNode].length; i++) {
      let to = graph[currentNode][i];

      if (parents[to] === -1) {
        if (capacities[currentNode][to] - flowPassed[currentNode][to] > 0) {
          parents[to] = currentNode;

          currentPathCapacity[to] = Math.min(
            currentPathCapacity[currentNode],
            capacities[currentNode][to] - flowPassed[currentNode][to]
          );

          if (to === t) {
            return currentPathCapacity[t];
          }

          q.enqueue(to);
        }
      }
    }
  }

  return 0;
};

const maxFlow = (s, t) => {
  let maxFlow = 0;
  let flow;

  while ((flow = bfs(s, t))) {
    maxFlow += flow;

    let currentNode = t;

    while (currentNode !== s) {
      let previousNode = parents[currentNode];

      flowPassed[previousNode][currentNode] += flow;
      flowPassed[currentNode][previousNode] -= flow;
      currentNode = previousNode;
    }
  }

  return maxFlow;
};

/* INITIALIZATION: */

let nodes = 6;

let graph = [[1, 4], [2, 3], [5], [2, 5], [1, 3]];

let capacities = Array.from(Array(nodes).fill(0), () =>
  new Array(nodes).fill(0)
);

capacities[0][1] = 7;
capacities[0][4] = 4;
capacities[1][2] = 5;
capacities[1][3] = 3;
capacities[2][5] = 8;
capacities[3][2] = 3;
capacities[3][5] = 5;
capacities[4][1] = 3;
capacities[4][3] = 2;

let flowPassed = Array.from(Array(nodes).fill(0), () =>
  new Array(nodes).fill(0)
);

let parents = new Array(nodes);
let currentPathCapacity = new Array(nodes);

let s = 0;
let t = 5;

let result = maxFlow(s, t);

console.log("Max flow: ", result);
