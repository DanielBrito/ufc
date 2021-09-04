const shortestPath = (graph, source) => {
  let { length } = graph;
  let dist = [];

  for (let i = 0; i < length; i++) {
    dist[i] = Infinity;
  }

  dist[source] = 0;

  for (let u in topologicalSort(graph)) {
    for (let v = 0; v < length; v++) {
      if (graph[u][v] !== null) {
        let newDist = dist[u] + graph[u][v];

        if (newDist < dist[v]) {
          dist[v] = newDist;
        }
      }
    }
  }

  return dist;
};

const topologicalSort = (graph) => {
  let { length } = graph;
  let visited = [];
  let order = [];
  let index = n - 1;

  for (let i = 0; i < length; i++) {
    if (!visited[i]) {
      index = visit(graph, visited, order, index, u);
    }
  }

  return order;
};

const visit = (graph, visited, order, index, u) => {
  let { length } = graph;

  if (visited[u]) {
    return index;
  }

  visited[u] = true;

  for (let v = 0; v < length; v++) {
    if (graph[u][v] !== null && !visited[v]) {
      index = visit(graph, visited, order, index, v);
    }
  }

  order[index--] = u;

  return index;
};
