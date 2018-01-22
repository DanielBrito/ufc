#include<stdio.h>
#include<stdlib.h>

#define TAM 10

//void constroi(int t, int* v);
//void peneira(int t, int* v);
void heapsort(int t, int* v);

int main(){
	
	int vetor[TAM] = {7, 9, 6, 4, 0, 2, 5, 1, 8, 3};
	int i;

	printf("Vetor desordenado:\n");

	for(i=0; i<TAM; i++){

		printf("%d ", vetor[i]);
	}

	printf("\n\n");

	heapsort(TAM, vetor);

	printf("Vetor ordenado:\n");

	for(i=0; i<TAM; i++){

		printf("%d ", vetor[i]);
	}

	printf("\n\n");

	return 0;
}


void heapsort(int t, int* v){

    int i = t/2;
    int pai, filho, x;

    while(1){

        if (i > 0){

            i--;
            x = v[i];
        } 
        else{

            t--;

            if(t == 0){

                return;
            }
              
            x = v[t];
            v[t] = v[0];
        }
          
        pai = i;
        filho = i * 2 + 1;

        while(filho < t){

            if((filho + 1 < t)  &&  (v[filho + 1] > v[filho])){

                filho++;
            }
                  
            if(v[filho] > x){

                v[pai] = v[filho];
                pai = filho;
                filho = pai * 2 + 1;
            } 
            else{

                break;
            }
        }
          
        v[pai] = x;
    }
}


/* 
    POR ALGUM MOTIVO, v[0] NÃO É COLOCADO NA SUA RESPECTIVA POSIÇÃO,
    E EM ALGUMAS EXECUÇÕES, OCORRE O ERRO "stack smashing detected":
*/

// void constroi(int t, int* v){

//     int k;

//     for(k=1; k<t; ++k){

//         int f = k+1;

//         while(f>1 && v[f/2] < v[f]){

//             troca(v[f/2], v[f]);

//             f/=2;
//         }
//     }
// }


// void peneira(int t, int* v){

//    int f=2;

//    while(f<=t){

//         if(f<t && v[f]<v[f+1]){

//             ++f;
//         }

//         if(v[f/2]>=v[f]){

//             break;
//         }

//         troca(v[f/2], v[f]);

//         f*=2;
//    }
// }


// void heapsort(int t, int* v){

//     int m;

//     constroi(t, v);

//     for(m=t; m>=2; --m){

//         troca(v[1], v[m]);

//         peneira(m-1, v);
//     }
// }