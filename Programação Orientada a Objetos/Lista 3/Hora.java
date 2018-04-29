public class Hora{
	
	private int hora;
	private int minuto;
	private int segundo;

	Hora(int hora, int minuto, int segundo){

		if(validaHora(hora, minuto, segundo)==1){

			this.hora = hora;
			this.minuto = minuto;
			this.segundo = segundo;
		}
		else{

			System.out.println("Hora inválida!");
		}
	}

	public int validaHora(int h, int m, int s){

		if((h<0 || h>24) && (m<0 || m>60) && (s<0 || s>60)){

			return 0;
		}

		return 1;
	}

	public String toString(){

		return this.hora + "h " + this.minuto + "min " + this.segundo + "seg";
	}
}