class Porta{
	
	String cor;
	double altura;
	double largura;
	double profundidade;
	boolean aberta;

	Porta(String cor, double altura, double largura, double profundidade){

		this.cor = cor;
		this.altura = altura;
		this.largura = largura;
		this.profundidade = profundidade;
	}

	boolean abrir(){

		if(aberta){

			return false;
		}
		else{

			aberta = true;
			return true;
		}
	}

	boolean fechar(){

		if(!aberta){

			return false;
		}
		else{

			aberta = false;
			return true;
		}
	}

	boolean estaAberta(){

		return aberta;
	}

	void pintar(String cor){

		this.cor = cor;
	}
}