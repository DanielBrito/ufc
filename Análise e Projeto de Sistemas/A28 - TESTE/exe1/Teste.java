package com.br.exe1;

import java.util.ArrayList;

/* 

Neste exercício é criada uma classe abstrata SmartphonePrototype e algumas classes concretas 
(NokiaPrototype, SamsungPrototype, IphonePrototype) extendendo a classe SmartphonePrototype.

Na classe Teste, são instanciados alguns objetos referentes às classes concretas, estes que 
são clonados com base na motivação e especificações do padrão de projeto Prototype, e que 
têm seus atributos atualizados de acordo com uma necessidade específica.

No final, eles são adicionados a um ArrayList e têm suas características impressas na tela.

*/

public class Teste {

	public static void main(String[] args) {

		ArrayList<SmartphonePrototype> lista  = new ArrayList<SmartphonePrototype>();
		
		SmartphonePrototype nokia2017 = new NokiaPrototype(399.90, "3310");
		
		SmartphonePrototype nokia2018 = nokia2017.clonar();
		nokia2018.setPreco(2980.00);
		nokia2018.setModelo("Sirocco");
		
		SmartphonePrototype samsung2010 = new SamsungPrototype(400.00, "Vibrant");
		
		SmartphonePrototype samsung2018 = samsung2010.clonar();
		samsung2018.setPreco(3200.00);
		samsung2018.setModelo("Galaxy A6");
		
		SmartphonePrototype iphone2015 = new IphonePrototype(2000.00, "6s Plus");
		
		SmartphonePrototype iphone2018 = iphone2015.clonar();
		iphone2018.setPreco(4000.00);
		iphone2018.setModelo("8");
		
		lista.add(nokia2017);
		lista.add(nokia2018);
		lista.add(samsung2010);
		lista.add(samsung2018);
		lista.add(iphone2015);
		lista.add(iphone2018);
		
		for(SmartphonePrototype x : lista) {
			
			System.out.println(x.exibirInfo() + "\n");
		}
	}

}
