package com.br.trabalho3;

import java.util.ArrayList;
import java.util.Scanner;

public class Operacoes {
	
	// ENTRADA DE DADOS
	
	static Scanner scan = new Scanner(System.in);
	
	static boolean flagAssimetrica = false;
	static boolean flagIrreflexiva = false;
	static boolean flagAntiSimetrica = false;
	static boolean flagTransitiva = false;

	public static void entradaDeDados() {
		
		int qtdElementos, elemento, qtdPares;
		
		System.out.print("Digite a quantidade de elementos do conjunto A: ");
		qtdElementos = scan.nextInt();
		
		int elementos[] = new int[qtdElementos];
		
		System.out.println("\nDigite os elementos do conjunto A: ");
		
		for(int i=0; i<qtdElementos; i++) {
			
			elemento = scan.nextInt();	
			
			if(elemento<1 || elemento>50) {
				
				System.out.println("Os elementos devem ser inteiros de 1 até 50");
				i--;
			}
			else
			if(verificarPertinencia(elementos, elemento)==true){
				
				System.out.println("O elemento já foi inserido no conjunto");
				i--;
			}
			else {
				
				elementos[i] = elemento;
			}
		}
		
		System.out.println("\nDigite a quantidade de pares ordenados: ");
		qtdPares = scan.nextInt();
		
		Tupla pares[] = new Tupla[qtdPares];
		Tupla copiaPares[] = new Tupla[qtdPares];
		
		String valores;
		int x, y;
		
		scan.nextLine();
		
		System.out.println("\nDigite os valores dos pares ordenados (x,y): ");
		
		for(int i=0; i<qtdPares; i++) {
			
			valores = scan.nextLine();			
			String[] par = valores.split(" ");
			
			if(par[0]!=null && par[1]!=null) {
				
				x = Integer.parseInt(par[0]);
				y = Integer.parseInt(par[1]);
			}
			else {
				
				x = 0;
				y = 0;
			}
			
			if(x<1 || x>50 || y<1 || y>50) {
				
				System.out.println("Os elementos devem ser inteiros de 1 até 50");
				--i;
			}
			else 
			if(verificarPertinencia(elementos, x)==false || verificarPertinencia(elementos, y)==false) {
				
				System.out.println("Os elementos digitados devem pertencer ao conjunto A");
				--i;
			}
			else {
				
				Tupla tuplaPares = new Tupla(Integer.parseInt(par[0]), Integer.parseInt(par[1]));
				Tupla tuplaCopiaPares = new Tupla(Integer.parseInt(par[0]), Integer.parseInt(par[1]));
				
				pares[i] = tuplaPares;
				copiaPares[i] = tuplaCopiaPares;
			}
		}
		
		imprimirConjunto(elementos);
		imprimirParesOrdenados(pares);
		
		System.out.println("\n\nPROPRIEDADES:");
		
		reflexividade(pares, elementos);
		simetria(pares, copiaPares, qtdPares);
		assimetrica();
		transitiva(pares);
		equivalenciaOrdemParcial();
		fechoReflexivo(elementos);
		fechoSimetrico(pares);
		fechoTransitivo(pares);
	}
	
	// PROPRIEDADES
	
	public static void reflexividade(Tupla[] pares, int[] elementos) {
		
		int achou = 0;
		
		for(int i=0; i<elementos.length; i++) {
			
			for(int j=0; j<pares.length; j++) {
				
				if(pares[j].getX()==elementos[i] && pares[j].getY()==elementos[i]) {
					
					++achou;
				}
			}
		}
		
		if(achou==elementos.length) {
			
			System.out.println("\n1. Reflexiva: V");
				
			System.out.println("\n2. Irreflexiva: F");
			
			for(int j=0; j<elementos.length; j++) {
				
				for(int k=0; k<pares.length; k++) {
					
					if(pares[k].getX()==elementos[j] && pares[k].getY()==elementos[j]) {
						
						imprimirParOrdenado(pares[k]);
					}
				}
			}
		}
		else {
			
			System.out.println("\n1. Reflexiva: F");
			
			for(int j=0; j<pares.length; j++) {
				
				imprimirParOrdenado(pares[j]);
			}
			
			System.out.println("\n\n2. Irreflexiva: V");
			
			flagIrreflexiva = true;
		}
	}
	
