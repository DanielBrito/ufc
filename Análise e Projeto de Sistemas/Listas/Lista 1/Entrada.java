package com.br.lista1;

import java.util.Scanner;

abstract class Entrada{

	private static Scanner scan = new Scanner(System.in);
	
	public static void validacao(){
		
		Repositorio repositorio = new Repositorio();

		int qtdBotas;
		int tamanho;
		char lado;

		do{
			
			qtdBotas = scan.nextInt();

		}while(qtdBotas%2==1 || qtdBotas<2 || qtdBotas>Math.pow(10,4));

		for(int i=0; i<qtdBotas; i++){

			do{
				
				tamanho = scan.nextInt();

			}while(tamanho<30 || tamanho>60);

			do{
				
				lado = scan.next().charAt(0);
				
			}while(!(lado =='D' || lado=='E'));

			repositorio.adicionar(new Bota(tamanho,lado));
		}
	}
}
