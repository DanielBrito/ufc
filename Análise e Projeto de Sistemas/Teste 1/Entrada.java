package com.br.teste1;

import java.util.Scanner;

public class Entrada {

	private static Scanner scan = new Scanner(System.in);
	private static int qtdPartidas;
	
	public static void validacao(){
		
		CopaDoMundo copa = new CopaDoMundo();
		
		int qtdTimes = 0;
		String nome = null;
		int pontos = 0;
		
		String input;
		
		String[] qtdPartidasTimes = null;
		String[] timePontos = null;
		
		do {
			
			input = scan.nextLine();
			qtdPartidasTimes = input.split(" ");
			
			qtdTimes = Integer.parseInt(qtdPartidasTimes[0]);
			qtdPartidas = Integer.parseInt(qtdPartidasTimes[1]);
			
		}while((qtdTimes<2 || qtdTimes>200) && (qtdPartidas<0 || qtdPartidas>Math.pow(10,4)));
			
		for(int i=0; i<qtdTimes; i++) {
			
			do {
				
				input = scan.nextLine();
				timePontos = input.split(" ");
				
				nome = timePontos[0];
				pontos = Integer.parseInt(timePontos[1]);
				
			}while(nome.length()>10);
			
			copa.adicionar(new Time(nome, pontos));
		}
	}
	
	public static int getQtdPartidas() {
		
		return qtdPartidas;
	}
}
