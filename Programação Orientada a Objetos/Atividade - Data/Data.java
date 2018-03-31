public class Data{

	private int dia;
	private int mes;
	private int ano;

	void inicializaData(int d, int m, int a){

		if(ehValida(d, m, a)){

			dia = d;
			mes = m;
			ano = a;
		}
		else{

			dia = 0;
			mes = 0;
			ano = 0;
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

	boolean ehIgual(Data outraData){

		if((this.dia==outraData.dia)&&(this.mes==outraData.mes)&&(this.ano==outraData.ano)){

			return true;
		}
		else{

			return false;
		}
	}

	void mostraData(){

		System.out.println("%d/%d/%d\n", this.dia, this.mes, this.ano);
	}
}