package com.br.exe5;

public class ImagemProxy implements Imagem {
	
	private ImagemReal imagemReal;
	private String arquivo;
	
	public ImagemProxy(String arquivo) {
		
		this.arquivo = arquivo;
	}

	@Override
	public void exibir() {
		
		if(imagemReal==null) {
			
			imagemReal = new ImagemReal(arquivo);
		}
		
		imagemReal.exibir();
	}
}
