package com.br.exe08;

public interface OrderedMap<K extends Comparable<K>, V> extends Map<K, V>{
	
	K min();
	K max();
	K ceiling(K key);
	K floor(K key);
	int rank(K key);
}