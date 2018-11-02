package com.br.trabalho2;

import java.util.ArrayList;

public class Primos {
	
private ArrayList<Integer> primos  = new ArrayList<Integer>();
	
	public Primos() {}
	
	public int getTamanho() {
		
		return primos.size();
	}

	public int getIndice(int indice) {
		
		return primos.get(indice);
	}
	
	public void primosAteN(int n) {
		
		for(int i = 2; i <= n; i++) {
			
			if(testaPrimos(i)) {
				
				primos.add(i);
			}
		}
	}
	
	public boolean testaPrimos(int n){

		int i, cont=0;

		if(n<1){

			return false;
		}

		for(i=1; i<=n; i++){

			if(n%i==0){
				cont++;

				if(cont>2){

					return false;
				}
			}
		}
		
		return true;
	}
}