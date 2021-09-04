const dijkstra = (graph, source) => {
  let dist = [];
  let visited = [];
  let { length } = graph;

  for (let i = 0; i < length; i++) {
    dist[i] = Infinity;
    visited[i] = false;
  }

  dist[source] = 0;

  for (let i = 0; i < length - 1; i++) {
    let u = minDistance(dist, visited);
    visited[u] = true;

    for (let v = 0; v < length; v++) {
      if (
        !visited[v] &&
        dist[u] !== Infinity &&
        dist[u] + graph[u][v] < dist[v]
      ) {
        dist[v] = dist[u] + graph[u][v];
      }
    }
  }

  return dist;
};

const minDistance = (dist, visited) => {
  let min = Infinity;
  let minIndex = -1;

  for (let v = 0; v < dist.length; v++) {
    if (visited[v] === false && dist[v] <= min) {
      min = dist[v];
      minIndex = v;
    }
  }

  return minIndex;
};
