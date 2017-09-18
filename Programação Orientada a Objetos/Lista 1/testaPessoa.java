class testaPessoa{
	
	public static void main(String[] args){

		Pessoa p = new Pessoa ("João", 17);

		p.fazAniversario();

		System.out.println("Nome: " + p.nome);
		System.out.println("Idade: " + p.idade);
	}	
}