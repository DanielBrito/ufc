package com.br.exe1;

import java.text.SimpleDateFormat;
import java.util.Date;

public class Impressora {
	
	private static final Impressora impressora = new Impressora();
	
	private Impressora() {
		
	}
	
	public static Impressora getInstance() {
		
		return impressora;
	}
	
	
	public void imprimirNota(CupomFiscal c){
		
		System.out.println("\t\t" + c.nomeLoja + "\n");
		
		System.out.println("CNPJ: " + c.getCnpj());
		System.out.println(new SimpleDateFormat("dd/MM/yyyy").format(new Date()) + " " + new SimpleDateFormat("HH:mm:ss").format(new Date()));
		
		System.out.println("\n----------------------------------------------------");
		System.out.println("CNPJ/CPF Consumidor: " + (c.getCpfConsumidor()!=null ? c.getCpfConsumidor() : c.getCnpjConsumidor()));
		System.out.println("----------------------------------------------------\n");
		
		System.out.println("\t\t CUPOM FISCAL\n");
		System.out.println("ITEM \t\tCÓDIGO \t\tDESCRIÇÃO");
		System.out.println("\t\tQTDxUNITÁTIO \t\tVALOR(R$)");
		
		System.out.println("____________________________________________________");
		
		double valorTotal = 0;
		
		for(int i=0; i<c.getListaItem().length; i++) {
			
			System.out.println((i+1) + " \t " + c.getListaItem()[i].getCodigo() + " " + c.getListaItem()[i].getNome());
			System.out.println(" \t " + c.getListaItem()[i].getQuantidade() + "x" + c.getListaItem()[i].getValorUnitario() + " \t\t\t " + c.getListaItem()[i].calculoValorTotal());
			valorTotal += c.getListaItem()[i].calculoValorTotal();
		}
		
		System.out.println("\nTOTAL R$ \t\t\t\t" + valorTotal);
		System.out.println("VALOR RECEBIDO R$ \t\t\t" + c.getDinheiroRecebido());
		System.out.println("TROCO R$ \t\t\t\t" + (c.getDinheiroRecebido()-valorTotal));
	}
	
	public void imprimirNota(CupomFiscal[] c) {
		
		for(int i=0; i<c.length; i++) {
			
			imprimirNota(c[i]);
		}
	}
}
