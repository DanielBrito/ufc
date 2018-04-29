public class Data{

	private int dia;
	private int mes;
	private int ano;

	Data(int dia, int mes, int ano){

		if(ehValida(dia, mes, ano)){

			this.dia = dia;
			this.mes = mes;
			this.ano = ano;			
		}
		else{

			System.out.println("Data inválida!");
		}
	}

	boolean ehValida(int d, int m, int a){

		if(ano<0){

			return false;
		}

		if(m==2){

			if(d>=1 && d<=28){

				return true;
			}
			else{

				return false;
			}
		}
		else
		if(m==1 || m==3 || m==5 || m==7 || m==8 || m==10 || m==12){

			if(d>=1 && d<=31){

				return true;
			}
			else{

				return false;
			}
		}
		else
		if(m==4 || m==6 || m==9 || m==11){

			if(d>=1 && d<=30){

				return true;
			}
			else{

				return false;
			}
		}
		else{

			return false;
		}
	}

	public String toString(){

		return this.dia + "/" + this.mes + "/" + this.ano;
	}
}