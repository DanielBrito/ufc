package com.br.exe07;

public class TestBST {

	public static void main(String[] args) {

		BST tree = new BST();
		
		tree.add(15);
		tree.add(1);
		tree.add(3);
		tree.add(19);
		tree.add(4);
		tree.add(7);
		tree.add(9);
		tree.add(6);
		tree.add(20);
		tree.add(18);
	    
	    System.out.println("BALANCEADA ? " + tree.verifyBalance());
	}
}
