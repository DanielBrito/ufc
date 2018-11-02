package com.br.teste;

import java.util.Calendar;

public class PessoaFisica extends Pessoa{
	
	private String cpf;
	private Calendar dataNascimento;
	private Calendar dataAtual = Calendar.getInstance();
	
	public PessoaFisica(String nome, String cpf, Calendar dataNascimento) {
		
		super(nome);
		
		if(validarDocumento(cpf)==true) {
			
			this.cpf = cpf;
		}
		else {
			
			this.cpf = "Inválido";
		}
		
		this.dataNascimento = dataNascimento;
	}

	@Override
	public String toString() {
		
		return super.toString() + "CPF: " + cpf + "\nData de nascimento: " + dataNascimento.get(Calendar.DAY_OF_MONTH) + "/" +
		                                                                     dataNascimento.get(Calendar.MONTH) + "/" +
		                                                                     dataNascimento.get(Calendar.YEAR);
	}

	protected boolean validarDocumento(String cpf) {
		
		if(cpf.length()!=14) {
			
			return false;
		}
			
		if(!(Character.isDigit(cpf.charAt(0))) || !(Character.isDigit(cpf.charAt(1))) || !(Character.isDigit(cpf.charAt(2)))) {
			
			return false;
		}
		
		if(cpf.charAt(3)!='.' || cpf.charAt(7)!='.') {
			
			return false;
		}
		
		if(!(Character.isDigit(cpf.charAt(4))) || !(Character.isDigit(cpf.charAt(5))) || !(Character.isDigit(cpf.charAt(6)))) {
			
			return false;
		}
		
		if(!(Character.isDigit(cpf.charAt(8))) || !(Character.isDigit(cpf.charAt(9))) || !(Character.isDigit(cpf.charAt(10)))) {
			
			return false;
		}
		
		if(cpf.charAt(11)!='-') {
			
			return false;
		}
		
		if(!(Character.isDigit(cpf.charAt(12))) || !(Character.isDigit(cpf.charAt(13)))) {
			
			return false;
		}
		
		return true;
	}

	@Override
	public int calcularIdade() {
		
		return dataAtual.get(Calendar.YEAR) - dataNascimento.get(Calendar.YEAR);
	}

	public String getCpf() {
		
		return cpf;
	}

	public void setCpf(String cpf) {
		
		this.cpf = cpf;
	}

	public Calendar getDataNascimento() {
		
		return dataNascimento;
	}

	public void setDataNascimento(Calendar dataNascimento) {
		
		this.dataNascimento = dataNascimento;
	}
	
	public boolean equals(PessoaFisica pf) {
		
		return pf!=null && this.cpf.equals(pf.getCpf());
	}
}
