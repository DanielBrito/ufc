class Casa{
	
	String cor;
	Porta[] portas;
	int totalDePortas;
	
	Casa(String cor, int qtdPortas){

		this.cor = cor;
		portas = new Porta[qtdPortas];
	}

	void pintar(String cor){

		this.cor = cor;
	}

	void adicionarPorta(Porta porta){

		portas[totalDePortas++] = porta;
	}

	int totalDePortas(){

		return totalDePortas;
	}

	int quantasPortasEstaoAbertas(){

		int cont = 0;

		for(int i=0; i<totalDePortas; i++){

			if(portas[i].estaAberta()){

				cont++;
			}
		}

		return cont;
	}
}