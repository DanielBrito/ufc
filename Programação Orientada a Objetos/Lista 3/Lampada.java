public class Lampada{

	private boolean estado;

	Lampada(boolean estado){

		this.estado = estado;
	}

	public String toString(){

		return "Lâmpada ligada? " + estado;
	}
}