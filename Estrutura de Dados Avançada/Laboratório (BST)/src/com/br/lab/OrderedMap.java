package com.br.lab;

public interface OrderedMap<K extends Comparable<K>, V> extends Map<K, V>{
	
	K min();
	K max();
	K ceiling(K key);
	K floor(K key);
}