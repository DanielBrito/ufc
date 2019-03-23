package com.br.exe08;

public class TestBST {

	public static void main(String[] args) {
		
		BinarySearchTreeMap<String, Integer> tree = new BinarySearchTreeMap<String, Integer>();
		
		tree.add("S", 26);
		tree.add("X", 2);
		tree.add("E", 49);
		tree.add("A", 22);
		tree.add("R", 70);
		tree.add("C", 10);
		tree.add("H", 70);
		tree.add("M", 10);
		tree.add("L", 42);
		tree.add("P", 13);
		
		System.out.println(tree.select(4));
	}
}
