const Colors = {
  WHITE: 0 /* Not visited */,
  GREY: 1 /* Visited, but not explored */,
  BLACK: 2 /* Totally explored */,
};

const initializeColor = (vertices) => {
  const color = {};

  for (let i = 0; i < vertices.length; i++) {
    color[vertices[i]] = Colors.WHITE;
  }

  return color;
};

module.exports = { Colors, initializeColor };
