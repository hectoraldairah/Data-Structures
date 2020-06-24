const util = require("util");

class Node {
  constructor(val) {
    this.val = val;
    this.next = null;
  }
}

class SinglyLinkedList {
  constructor() {
    this.head = null;
    this.tail = null;
    this.length = 0;
  }
  traverse() {
    let current = this.head;
    while (current) {
      console.log(current.val);
      current = current.next;
    }
    return;
  }
  push(val) {
    let newNode = new Node(val);
    if (!this.head) {
      this.head = newNode;
      this.tail = this.head;
    } else {
      this.tail.next = newNode;
      this.tail = newNode;
    }
    this.length++;
    return this;
  }
  pop() {
    if (!this.head) return undefined;
    let current = this.head;
    let newTail = current;
    while (current.next) {
      newTail = current;
      current = current.next;
    }
    newTail.next = null;
    this.tail = newTail;
    this.length--;
    return current;
  }
  shift() {
    if (!this.head) return null;
    let current = this.head;
    this.head = current.next;
    this.length--;
    return current.val;
  }
  unShift(val) {
    if (!this.head) return this.push(val);
    let newNode = new Node(val);
    newNode.next = this.head;
    this.head = newNode;
    this.length++;
    return this;
  }
  get(index) {
    if (index < 0 || index >= this.length) return null;
    let currentNode = this.head;
    let count = 0;
    while (index != count) {
      currentNode = currentNode.next;
      count++;
    }
    return currentNode;
  }

  set(index, val) {
    let nodeFound = this.get(index);
    if (nodeFound) {
      nodeFound.val = val;
      return true;
    }
    return false;
  }

  insert(index, val) {
    if (index < 0 || index > this.length) return false;
    if (index === this.length) return !!this.push(val);
    if (this.length === 0) return !!this.unShift(val);

    let prevNode = this.get(index - 1);
    let newNode = new Node(val);
    let temp = prevNode.next;
    prevNode.next = newNode;
    newNode.next = temp;
    this.length++;
    return true;
  }

  remove(index) {
    if (index < 0 || index >= this.length) return undefined;
    if (index === this.length - 1) return this.pop();
    if (index === 0) return this.shift();

    let prevNode = this.get(index - 1);
    let removed = prevNode.next;
    prevNode.next = removed.next;
    removed.next = null;
    this.length--;
    return removed;
  }
  reverse() {
    let node = this.head;
    this.head = this.tail;
    this.tail = node;
    let next;
    let prev = null;

    for (let i = 0; i < this.length; i++) {
      next = node.next;
      node.next = prev;
      prev = node;
      node = next;
    }
    return this;
  }
  rotate(number) {
    const index = number < 0 ? number + this.length : number;
    if (index < 0 || index >= this.length) return undefined;
    if (index === 0) return this;

    const prevNode = this.get(index - 1);
    console.log(prevNode);
    if (!prevNode) return undefined;

    this.tail.next = this.head;
    this.head = prevNode.next;
    this.tail = prevNode;
    prevNode.next = null;

    return this;
  }

  print() {
    let arr = [];
    let currentNode = this.head;
    while (currentNode) {
      arr.push(currentNode.val);
      currentNode = currentNode.next;
    }
    return arr;
  }
}
let list = new SinglyLinkedList();
list.push(5).push(10).push(15).push(20).push(25);
console.log(list.head.val);
console.log(list.tail.val);
list.rotate(-1);
console.log(list.head.val);
console.log(list.head.next.val);
console.log(list.head.next.next.val);
console.log(list.head.next.next.next.val);
console.log(list.head.next.next.next.next.val);
console.log(list.tail.val);
console.log(list.tail.next);
console.log(list.length);
