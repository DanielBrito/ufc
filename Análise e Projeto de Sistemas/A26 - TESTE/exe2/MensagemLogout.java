package com.br.exe2;

public abstract class MensagemLogout {
	
	private String logo;
	private String mensagem;
	
	public MensagemLogout(String logo, String mensagem) {
		
		this.logo = logo;
		this.mensagem = mensagem;
	}

	public String getLogo() {
		
		return logo;
	}

	public void setLogo(String logo) {
		
		this.logo = logo;
	}

	public String getMensagem() {
		
		return mensagem;
	}

	public void setMensagem(String mensagem) {
		
		this.mensagem = mensagem;
	}
	
	public abstract void mostrarTelaGrafica();
}
