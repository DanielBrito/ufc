package com.br.lista1;

import java.util.ArrayList;

class Repositorio{
	
	static ArrayList <Bota> botas = new ArrayList<>();

	public Repositorio(){
		
	}
		
	public void adicionar(Bota bota){
		
		botas.add(bota);
	}

	public void mostra(){

		for(Bota bota: botas){
			
			System.out.println(bota);
		}
	}
	
	public static int contaPares() {
		
		int total=0;
		
		int n = botas.size();
		
		for(int i=0; i<n-1; i++) {
			
			if((botas.get(i).getLado()=='E') && botas.get(i).getStatus()==false) {
				
				for(int j=i+1; j<n; j++) {
					
					if((botas.get(i).getTamanho()==botas.get(j).getTamanho()) && (botas.get(j).getLado()=='D') && (botas.get(j).getStatus()==false)) {
						
						total++;
					}
				}
			}
			else {
				
				for(int j=i+1; j<n; j++) {
					
					if((botas.get(i).getTamanho()==botas.get(j).getTamanho()) && (botas.get(j).getLado()=='E') && (botas.get(j).getStatus()==false)) {
						
						total++;
					}
				}
			}
		}
		
		return total;
	}
}