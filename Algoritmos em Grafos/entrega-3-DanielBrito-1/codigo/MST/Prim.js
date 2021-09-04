const { PriorityQueue } = require("../Models/PriorityQueue");
const INF = Number.MAX_SAFE_INTEGER;

function prim(graph, weights) {
  let adjacencyMatrix = getAdjacencyMatrix(graph, weights);
  const parent = [];
  const key = [];
  const visited = [];
  const { length } = graph;

  let mst = [];
  let cost = 0;

  for (let i = 0; i < length; i++) {
    key[i] = INF;
    visited[i] = false;
  }

  key[0] = 0;
  parent[0] = -1;

  let queue = new PriorityQueue();

  graph.forEach((edge, index) => queue.enqueue(edge, weights[index]));

  while (!queue.isEmpty()) {
    const element = queue.dequeue();
    const u = Math.min(element.value[0], element.value[1]);

    visited[u] = true;

    for (let v = 0; v < length; v++) {
      if (
        adjacencyMatrix[u][v] &&
        !visited[v] &&
        adjacencyMatrix[u][v] < key[v]
      ) {
        cost += adjacencyMatrix[u][v];
        mst.push(u + " - " + v);

        parent[v] = u;
        key[v] = adjacencyMatrix[u][v];
      }
    }
  }

  return { mst, cost };
}

function getAdjacencyMatrix(graph, weights) {
  let { length } = graph;
  const matrix = new Array(length - 1)
    .fill(0)
    .map(() => new Array(length - 1).fill(0));

  graph.forEach((edge, index) => {
    matrix[edge[0]][edge[1]] = weights[index];
    matrix[edge[1]][edge[0]] = weights[index];
  });

  return matrix;
}

module.exports = { prim };
