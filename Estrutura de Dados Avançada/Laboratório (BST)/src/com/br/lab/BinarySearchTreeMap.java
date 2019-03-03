package com.br.lab;

public class BinarySearchTreeMap<K extends Comparable<K>, V> implements OrderedMap<K, V> {
	
	private class Node{
		
		K key;
		V value;
		Node left;
		Node right;
	
		public Node(K key, V value) {
			
			this.key = key;
			this.value = value;
		}	
	}
	
	private Node root;

	@Override
	public void add(K key, V value) {

		root = add(root, key, value);
	}
	
	@Override
	public V get(K key) {
		
		return get(root, key);
	}
	
	@Override
	public void remove(K key) {

		root = remove(root, key);
	}
	
	@Override
	public Iterable<K> keys() {
		
		return null;
	}

	@Override
	public K min() {
		
		return minNode(root).key;
	}
	
	@Override
	public K max() {
		
		return maxNode(root).key;
	}
	
	@Override
	public K ceiling(K key) {
		
		Node r = floor(root, key);
		
		if(r==null) {
			
			return null;
		}
		
		return r.key;
	}

	@Override
	public K floor(K key) {
		
		Node r = floor(root, key);
		
		if(r==null) {
			
			return null;
		}
		
		return r.key;
	}
	
	public void printInOrder(BinarySearchTreeMap<K,V> tree) {
		
		print(tree.root);
	}
	
	private void print(Node r) {
		
		if(r==null) {
			
			return;
		}
		
		print(r.left);
		System.out.println(r.key);
		print(r.right);
	}
	
	private Node add(Node r, K key, V value) {
		
		if(r==null) {
			
			return new Node(key, value);
		}
		
		if(key.compareTo(r.key)<0) {
			
			r.left = add(r.left, key, value);
		}
		else 
		if(key.compareTo(r.key) > 0) {
			
			r.right = add(r.right, key, value);
		}
		else {
			
			r.value = value;
		}
		
		return r;
	}

	private V get(Node r, K key) {
		
		if(r==null) {
			
			return null;
		}
		
		int cmp = key.compareTo(r.key);
		
		if(cmp<0) {
			
			return get(r.left, key);
		}
		else
		if(cmp>0) {
			
			return get(r.right, key);
		}
		else {
			
			return r.value;
		}
	}
	
	private Node minNode(Node r) {
		
		if(r.left==null) {
			
			return r;
		}
		
		return minNode(r.left);
	}
	
	private Node maxNode(Node r) {
		
		if(r==null) {
			
			return null;
		}
		
		if(r.right==null) {
			
			return r;
		}
		
		return maxNode(r.right);
	}
	
	public void removeMin() {
		
		root = removeMin(root);
	}
	
	private Node removeMin(Node r) {
		
		if(r==null) {
			
			return null;
		}
		
		if(r.left==null) {
			
			return r.right;
		}
			
		r.left = removeMin(r.left);
		
		return r;
	}
	
	private Node removeMax(Node r) {
		
		if(r==null) {
			
			return null;
		}
		
		if(r.right==null) {
			
			return r.left;
		}
			
		r.right = removeMax(r.right);
		
		return r;
	}

	private Node remove(Node r, K key) {
		
		if(r==null) {
			
			return null;
		}
		
		int cmp = key.compareTo(r.key);
		
		if(cmp<0) {
			
			r.left = remove(r.left, key);
		}
		else 
		if(cmp>0) {
			
			r.right = remove(r.right, key);
		}
		else {
			
			if(r.right==null) {
				
				return r.left;
			}
			
			if(r.left==null) {
				
				return r.right;
			}
			
			Node tmp = r;
			
			r = minNode(r.right);
			r.right = removeMin(tmp.right);
			r.left = tmp.left;
		}
		
		return r;
	}	

	public Node floor(Node r, K key) {

		if(r==null) {
			
			return null;
		}
		
		int cmp = key.compareTo(r.key);
		
		if(cmp==0) {
			
			return r;
		}
		
		if(cmp<0) {
		
			return floor(r.left, key);
		}
		
		Node tmp = floor(r.right, key);
		
		if(tmp!=null) {
			
			return tmp;
		}
		else {
			
			return r;
		}
	}
	
	/*
	 
	private Node minNodeInterativo(){
		
		if(root==null) {
			
			return null;
		}
		
		Node r = root;
		
		while(r.left!=null) {
			
			r = r.left;
		}
		
		return r;
	}
	
	private Node maxNodeInterativo(){
		
		if(root==null) {
			
			return null;
		}
		
		Node r = root;
		
		while(r.right!=null) {
			
			r = r.right;
		}
		
		return r;
	}
	
	*/
}
