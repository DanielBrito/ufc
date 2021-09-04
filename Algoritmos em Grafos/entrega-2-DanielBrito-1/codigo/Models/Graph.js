const { Dictionary } = require("./Dictionary");
const { Queue } = require("./Queue");

const { initializeColor, Colors } = require("../Utils/Colors");

class Graph {
  constructor(isDirected = false) {
    this.isDirected = isDirected;
    this.vertices = [];
    this.adjacencyList = new Dictionary();
  }

  addVertex(v) {
    if (!this.vertices.includes(v)) {
      this.vertices.push(v);
      this.adjacencyList.set(v, []);
    }
  }

  addEdge(v, w) {
    if (!this.adjacencyList.get(v)) {
      this.addVertex(v);
    }

    if (!this.adjacencyList.get(w)) {
      this.addVertex(w);
    }

    this.adjacencyList.get(v).push(w);

    if (!this.isDirected) {
      this.adjacencyList.get(w).push(v);
    }
  }

  getVertices() {
    return this.vertices;
  }

  getAdjacencyList() {
    return this.adjacencyList;
  }

  toString() {
    let str = "";

    for (let i = 0; i < this.vertices.length; i++) {
      str += `${this.vertices[i]} -> `;

      const neighbors = this.adjacencyList.get(this.vertices[i]);

      for (let j = 0; j < neighbors.length; j++) {
        str += `${neighbors[j]} `;
      }

      str += "\n";
    }

    return str;
  }

  BFS(startVertex, callback) {
    const vertices = this.getVertices();
    const adjacencyList = this.getAdjacencyList();
    const color = initializeColor(vertices);
    const queue = new Queue();

    queue.enqueue(startVertex);

    while (!queue.isEmpty()) {
      const u = queue.dequeue();
      const neighbors = adjacencyList.get(u);

      color[u] = Colors.GREY;

      for (let i = 0; i < neighbors.length; i++) {
        const w = neighbors[i];

        if (color[w] === Colors.WHITE) {
          color[w] = Colors.GREY;
          queue.enqueue(w);
        }
      }

      color[u] = Colors.BLACK;

      if (callback) {
        callback(u);
      }
    }
  }

  DFS(callback) {
    const vertices = this.getVertices();
    const adjacencyList = this.getAdjacencyList();
    const color = initializeColor(vertices);

    for (let i = 0; i < vertices.length; i++) {
      if (color[vertices[i]] === Colors.WHITE) {
        this.visitDFS(vertices[i], color, adjacencyList, callback);
      }
    }
  }

  visitDFS(u, color, adjacencyList, callback) {
    color[u] = Colors.GREY;

    if (callback) {
      callback(u);
    }

    const neighbors = adjacencyList.get(u);

    for (let i = 0; i < neighbors.length; i++) {
      const w = neighbors[i];

      if (color[w] === Colors.WHITE) {
        this.visitDFS(w, color, adjacencyList, callback);
      }
    }

    color[u] = Colors.BLACK;
  }

  isConnected() {
    let visitedVerticesBFS = 0;

    this.BFS(this.vertices[0], () => ++visitedVerticesBFS);

    return this.vertices.length === visitedVerticesBFS;
  }
}

module.exports = { Graph };
