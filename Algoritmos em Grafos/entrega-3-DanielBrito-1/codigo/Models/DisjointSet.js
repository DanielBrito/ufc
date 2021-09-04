class DisjointSet {
  constructor() {
    this.parents = [];
  }

  find(x) {
    if (typeof this.parents[x] !== "undefined") {
      if (this.parents[x] < 0) {
        return x;
      } else {
        return this.find(this.parents[x]);
      }
    } else {
      this.parents[x] = -1;
      return x;
    }
  }

  union(x, y) {
    let xParent = this.find(x);
    let yParent = this.find(y);

    if (xParent !== yParent) {
      this.parents[xParent] += this.parents[yParent];
      this.parents[yParent] = xParent;
      return false;
    } else {
      return true;
    }
  }
}

module.exports = { DisjointSet };
