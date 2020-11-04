package com.br.ufc.topico3;

public class Main {

	public static void main(String[] args) {
		
		// Definicao das matrizes para teste:
		double[][] a = {{1, 4, 3}, {2, 5 ,4}, {1, -3, -2}};
		double[][] b = {{1, 3, 2}, {-2, 1, 1}, {-1, 4, 3}};
		double[][] c = {{1, 2, 1}, {2, 1, -3}, {3, 3, -2}};
		
		Matriz A = new Matriz(a);
		double[] Ab = {1, 4, 5};   // Termos independentes
		
		Matriz B = new Matriz(b);
		double[] Bb = {1, -2, -1}; // Termos independentes
		
		Matriz C = new Matriz(c);
		double[] Cb = {1, 4, 0};   // Termos independentes
		
		resolverSistema(A, Ab); // Sistema possivel e determinado
		resolverSistema(B, Bb); // Sistema possivel e indeterminado
		resolverSistema(C, Cb); // Sistema impossível
	}
	
	public static void resolverSistema(Matriz matrizCoeficientes, double[] termosIndependentes) {
		
		double[] solucao = Sistemas.eliminacaoGaussianaPivoteamento(matrizCoeficientes, termosIndependentes);
		
		// Verificando a categoria do sistema com base na solucao:
		
		if(Matriz.determinante(matrizCoeficientes)!=0 && solucao!=null) {
			
			System.out.println("Sistema possivel e determinado\n");
			
			System.out.print("S = { ");
			
			for(int i=0; i<solucao.length; i++) {
					
				System.out.printf("%.2f ", solucao[i]);
			}
			
			System.out.print("}\n\n");
		}
		else
		if(Matriz.determinante(matrizCoeficientes)==0 && solucao==null){
			
			System.out.println("Sistema possivel e indeterminado\n");
		}
		else {
			
			System.out.println("Sistema impossivel\n");
		}
		
		System.out.println("------------------------------------------\n");
	}
}