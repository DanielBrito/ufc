package com.br.lab;

import java.util.LinkedList;

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
		
		tree.printInOrder(tree);
		System.out.println();
		
		System.out.print("Size: ");
		System.out.println(tree.size());
		
		System.out.print("Rank: ");
		System.out.println(tree.rank("D"));
		
		System.out.print("Height: ");
		System.out.println(tree.height());
		
		Iterable<String> list = new LinkedList<String>();
		
		list = tree.keys("F", "T");
		
		System.out.println(list);
	}
}