	public static void simetria(Tupla[] pares, Tupla[] copiaPares, int qtdPares) {
		
		int achou = 0;
		
		for(int i=0; i<pares.length; i++) {
			
			if(procurarSimetrico(pares, pares[i])==true) {
				
				++achou;
			}
		}
		
		if(achou==qtdPares) {
			
			System.out.println("\n\n3. Simétrica: V");
			
			System.out.println("\n4. Anti-simétrica: F");
			
			for(int i=0; i<pares.length; i++) {
				
				if(procurarSimetrico(copiaPares, pares[i])==true) {
					
					imprimirSimetricos(pares[i], obterSimetrico(pares[i]));
					removerParOrdenado(copiaPares, pares[i], obterSimetrico(pares[i]));
				}
			}
		}
		else {
			
			System.out.println("\n3. Simétrica: F");
	
			for(int i=0; i<copiaPares.length; i++) {
				
				if(procurarSimetrico(copiaPares, copiaPares[i])==false) {
					
					imprimirParOrdenado(copiaPares[i]);
					removerParOrdenado(copiaPares, copiaPares[i], obterSimetrico(copiaPares[i]));
				}
			}
			
			System.out.println("\n\n4. Anti-simétrica: V");
			
			flagAntiSimetrica = true;
		}
	}
	
	public static void assimetrica() {
		
		if(flagIrreflexiva==true && flagAntiSimetrica==true) {
			
			System.out.println("\n5. Assimétrica: V");
		}
		else {
			
			System.out.println("\n\n5. Assimétrica: F");
		}
	}
	
	public static void transitiva(Tupla[] pares) {
		
		ArrayList<Tupla> lista = new ArrayList<>();
		int naoAchou = 0;
		
		for(int i=0; i<pares.length-1; i++) {
			
			for(int j=i+1; j<pares.length; j++) {
				
				if(pares[i].getY()==pares[j].getX()) {
					
					Tupla transitivo = new Tupla(pares[i].getX(), pares[j].getY());
					
					if(procurarTransitivo(pares, transitivo)==false) {
						
						lista.add(transitivo);
						++naoAchou;
					}
				}
			}
		}
		
		if(naoAchou==0) {
			
			System.out.println("\n6. Transitiva: V");
			
			flagTransitiva = true;
		}
		else {
			
			System.out.println("\n6. Transitiva: F");
			
			for(Tupla t : lista) {
				
				imprimirParOrdenado(t);
			}
		}
	}
	
	public static void equivalenciaOrdemParcial() {
		
		if(flagIrreflexiva==false && flagAssimetrica==false && flagTransitiva==true) {
			
			System.out.println("\nRelação de equivalência: V\nRelação de ordem parcial: F");
		}
		else {
			
			System.out.println("\nRelação de equivalência: F\nRelação de ordem parcial: V");
		}
	}
	
	public static void fechoReflexivo(int[] elementos) {
		
		System.out.print("\nFecho reflexivo da relação = { ");
		
		for(int i=0; i<elementos.length; i++) {
			
			Tupla simetrico = new Tupla(elementos[i], elementos[i]);
			
			imprimirParOrdenado(simetrico);
		}
		
		System.out.print("}");
	}
	
	public static void fechoSimetrico(Tupla[] pares) {
		
		ArrayList<Tupla> lista = new ArrayList<>();
		
		for(int i=0; i<pares.length; i++) {
			
			if(procurarSimetrico(pares, pares[i])==true) {
				
				lista.add(pares[i]);
			}
			else {
				
				lista.add(pares[i]);
				lista.add(obterSimetrico(pares[i]));
			}
		}
		
		System.out.print("\nFecho simétrico da relação = { ");
		
		for(Tupla t : lista) {
			
			imprimirParOrdenado(t);
		}
		
		System.out.print("}");
	}
	
