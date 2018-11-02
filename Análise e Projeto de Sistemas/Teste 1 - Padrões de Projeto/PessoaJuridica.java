package com.br.teste;

import java.util.Calendar;

public class PessoaJuridica extends Pessoa {
	
	private String cnpj;
	private Calendar dataCriacao;
	private Calendar dataAtual = Calendar.getInstance();
	
	public PessoaJuridica(String nome, String cnpj, Calendar dataCriacao) {
		
		super(nome);
		
		if(validarDocumento(cnpj)==true) {
			
			this.cnpj = cnpj;
		}
		else {
			
			this.cnpj = "Inválido";
		}
		
		this.dataCriacao = dataCriacao;
	}
	
	@Override
	public String toString() {
		
		return super.toString() + "CNPJ: " + cnpj + "\nData de criação: " + dataCriacao.get(Calendar.DAY_OF_MONTH) + "/" +
                                                                            dataCriacao.get(Calendar.MONTH) + "/" +
                                                                            dataCriacao.get(Calendar.YEAR);		
	}
	
	protected boolean validarDocumento(String cnpj) {
		
		if(cnpj.length()!=18) {
			
			return false;
		}
		
		if(!(Character.isDigit(cnpj.charAt(0))) || !(Character.isDigit(cnpj.charAt(1)))) {
			
			return false;
		}
		
		if(cnpj.charAt(2)!='.' || cnpj.charAt(6)!='.') {
			
			return false;
		}
		
		if(!(Character.isDigit(cnpj.charAt(3))) || !(Character.isDigit(cnpj.charAt(4))) || !(Character.isDigit(cnpj.charAt(5)))) {
			
			return false;
		}
		
		if(!(Character.isDigit(cnpj.charAt(7))) || !(Character.isDigit(cnpj.charAt(8))) || !(Character.isDigit(cnpj.charAt(9)))) {
			
			return false;
		}
		
		if(cnpj.charAt(10)!='/') {
			
			return false;
		}
		
		if(!(Character.isDigit(cnpj.charAt(11))) || !(Character.isDigit(cnpj.charAt(12))) || !(Character.isDigit(cnpj.charAt(13))) || !(Character.isDigit(cnpj.charAt(14)))) {
			
			return false;
		}
		
		if(cnpj.charAt(15)!='-') {
			
			return false;
		}
		
		if(!(Character.isDigit(cnpj.charAt(16))) || !(Character.isDigit(cnpj.charAt(17)))) {
			
			return false;
		}
		
		return true;
	}
	
	@Override
	public int calcularIdade() {
		
		return dataAtual.get(Calendar.YEAR) - dataCriacao.get(Calendar.YEAR);
	}

	public Calendar getDataCriacao() {
		
		return dataCriacao;
	}

	public void setDataCriacao(Calendar dataCriacao) {
		
		this.dataCriacao = dataCriacao;
	}

	public String getCnpj() {
		
		return cnpj;
	}

	public void setCnpj(String cnpj) {
		
		this.cnpj = cnpj;
	}
	
	public boolean equals(PessoaJuridica pj) {
		
		return pj!=null && this.cnpj.equals(pj.getCnpj());
	}
}
