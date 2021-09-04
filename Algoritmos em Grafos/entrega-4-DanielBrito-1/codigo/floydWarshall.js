const floydWarshall = (graph) => {
  let dist = [];
  let { length } = graph;

  for (let i = 0; i < length; i++) {
    dist[i] = [];

    for (let j = 0; j < length; j++) {
      if (i === j) {
        dist[i][j] = 0;
      } else if (!isFinite(graph[i][j])) {
        dist[i][j] = Infinity;
      } else {
        dist[i][j] = graph[i][j];
      }
    }
  }

  for (let i = 0; i < length; i++) {
    for (let j = 0; j < length; j++) {
      for (let k = 0; k < length; k++) {
        if (dist[j][i] + dist[i][k] < dist[j][k]) {
          dist[j][k] = dist[j][i] + dist[i][k];
        }
      }
    }
  }

  return dist;
};
