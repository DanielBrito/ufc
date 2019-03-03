package com.br.lab01;

public class TestLinkedList {
	
	public static void main(String[] args) {
		
		Map<String, Integer> map = new LinkedListMap<>();
		
		map.add("João", 23);
		map.add("Maria", 33);
		map.add("Paulo", 43);
		map.add("Paulo", 53);
		map.add("Tereza", 63);
		
		map.remove("Tereza");
		map.remove("João");
		map.remove("Paulo");
		
		System.out.println(map.get("Paulo"));
		
		for (String key : map.keys()) {
			
			System.out.println(key);
		}	
	}
}
