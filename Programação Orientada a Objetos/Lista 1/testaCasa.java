class testaCasa{
	
	public static void main(String[] args){

		Porta p1 = new Porta ("Azul", 2.0, 0.8, 0.05);
		Porta p2 = new Porta ("Preto", 2.0, 0.8, 0.05);
		Porta p3 = new Porta ("Vermelho", 2.0, 0.8, 0.05);

		Casa c = new Casa("Branco", 10);

		c.adicionarPorta(p1);
		c.adicionarPorta(p2);
		c.adicionarPorta(p3);

		p1.abrir();
		p2.abrir();
		p3.abrir();

		p2.fechar();

		c.pintar("Amarelo");

		System.out.println("Quantidade de portas abertas: " + c.quantasPortasEstaoAbertas());
	}
}