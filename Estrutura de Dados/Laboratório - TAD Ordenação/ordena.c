#include <stdlib.h>

void bubbleSort(int n, int* v){

    int i, j, aux;

    for(i=0; i<n; i++){

        for(j=i+1; j<n; j++){

            if(v[i]<=v[j]){

                aux = v[j];
                v[j] = v[i];
                v[i] = aux;
            }
        }
    }
}

/*
void bubbleSort(int n, int *v){

    int i, j, aux, k;
    k = n-1;

    for(i=0; i<n; i++){

        for(j=0; j<k; j++){

            if(v[j]<v[j+1]){

                aux = v[j];
                v[j] = v[j+1];
                v[j+1]=aux;
            }
        }

        k--;
    }
}
*/

void insertionSort(int n, int* v){

    int i, j, x;

    for(j=1; j<n; j++){

        x = v[j];

        for(i=j-1; i>=0 && v[i] < x; i--){

            v[i+1] = v[i];
        }

        v[i+1] = x;
    }
}

void selectionSort(int n, int* v){

    int i, j, min, x;

    for(i=0; i<n-1; i++){

        min=i;

        for(j=i+1; j<n; j++){

            if(v[j]>v[min]){

                min = j;
            }
        }

        x = v[i];
        v[i] = v[min];
        v[min] = x;
    }
}

void bubbleSortRec(int n, int* v){

    int i, j, aux;

    if(n>1){

    	for(j=0; j<n-1; j++){

        	if(v[j]>v[j+1]){

          		aux = v[j];
          		v[j] = v[j+1];
          		v[j+1]=aux;
        	}

        	bubbleSortRec(n-1, v);
     	}
    }
}

void insertionSortRec(int n, int* v){

    int i, j, x;

    if(n>1){

        insertionSortRec(n-1, v);

        x = v[n-1];

        for(i=n-2; i>=0 && v[i]>x; i--){

            v[i+1] = v[i];
        }

        v[i+1] = x;
    }
}

void selectionSortRec(int n, int* v){

    int i, x, j, min;

	if(n>1){

		min = 0;

		for(j=1; j<n; j++){

			if(v[j]<v[min]){

				min = j;
			}
		}

		x = v[min];
		v[min] = v[0];
		v[0] = x;

		selectionSortRec(n-1, v+1);
	}
}

void intercala(int p, int q, int r, int* v){

    int i, j, k, *w;

	w = malloc((r-p)*sizeof(int));

	i = p;
	j = q;
	k = 0;

	while(i<q && j<r){

		if(v[i]>v[j]){

			w[k++] = v[i++];
		}
		else{

			w[k++] = v[j++];
		}
	}

	while(i<q){

		w[k++] = v[i++];
	}

	while(j<r){

		w[k++] = v[j++];
	}

	for(i=p; i<r; i++){

		v[i] = w[i-p];
	}

	free(w);
}

void mergeSort(int n, int* v){

    int p, r, b=1;

	while(b<n){

		p=0;

		while(p+b<n){

			r = p+2*b;

			if(r>n){

				r=n;
			}

			intercala(p, p+b, r, v);

			p = p+2*b;
		}

		b = 2*b;
	}
}