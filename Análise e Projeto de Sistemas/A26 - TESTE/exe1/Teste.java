package com.br.exe1;

public class Teste {

	public static void main(String[] args) {
		
		Item eletro[] = new Item[3];
		
		eletro[0] = new Item(45, "Forno Microondas", 355.00, 1);
		eletro[1] = new Item(80, "Circulador de Ar", 250.00, 2);
		eletro[2] = new Item(82, "Televisão 14'", 470, 1);
		
		CupomFiscal cf1 = new CupomFiscal.CupomFiscalBuilder("MC ELETRODOMÉSTICOS", "01.111.111/0001-19")
				                         .cnpjConsumidor("00.879.197/0001-80")
				                         .dinheiroRecebido(2000.00)
				                         .listaItem(eletro)
				                         .build();
		
		Impressora.getInstance().imprimirNota(cf1);
		
		Item mobilia[] = new Item[3];
		
		mobilia[0] = new Item(56, "Guarda-roupas", 590.00, 2);
		mobilia[1] = new Item(34, "Estante", 129.00, 3);
		mobilia[2] = new Item(99, "Cama", 700.00, 4);
		
		CupomFiscal cf2 = new CupomFiscal.CupomFiscalBuilder("CASAS BAHIA", "12.345.678/2018-11")
				                         .cpfConsumidor("401.792218-09")
				                         .dinheiroRecebido(5000.00)
				                         .listaItem(mobilia)
				                         .build();
		
		Impressora.getInstance().imprimirNota(cf2);
		
		CupomFiscal cupons[] = new CupomFiscal[2];
		
		cupons[0] = cf1;
		cupons[1] = cf2;
		
		Impressora.getInstance().imprimirNota(cupons);
	}
}
