package eda.atividade5;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Collections;
import java.util.Comparator;
import java.util.Vector;

public class Main {
	
	static Vector<Objeto> objetosCasa = new Vector<Objeto>();
    static Vector<Objeto> objetosResgatados = new Vector<Objeto>();
        
    static String nome;
    static double peso, valor, pesoMaximo;
	static boolean sair = false;
	static BufferedReader scan = new BufferedReader(new InputStreamReader(System.in));
	
	public static void main(String[] args) throws NumberFormatException, IOException {
		
		while(!sair) {
			
			System.out.println("\nMENU\n");
			System.out.println("1 - Indexar novo elemento");
			System.out.println("2 - Resgatar elementos relevantes");
			System.out.println("3 - Exibir conjunto de dados");
			System.out.println("4 - Exibir elementos resgatados");
			System.out.println("0 - Sair\n");
			
			System.out.print("- > ");
			int opcao = Integer.parseInt(scan.readLine());
			
			if(opcao==1) {
				
				System.out.println("\n1 - INDEXAR NOVO ELEMENTO\n");
				
				System.out.print("Digite o nome do objeto: ");
				nome = scan.readLine();
				
				System.out.print("Digite o peso do objeto: ");
				peso = Double.parseDouble(scan.readLine());
				
				System.out.print("Digite o valor do objeto: ");
				valor = Double.parseDouble(scan.readLine());
				
				objetosCasa.add(new Objeto(nome, peso, valor));
			}
			else
			if(opcao==2) {
				
				System.out.println("\n2 - RESGATAR ELEMENTOS RELEVANTES\n");
				
				System.out.print("Digite o peso máximo: ");
				pesoMaximo = Double.parseDouble(scan.readLine());
				
				System.out.println();
				
				if(objetosCasa.size()!=0) {
					
					resgatarElementos(pesoMaximo);
				}
				else {
					
					System.out.println("Não existem objetos na casa!");
				}								
			}
			else
			if(opcao==3) {
				
				System.out.println("\n3 - EXIBIR CONJUNTO DE DADOS\n");
				
				if(objetosCasa.size()!=0) {
					
					exibirObjetos(objetosCasa);
				}
				else {
					
					System.out.println("Não existem objetos na casa!");
				}				
			}
			else
			if(opcao==4) {
				
				System.out.println("\n4 - EXIBIR ELEMENTOS JÁ RESGATADOS\n");
				
				if(objetosResgatados.size()!=0) {
					
					exibirObjetos(objetosResgatados);
				}
				else {
					
					System.out.println("Nenhum objeto foi resgatado!");
				}
			}
			else
			if(opcao==0) {
				
				sair = true;
			}
			else {
				
				System.out.println("Opcao inválida!\n");
			}
		}
	}
	
	public static void resgatarElementos(double pesoMaximo) {
		
        Comparator<Objeto> cmp = new Comparator<Objeto>() {
        	
            public int compare(Objeto x, Objeto y) {
            	
                return (int) ((x.peso/x.valor) - (y.peso/y.valor));
            }
        };
        
        Collections.sort(objetosCasa, cmp);
        Collections.reverse(objetosCasa);
     
        Vector<Objeto> objetosMochila = new Vector<Objeto>();
        double pesoMochila=0;
        int posicao=0;
        
        while(pesoMochila<pesoMaximo && posicao<objetosCasa.size()) {
        	
            Objeto tmp = objetosCasa.get(posicao);
            
            if(pesoMochila+tmp.peso <= pesoMaximo) {
            	
                objetosMochila.add(tmp);
                objetosResgatados.add(tmp);                
                pesoMochila += tmp.peso;
            }
            
            posicao++;
        }
        
        if(objetosMochila.size()!=0) {
        	
            for(Objeto obj : objetosMochila) {
            	
            	System.out.printf("  Nome: %s\n", obj.nome);
            	System.out.printf("  Peso: %.2f\n", obj.peso);
            	System.out.printf("  Valor: %.2f\n\n", obj.valor);
            }
            
            for(Objeto obj : objetosMochila) {
            	
            	objetosCasa.remove(obj);
            }       	
        }
        else {
        	
        	System.out.println("A mochila não suporta os objetos!");
        }
	}
	
	public static void exibirObjetos(Vector<Objeto> objetos) {
        
        for(Objeto obj : objetos) {
        	
        	System.out.printf("  Nome: %s\n", obj.nome);
        	System.out.printf("  Peso: %.2f\n", obj.peso);
        	System.out.printf("  Valor: %.2f\n\n", obj.valor);
        }
	}
}
