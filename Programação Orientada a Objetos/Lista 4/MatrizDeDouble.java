public class MatrizDeDouble{
		
	int linhas;
	int colunas;
	double[][] matriz;

	MatrizDeDouble(int linhas, int colunas){

		matriz = new double[linhas][colunas];

		this.linhas = linhas;
		this.colunas = colunas;

		preencheMatriz(0.0);
	}

	public void preencheMatriz(double valor){

		int i, j;

		for(i=0; i<linhas; i++){

			for(j=0; j<colunas; j++){

				matriz[i][j] = valor;
			}
		}
	}

	public double maiorValor(){

		double maior = matriz[0][0];
		int i, j;

		for(i=0; i<linhas; i++){

			for(j=0; j<colunas; j++){

				if(matriz[i][j]>maior){

					maior = matriz[i][j];
				}
			}
		}

		return maior;
	}

	public String toString(){

		int i, j;
		String mat="";

		for(i=0; i<linhas; i++){

			for(j=0; j<colunas; j++){

				mat = mat + "[" + matriz[i][j] + "] "; 
			}

			mat = mat + "\n";
		}

	return mat;

	}
}