package com.br.exe06;

public class BST{
	
	private class Node{
		
		int key;
		Node left;
		Node right;
		
		public Node(int key) {
			
			this.key = key;
		}
	}
	
	private Node root;

	public void add(int key) {

		root = add(root, key);
	}
	
	private Node add(Node r, int key) {
		
		if(r==null) {
			
			return new Node(key);
		}
		
		if(key<r.key) {
			
			r.left = add(r.left, key);
		}
		else
		if(key>r.key) {
			
			r.right = add(r.right, key);
		}
		else {
			
			r.key = key;
		}
		
		return r;
	}
	
	public void  printInOrder() {
		
		print(root);
	}
	
	private void print(Node r) {
		
		if(r==null) {
			
			return;
		}
		
		print(r.left);
		System.out.print(r.key + " ");
		print(r.right);
	}
	
	public int getHeight() {
		
		return height(root);
	}
	
	private int height(Node r) {
		
		if(r==null) {

			return -1;
		}

		int hleft = height(r.left);
		int hright = height(r.right);

		if(hleft>hright) {

			return hleft + 1;
		}
		
		return hright + 1;
	}
	
	public boolean verifyBalance() {
		
		return isBalanced(root);
	}
	
	private boolean isBalanced(Node r) {
		
		if (root==null) {
			
			return true;
		}

		int hleft = height(r.left);
		int hright = height(r.right);
			
		return Math.abs(hleft-hright)>1 ? false : true;
	}
	
	public void balancedTree(int[] v) {
		
		add(v[v.length/2]);
		
		for(int i=0; i<v.length; i++) {
			
			add(v[i]);
		}
	}
}
