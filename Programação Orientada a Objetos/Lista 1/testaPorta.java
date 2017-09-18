class testaPorta{
	
	public static void main(String[] args){

		Porta p = new Porta ("Branco", 2.0, 0.8, 0.05);

		p.abrir();
		p.fechar();

		p.pintar("Azul");
		p.pintar("Verde");

		p.altura = 3.0;
		p.largura = 1.0;
		p.profundidade = 0.1;

		System.out.println("Cor: " + p.cor);
		System.out.println("Altura: " + p.altura);
		System.out.println("Largura: " + p.largura);
		System.out.println("profundidade: " + p.profundidade);

		System.out.println("Aberta? " + p.estaAberta());	
	}
}