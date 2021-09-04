const bellmanFord = (graph, source) => {
  let { length } = graph;
  let dist = [];

  for (let i = 0; i < length; i++) {
    dist[i] = Infinity;
  }

  dist[source] = 0;

  for (let i = 0; i < length - 1; i++) {
    for (let j = 0; j < length; j++) {
      for (let k = 0; k < length; k++) {
        if (dist[j] + graph[j][k] < dist[k]) {
          dist[k] = dist[j] + graph[j][k];
        }
      }
    }
  }

  for (let i = 0; i < length - 1; i++) {
    for (let j = 0; j < length; j++) {
      for (let k = 0; k < length; k++) {
        if (dist[j] + graph[j][k] < dist[k]) {
          return false;
        }
      }
    }
  }

  return true;
};
