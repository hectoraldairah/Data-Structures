class Node {
  constructor(data, right = null, left = null) {
    this.data = data;
    this.right = right;
    this.left = null;
  }

  addNode(n) {
    if (n.data < this.data) {
      if (this.left === null) {
        this.left = n;
      } else {
        this.left.addNode(n);
      }
    } else if (n.data > this.data) {
      if (this.right === null) {
        this.right = n;
      } else {
        this.right.addNode(n);
      }
    }
  }
}
