package com.br.exe1;

public class CupomFiscal {
	
	// Atributos obrigatórios
	public String nomeLoja;
	public String cnpj;
	
	// Atributos opcionais
	private String cpfConsumidor;
	private String cnpjConsumidor;
	private double dinheiroRecebido;
	private Item[] listaItem = new Item[100];
	
	public String getNomeLoja() {
		
		return nomeLoja;
	}

	public String getCnpj() {
		
		return cnpj;
	}

	public String getCpfConsumidor() {
		
		return cpfConsumidor;
	}

	public String getCnpjConsumidor() {
		
		return cnpjConsumidor;
	}
	
	public double getDinheiroRecebido() {
		
		return dinheiroRecebido;
	}

	public Item[] getListaItem() {
		
		return listaItem;
	}

	private CupomFiscal(CupomFiscalBuilder builder) {
		
		this.nomeLoja = builder.nomeLoja;
		this.cnpj = builder.cnpj;
		this.cpfConsumidor = builder.cpfConsumidor;
		this.cnpjConsumidor = builder.cnpjConsumidor;
		this.dinheiroRecebido = builder.dinheiroRecebido;
		this.listaItem = builder.listaItem;
	}
	
	public static class CupomFiscalBuilder{
		
		public String nomeLoja;
		public String cnpj;
		
		private String cpfConsumidor;
		private String cnpjConsumidor;
		private double dinheiroRecebido;
		private Item[] listaItem = new Item[100];
		
		public CupomFiscalBuilder(String nomeLoja, String cnpj) {
			
			this.nomeLoja = nomeLoja;
			this.cnpj = cnpj;
		}
		
		public CupomFiscalBuilder cpfConsumidor(String cpfConsumidor) {
			
			this.cpfConsumidor = cpfConsumidor;
			return this;
		}
		
		public CupomFiscalBuilder cnpjConsumidor(String cnpjConsumidor) {
			
			this.cnpjConsumidor = cnpjConsumidor;
			return this;
		}
		
		public CupomFiscalBuilder dinheiroRecebido(double dinheiroRecebido) {
			
			this.dinheiroRecebido = dinheiroRecebido;
			return this;
		}
		
		public CupomFiscalBuilder listaItem(Item[] listaItem) {
			
			this.listaItem = listaItem;
			return this;
		}
		
		public CupomFiscal build() {
			
			return new CupomFiscal(this);
		}
	}	
}
