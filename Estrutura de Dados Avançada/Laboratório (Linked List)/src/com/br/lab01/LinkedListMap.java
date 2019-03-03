package com.br.lab01;

import java.util.LinkedList;
import java.util.List;

public class LinkedListMap<K, V> implements Map<K, V> {
	
	private class Entry {
		
		K key;
		V value;
		Entry next;
		
		public Entry(K key, V value, Entry next) {
			
			this.key = key;
			this.value = value;
			this.next = next;
		}
	}
	
	private Entry first;
	
	@Override
	public void add(K key, V value) {
		
		Entry e = getEntry(key);
		
		if (e == null) {
			
			first = new Entry(key, value, first);
		}
		else { 
			
			e.value = value;
		}
	}
	
	private Entry getEntry(K key) {
		
		for (Entry r = first; r != null; r = r.next) {
			
			if (r.key.equals(key)) {
				
				return r;
			}
		}
		
		return null;
	}

	@Override
	public V get(K key) {
		
		Entry e = getEntry(key);
		
		return (e != null)? e.value : null;
	}

	@Override
	public void remove(K key) {
		
		Entry lst = new Entry(null, null, first);
		
		for (Entry prev = lst; prev.next != null; prev = prev.next) {
			
			if (key.equals(prev.next.key)) {
				
				prev.next = prev.next.next;
				break;
			}
		}
			
		first = lst.next;
	}

	@Override
	public Iterable<K> keys() {
		
		List<K> keys = new LinkedList<>();
		
		for (Entry r = first; r != null; r = r.next) {
			
			keys.add(r.key);
		}
			
		return keys;
	}
}