public class Exe6{
	
	public static void main(String[] args) {

		int[][] tabuada = new int[10][10];
		int i, j;

		for(i=0; i<10; i++){

			System.out.println("TABUADA " + (i+1) + "\n");

			for (j=0; j<10; j++){

				tabuada[i][j] = (i+1)+j;

				System.out.println((i+1) + " + " + j + " = " + tabuada[i][j]);				
			}

			System.out.println();
		}
	}
}
