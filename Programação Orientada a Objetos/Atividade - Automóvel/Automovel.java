class Automovel {

	String modelo;
	String cor;
	int combustivel;
	
	public static final int GASOLINA = 1;
	public static final int ALCOOL = 2;
	public static final int DIESEL = 3;
	public static final int GAS = 4;
	public static final int NUM_MAXIMO_PRESTACOES = 24;
	
	public Automovel(String modelo, String cor, int combustivel ) {

		this.modelo = modelo;
		this.cor = cor;
		this.combustivel = combustivel;
	}
	
	public double quantoCusta(){
		
		double preco = 0.0;
		
		switch(combustivel){

			case GASOLINA:
				preco = 20000; break;

			case ALCOOL:
				preco = 22000; break;

			case DIESEL: 
				preco = 27000; break;

			case GAS:
				preco = 23000; break;
		}		
		
		return preco ;
	}
	
	public int quantasPrestacoes(){

		return NUM_MAXIMO_PRESTACOES ;
	}
	
	public String toString(){
		
		return "\nCor: " + cor + "\nModelo: " + modelo + "\nTipo de combustível: " + combustivel;
	}
}