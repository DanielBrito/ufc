const { Graph } = require("./Models/Graph");

/* - - - DECLARATIONS - - - */

const vertices = ["A", "B", "C", "D", "E", "F", "G", "H", "I"];
const edges = [
  ["A", "B"],
  ["A", "C"],
  ["A", "D"],
  ["C", "D"],
  ["C", "G"],
  ["D", "G"],
  ["D", "H"],
  ["B", "E"],
  ["B", "F"],
  ["E", "I"],
];

const callbackFunction = (vertex) => console.log("Visited vertex: " + vertex);

/* - - - GRAPH - - - */

const graph = new Graph();

vertices.forEach((vertex) => graph.addVertex(vertex));

edges.forEach((edge) => graph.addEdge(edge[0], edge[1]));

console.log("GRAPH:");

console.log(graph.toString());

/* - - - DIGRAPH - - - */

const digraph = new Graph(true);

vertices.forEach((vertex) => digraph.addVertex(vertex));

edges.forEach((edge) => digraph.addEdge(edge[0], edge[1]));

console.log("DIGRAPH:");

console.log(digraph.toString());

/* - - - GRAPH BFS - - - */

console.log("GRAPH BFS:");

graph.BFS(vertices[0], callbackFunction);

/* - - - DIGRAPH BFS - - - */

console.log("\nDIGRAPH BFS:");

digraph.BFS(vertices[0], callbackFunction);

/* - - - GRAPH DFS - - - */

console.log("\nGRAPH DFS:");

graph.DFS(callbackFunction);

/* - - - DIGRAPH BFS - - - */

console.log("\nDIGRAPH DFS:");

digraph.DFS(callbackFunction);

/* - - - CONNECTIVITY - - - */

const graphConnectivity = new Graph();

vertices.forEach((vertex) => graphConnectivity.addVertex(vertex));

// Removing [A, B] edge turns it into a disconnected graph:
edges.forEach((edge) => graphConnectivity.addEdge(edge[0], edge[1]));

console.log("\nIS CONNECTED:");
console.log(graphConnectivity.isConnected());

/* - - - STRONG CONNECTIVITY - - - */

// TODO
