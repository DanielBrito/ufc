const { DisjointSet } = require("../Models/DisjointSet");

function kruskal(graph, weights) {
  let mst = [];

  graph.sort(function (a, b) {
    return weights[graph.indexOf(a)] - weights[graph.indexOf(b)];
  });

  weights.sort(function (a, b) {
    return a - b;
  });

  let cost = 0;

  let set = new DisjointSet();

  for (let i = 0; i < weights.length; i++) {
    if (set.find(graph[i][0]) !== set.find(graph[i][1])) {
      set.union(graph[i][0], graph[i][1]);

      cost += weights[i];
      mst.push(graph[i][0] + " - " + graph[i][1]);
    }
  }

  return { mst, cost };
}

module.exports = { kruskal };
