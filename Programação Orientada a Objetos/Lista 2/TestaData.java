public class TestaData{

	public static void main(String[] args) {
		
		Data niver = new Data(4,1,2018);
		Data natal = new Data(25,12,2018);
		Data data = new Data(10,10,2010);
		Data copia = new Data(1,1,1);

		System.out.print("Data: ");
		data.mostraData();

		System.out.print("Aniversário: ");
		niver.mostraData();

		System.out.print("Natal: ");
		natal.mostraData();

		copia.copiaData(data);

		System.out.print("Cópia da Data: ");
		copia.mostraData();

		if(niver.ehIgual(natal)){

			System.out.println("Datas iguais!");
		}
		else{

			System.out.println("Datas diferentes!");
		}
	}
}