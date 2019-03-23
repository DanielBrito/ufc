package com.br.exe06;

import java.util.Arrays;

public class TestBST {

	public static void main(String[] args) {

		BST tree = new BST();
		int N = 10;
		
		int[] v = new int[N];
		
		for(int i=0; i<N; i++) {
			
			v[i] = (int)(Math.random()*50+1); // [1..50]
		}
		
		Arrays.sort(v);
		
		tree.balancedTree(v);
		
		System.out.println("VETOR:");
		
		for(int i=0; i<N; i++) {
			
			System.out.print(v[i] + " ");
		}
		
		System.out.println("\n\nBST:");
	    tree.printInOrder();
	    
	    System.out.println("\n\nBALANCEADA ? " + tree.verifyBalance());
	}
}
