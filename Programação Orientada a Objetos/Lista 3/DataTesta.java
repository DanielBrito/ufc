public class DataTesta{

	public static void main(String[] args) {
		
		Data niver = new Data(4,1,2018);
		Data natal = new Data(25,12,2018);

		niver.inicializaData(4,1,2018);
		natal.inicializaData(25,12,2018);

		System.out.print("Aniversário: ");
		niver.mostraData();

		System.out.print("Natal: ");
		natal.mostraData();

		if(niver.ehIgual(natal)){

			System.out.println("Datas iguais!");
		}
		else{

			System.out.println("Datas diferentes!");
		}
	}
}