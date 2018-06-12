public class AutomovelLuxo extends AutomovelBasico {
	
	
	private boolean direcaoEletrica;
	private boolean automatico;
	private boolean vidroTravaEletricos;
	public static final int qtdPresatcoes = 24;
	
	public AutomovelLuxo(String modelo, String cor, int combustive, boolean retrovisorEletrico, boolean limpadorTraseiro, boolean som, boolean direcaoEletrica, boolean automatico , boolean vidroTravaEletricos) {
		
		super(modelo, cor, combustive, retrovisorEletrico, limpadorTraseiro, som);
		this.direcaoEletrica = direcaoEletrica;
		this.automatico = automatico;
		this.vidroTravaEletricos = vidroTravaEletricos;
		
	}
	
	@Override
	public double quantoCusta() {
		
		double acrescimo = 0;
		
		if (direcaoEletrica) {

			acrescimo += 250;
		}

		if (automatico) {

			acrescimo += 120;
		}

		if (vidroTravaEletricos) {

			acrescimo += 1000;
		}
		
		return acrescimo += super.quantoCusta();		
	}
	
	@Override
	public int quantasPrestacoes() {

		return qtdPresatcoes;
	}
	
	@Override
	public String toString(){

		String resultado = "";

		if(direcaoEletrica){

			resultado += "\nDireção elétrica";
		}

		if(automatico){

			resultado += "\nAutomático";
		}

		if(vidroTravaEletricos){

			resultado += "\nVidro com trava elétrica";
		}

		return super.toString() + resultado;
	}
	
}
