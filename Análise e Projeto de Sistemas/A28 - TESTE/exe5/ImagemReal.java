package com.br.exe5;

public class ImagemReal implements Imagem{
	
	private String arquivo;
	
	public ImagemReal(String arquivo) {
		
		this.arquivo = arquivo;
		carregarDoDisco(arquivo);
	}

	@Override
	public void exibir() {

		System.out.println("Exibindo: " + arquivo);
	}
	
	private void carregarDoDisco(String arquivo) {
		
		System.out.println("Carregando: " + arquivo);
	}
}
