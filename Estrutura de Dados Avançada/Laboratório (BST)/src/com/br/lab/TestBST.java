package com.br.lab;

public class TestBST {

	public static void main(String[] args) {
		
		BinarySearchTreeMap<String, Integer> tree = new BinarySearchTreeMap<String, Integer>();
		
		tree.add("D", 26);
		tree.add("N", 2);
		tree.add("F", 49);
		tree.add("C", 22);
		tree.add("A", 70);
		tree.add("B", 10);
		
		tree.printInOrder(tree);
	}
}
