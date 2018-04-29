public class Exe5{
	
	public static void main(String[] args) {

		int vetor[] = new int[10];
		int i;

		for(i=0; i<vetor.length; i++){

			vetor[i] = i+i;
		}

		for(int v : vetor){

			System.out.println(v);
		}
	}
}
