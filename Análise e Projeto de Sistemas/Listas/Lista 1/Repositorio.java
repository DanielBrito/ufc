package com.br.lista1;

import java.util.ArrayList;

class Repositorio{
	
	static ArrayList <Bota> botas = new ArrayList<>();

	public Repositorio(){
		
	}
		
	public void adicionar(Bota bota){
		
		botas.add(bota);
	}
	
	public static int contaPares() {
		
		int total=0;
		
		for(int i=0; i<botas.size()-1; i++) {
			
			if(botas.get(i).getLado()=='E') {
				
				for(int j=i+1; j<botas.size(); j++) {
					
					if((botas.get(i).getTamanho()==botas.get(j).getTamanho()) && (botas.get(j).getLado()=='D') && (botas.get(j).getStatus()==false)) {
						
						total++;
						botas.get(i).setContada(botas.get(i));
						botas.get(j).setContada(botas.get(j));
						
						break;
					}
				}
			}
			else {
				
				for(int j=i+1; j<botas.size(); j++) {
					
					if((botas.get(i).getTamanho()==botas.get(j).getTamanho()) && (botas.get(j).getLado()=='E') && (botas.get(j).getStatus()==false)) {
						
						total++;
						botas.get(i).setContada(botas.get(i));
						botas.get(j).setContada(botas.get(j));
						
						break;
					}
				}
			}
		}
		
		return total;
	}
}