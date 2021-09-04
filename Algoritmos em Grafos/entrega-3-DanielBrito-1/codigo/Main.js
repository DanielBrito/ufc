const { kruskal } = require("./MST/Kruskal");
const { prim } = require("./MST/Prim");

const graph = [
  [0, 1],
  [0, 4],
  [1, 4],
  [1, 3],
  [3, 2],
  [4, 2],
];
const weights = [5, 100, 20, 70, 9, 17];

console.log("KRUSKAL: ");

const resultKruskal = kruskal(graph, weights);

console.log("MST = " + resultKruskal.mst);
console.log("Cost = " + resultKruskal.cost);

console.log("\nPRIM: ");

const resultPrim = prim(graph, weights);

console.log("MST = " + resultPrim.mst);
console.log("Cost = " + resultPrim.cost);
