package com.br.teste1;

import java.util.ArrayList;

public class CopaDoMundo {
	
	static ArrayList <Time> times = new ArrayList<>();
	
	public void adicionar(Time time){
		
		times.add(time);
	}
	
	public static int contaEmpates() {
		
		int total=0;
		
		for(int i=0; i<times.size(); i++) {
			
			total += times.get(i).getPontos();
		}
		
		return ((Entrada.getQtdPartidas()*3)-total);
	}

}
