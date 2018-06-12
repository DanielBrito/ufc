public class AutomovelBasico extends Automovel {

	private boolean retrovisorEletrico;
	private boolean limpadorTraseiro;
	private boolean som;
	
	public AutomovelBasico(String modelo, String cor, int combustive, boolean retrovisorEletrico, boolean limpadorTraseiro, boolean som) {

		super(modelo, cor, combustive);
		this.retrovisorEletrico = retrovisorEletrico;
		this.limpadorTraseiro = limpadorTraseiro;
		this.som = som;
	}

	public double quantoCusta(){

		double acrescimo = 0;
		
		if (retrovisorEletrico) {

			acrescimo += 400;
		}

		if (limpadorTraseiro) {

			acrescimo += 200;
		}

		if (som) {

			acrescimo += 900;
		}
		
		return acrescimo += super.quantoCusta();
	}
	
	public String toString() {

		String resultado = "";

		if(retrovisorEletrico) {

			resultado = "\nRetrovisor  elétrico";
		}

		if(limpadorTraseiro) {

			resultado += "\nLimpador traseiro";
		}

		if(som) {

			resultado += "\nSom";
		}
		
		return super.toString() + resultado;
	}
}
