package com.br.exe07;

import java.util.ArrayList;
import java.util.List;

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
	
	// ADD ELEMENTS

	public void add(int key) {

		root = add(root, key);
		
		List<Integer> l = new ArrayList<Integer>();
		l = getInOrder(l, root);

		balanceTree(l);
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
	
	// PRINT ELEMENTS
	
	public void printInOrder() {
		
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
	
	// LIST ELEMENTS (IN ORDER)
	
	private List<Integer> getInOrder(List<Integer> l, Node r){
		
		if(r==null) {
			
			return null;
		}
		
		getInOrder(l, r.left);
		l.add(r.key);
		getInOrder(l, r.right);

		return l;
	}
	
	// VERIFY BALANCE
	
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
	
	// GET HEIGHT
	
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
	
	// BALANCE TREE
	
	public void balanceTree(List<Integer> l) {
		
		int m = l.get((l.size())/2);
		
		Node middle = new Node(m);
		
		root = middle;// Set new root
		
		for(int x : l) {
			
			add(root, x);
		}
	}
}
