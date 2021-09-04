const { Element } = require("./Element");

class PriorityQueue {
  constructor() {
    this.values = [];
  }

  enqueue(value, priority) {
    let element = new Element(value, priority);
    this.values.push(element);

    let index = this.values.length - 1;
    const current = this.values[index];

    while (index > 0) {
      let parentIndex = Math.floor((index - 1) / 2);
      let parent = this.values[parentIndex];

      if (parent.priority <= current.priority) break;

      this.values[parentIndex] = current;
      this.values[index] = parent;
      index = parentIndex;
    }
  }

  dequeue() {
    if (this.isEmpty()) {
      return undefined;
    }

    if (this.values.length === 1) {
      return this.values.pop();
    }

    const min = this.values[0];
    const end = this.values.pop();

    this.values[0] = end;

    let index = 0;
    const length = this.values.length;
    const current = this.values[0];

    while (true) {
      let leftChildIndex = 2 * index + 1;
      let rightChildIndex = 2 * index + 2;
      let leftChild, rightChild;
      let swap = null;

      if (leftChildIndex < length) {
        leftChild = this.values[leftChildIndex];

        if (leftChild.priority < current.priority) {
          swap = leftChildIndex;
        }
      }

      if (rightChildIndex < length) {
        rightChild = this.values[rightChildIndex];

        if (
          (swap === null && rightChild.priority < current.priority) ||
          (swap !== null && rightChild.priority < leftChild.priority)
        )
          swap = rightChildIndex;
      }

      if (swap === null) break;

      this.values[index] = this.values[swap];
      this.values[swap] = current;
      index = swap;
    }

    return min;
  }

  isEmpty() {
    return this.values.length === 0;
  }
}

module.exports = { PriorityQueue };
