public class Data{

	private int dia;
	private int mes;
	private int ano;

	Data(int dia, int mes, int ano){

		if(ehValida(dia, mes, ano)==true){

			this.dia = dia;
			this.mes = mes;
			this.ano = ano;
		}
		else{

			System.out.println("Data inválida!");
		}
	}

	public boolean ehValida(int d, int m, int a){

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

	public boolean ehIgual(Data outraData){

		if(ehValida(outraData.dia, outraData.mes, outraData.ano)){

			if((this.dia==outraData.dia)&&(this.mes==outraData.mes)&&(this.ano==outraData.ano)){

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

	public void copiaData(Data outraData){

		this.dia = outraData.dia;
		this.mes = outraData.mes;
		this.ano = outraData.ano;
	}

	public void mostraData(){

		if(mes==1) System.out.println(dia + " de Janeiro de " + ano);
		if(mes==2) System.out.println(dia + " de Fevereiro de " + ano);
		if(mes==3) System.out.println(dia + " de Março de " + ano);
		if(mes==4) System.out.println(dia + " de Abril de " + ano);
		if(mes==5) System.out.println(dia + " de Maio de " + ano);
		if(mes==6) System.out.println(dia + " de Junho de " + ano);
		if(mes==7) System.out.println(dia + " de Julho de " + ano);
		if(mes==8) System.out.println(dia + " de Agosto de " + ano);
		if(mes==9) System.out.println(dia + " de Setembro de " + ano);
		if(mes==10) System.out.println(dia + " de Outubro de " + ano);
		if(mes==11) System.out.println(dia + " de Novembro de " + ano);
		if(mes==12) System.out.println(dia + " de Dezembro de " + ano);
	}
}