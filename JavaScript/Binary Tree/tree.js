class Tree {
  constructor() {
    this.root = null;
  }

  addValue(val) {
    let n = new Node(val);
    if (this.root === null) {
      this.root = n;
    } else {
      this.root.addNode(n);
    }
  }
}
