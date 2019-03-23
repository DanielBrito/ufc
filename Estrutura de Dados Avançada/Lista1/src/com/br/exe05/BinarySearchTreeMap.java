package com.br.exe05;

import java.util.LinkedList;
import java.util.Queue;

public class BinarySearchTreeMap<K extends Comparable<K>, V> implements OrderedMap<K, V> {
	
	private class Node{
		
		K key;
		V value;
		Node left;
		Node right;
		int count;
	
		public Node(K key, V value, int count) {
			
			this.key = key;
			this.value = value;
			this.count = count;
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
	
	@Override
	public Iterable<K> keys(K lo, K hi){
		
		Queue<K> queue = new LinkedList<K>();
		
		keys(root, queue, lo, hi);
		
		return queue;
	}
	
	public Iterable<K> keys() {
		
		return keys(min(), max());
	}
	
	private void keys(Node r, Queue<K> queue, K lo, K hi) {
		
		if(r==null) {
			
			return;
		}
		
		int cmpLo = lo.compareTo(r.key);
		int cmpHi = hi.compareTo(r.key);
		
		if(cmpLo<0) {
			
			keys(r.left, queue, lo, hi);
		}
		
		if(cmpLo<=0 && cmpHi>=0) {
			
			queue.add(r.key);
		}
		
		if(cmpHi>0) {
			
			keys(r.right, queue, lo, hi);
		}
	}
	
	@Override
	public int size() {
		
		return size(root);
	}
	
	private int size(Node r) {
		
		if(r==null) {
			
			return 0;
		}
		else {
			
			return r.count;
		}
	}
	
	private int count(Node r) {
		
		return (r!=null)? r.count : 0;
	}
	
	private int rank(Node r, K val) {
		
		if(r==null) {
			
			return 0;
		}
		
		int cmp = val.compareTo(r.key);
		
		if(cmp < 0) {
			
			return rank(r.left, val);
		}
		
		if(cmp > 0) {
			
			return count(r.left) + rank(r.right, val) + 1;
		}
		
		return count(r.left) + 1;
	}
	
	public int rank(K key) {
		
		return rank(root, key);
	}
	
	public void printInOrder(BinarySearchTreeMap<K,V> tree) {
		
		print(tree.root);
	}
	
	private void print(Node r) {
		
		if(r==null) {
			
			return;
		}
		
		print(r.left);
		System.out.println("N = " + r.count + " # Chave: " + r.key + " | Valor: " + r.value);
		print(r.right);
	}
	
	public int height() {
		
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
	
	private Node add(Node r, K key, V value) {
		
		if(r==null) {
			
			return new Node(key, value, 1);
		}
		
		int cmp = key.compareTo(r.key);
		
		if(cmp<0) {
			
			r.left = add(r.left, key, value);
		}
		else 
		if(cmp>0) {
			
			r.right = add(r.right, key, value);
		}
		else {
			
			r.value = value;
		}
		
		r.count = size(r.left) + size(r.right) + 1;
		
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
	
	@SuppressWarnings("unused")
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
		
		r.count = size(r.left) + size(r.right) + 1;
		
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