	public static void fechoTransitivo(Tupla[] pares) {
		
		ArrayList<Tupla> lista = new ArrayList<>();
		
		for(int i=0; i<pares.length-1; i++) {
					
			for(int j=i+1; j<pares.length; j++) {
				
				if(pares[i].getY()==pares[j].getX()) {
					
					Tupla transitivo = new Tupla(pares[i].getX(), pares[j].getY());
					
					if(procurarTransitivo(pares, transitivo)==false) {
						
						lista.add(transitivo);
					}
				}
			}
		}
		
		System.out.print("\nFecho transitivo da relação = { ");
		
		for(int i=0; i<pares.length; i++) {
			
			imprimirParOrdenado(pares[i]);
		}		
		
		for(Tupla t : lista) {
			
			imprimirParOrdenado(t);
		}
		
		System.out.print("}");
	}
	
	// IMPRESSÃO
	
	public static void imprimirConjunto(int[] vetor) {
		
		System.out.println("\nElementos do conjunto:");
		
		System.out.print("A = { ");
		
		for(int i=0; i<vetor.length; i++) {
			
			if(i<vetor.length-1) {
				
				System.out.print(vetor[i] + ", ");
			}
			else {
				
				System.out.print(vetor[i] + " };");
			}
		}
	}
	
	public static void imprimirParesOrdenados(Tupla[] vetor) {
		
		System.out.println("\n\nRelação de pares ordenados:");
		
		for(int i=0; i<vetor.length; i++) {
			
			System.out.print("(" + vetor[i].getX() + "," + vetor[i].getY() + "); ");
		}
	}
	
	public static void imprimirParOrdenado(Tupla par) {
		
		if(!(par.getX()==0 && par.getY()==0)) {
			
			System.out.print("(" + par.getX() + "," + par.getY() + "); ");
		}
	}
	
	public static void imprimirSimetricos(Tupla original, Tupla simetrico) {
		
		if(!(original.getX()==0 && original.getY()==0 && simetrico.getX()==0 && simetrico.getY()==0)) {
			
			if(!(original.getX()==simetrico.getX() && original.getY()==simetrico.getY())) {
				
				System.out.print("(" + original.getX() + "," + original.getY() + ") e (" + simetrico.getX() + "," + simetrico.getY() + "); ");
			}			
		}
	}
	
	// FUNÇÕES AUXILIARES
	
	public static boolean verificarPertinencia(int[] vetor, int num) {
		
		for(int i=0; i<vetor.length; i++) {
			
			if(vetor[i]==num) {
				
				return true;
			}
		}
		
		return false;
	}
	
	public static boolean procurarSimetrico(Tupla[] pares, Tupla par) {
		
		for(int i=0; i<pares.length; i++) {
			
			if(pares[i].getX()==par.getY() && pares[i].getY()==par.getX()) {
				
				return true;
			}
		}
		
		return false;
	}
	
	public static void copiarPares(Tupla[] pares, Tupla[] copiaPares) {
		
		for(int i=0; i<pares.length; i++) {
			
			copiaPares[i].setX(pares[i].getX());
			copiaPares[i].setY(pares[i].getY());
		}
	}
	
	public static Tupla obterSimetrico(Tupla par) {
		
		return new Tupla(par.getY(), par.getX());
	}	
	
	public static void removerParOrdenado(Tupla[] copiaPares, Tupla original, Tupla simetrico) {
		
		for(int i=0; i<copiaPares.length; i++) {
			
			if(copiaPares[i].getX()==original.getX() && copiaPares[i].getY()==original.getY()) {
				
				copiaPares[i].setX(0);
				copiaPares[i].setY(0);
			}
		}
		
		for(int i=0; i<copiaPares.length; i++) {
			
			if(copiaPares[i].getX()==simetrico.getX() && copiaPares[i].getY()==simetrico.getY()) {
				
				copiaPares[i].setX(0);
				copiaPares[i].setY(0);
			}
		}
	}
	
	public static boolean procurarTransitivo(Tupla[] pares, Tupla transitivo) {
		
		for(int i=0; i<pares.length; i++) {
			
			if(pares[i].getX()==transitivo.getX() && pares[i].getY()==transitivo.getY()) {
				
				return true;
			}
		}
		
		return false;
	}
}