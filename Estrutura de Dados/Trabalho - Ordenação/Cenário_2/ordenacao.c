#include <stdlib.h>

void troca(int* x, int* y){

    int temp = *x;
    *x = *y;
    *y = temp;
}

/* BubbleSort crescente */

void bubbleSort(int* v, int n, long long int *comp, long long int *troc){

	int i, j;

	for(i=n-1; i>0; i--){

		int ordenado = 0;

		for(j=0; j<i; j++){

			++(*comp);

			if(v[j]>v[j+1]){

				troca(&v[j], &v[j+1]);
				++(*troc);

				ordenado = 1;
			}
		}

		if(ordenado==0){

			return;
		}
	}
}

/* SelectionSort crescente */

void selectionSort(int* v, int n, long long int *comp, long long int *troc){

	int i, x, j, min;

	for(i=0; i<n; i++){

		min = i;

		for(j=i+1; j<n; j++){

			++(*comp);

			if(v[j]<v[min]){

				min = j;
			}
		}

		x = v[min];
		v[min] = v[i];
		v[i] = x;

		++(*troc);
	}
}

/* InsertionSort crescente */

void insertionSort(int* v, int n, long long int *comp, long long int *troc){

	int i, j, x;

	for(j=1; j<n; j++){

		x = v[j];

		for(i=j-1; i>=0 && v[i]>x; i--){

			++(*comp);
			v[i+1] = v[i];
			++(*troc);
		}

		v[i+1] = x; 
		++(*troc);
	}
}

/* MergeSort crescente */

void intercala(int p, int q, int r, int* v, long long int *comp, long long int *troc){

	int i, j, k, *w;

	w = malloc((r-p)*sizeof(int));

	i = p;
	j = q;
	k = 0;

	while(i<q && j<r){

		++(*comp);

		if(v[i]<=v[j]){

			w[k++] = v[i++]; 
			++(*troc);
		}
		else{

			w[k++] = v[j++]; 
			++(*troc);
		}
	}

	while(i<q){

		w[k++] = v[i++]; 
		++(*troc);
	}

	while(j<r){

		w[k++] = v[j++]; 
		++(*troc);
	}

	for(i=p; i<r; i++){

		v[i] = w[i-p]; 
		++(*troc);
	}

	free(w);
}


void mergeSort(int* v, int n, long long int *comp, long long int *troc){

	int p, r;
	int b=1;

	while(b<n){

		p=0;

		while(p+b<n){

			r = p+2*b;

			if(r>n){

				r=n;
			}

			intercala(p, p+b, r, v, comp, troc);

			p = p+2*b;
		}

		b = 2*b;
	}
}

/* QuickSort crescente */

int separa(int p, int r, int* v, long long int *comp, long long int *troc){

    int c, j, k, t;
    c = v[r];
    j = p;

    for(k=p; k<r; k++){

		++(*comp);

        if(v[k]<=c){

            troca(&v[j], &v[k]);
            ++(*troc);

            j++;
        }
    }

    v[r] = v[j]; 
    ++(*troc);

    v[j] = c; 
    ++(*troc);

    return j;
}

void quickSort(int p, int r, int* v, long long int *comp, long long int *troc){

    int j;

    if(p<r){

        j = separa(p, r, v, comp, troc);
        quickSort(p, j-1, v, comp, troc);
        quickSort(j+1, r, v, comp, troc);
    }
}

/* HeapSort crescente */

void constroi(int* v, int t, int i, long long int *comp, long long int *troc){

    int max = i;
    int esq = 2*i+1;
    int dir = 2*i+2;

    if(esq<t && v[esq]>v[max]){

		++(*comp);

        max = esq;
    }

    if(dir<t && v[dir]>v[max]){

		++(*comp);

        max = dir;
    }

    if(max!=i){

        troca(&v[i], &v[max]);
        ++(*troc);

        constroi(v, t, max, comp, troc);
    }
}

void peneira(int* v, int t, long long int *comp, long long int *troc){

    int i;

    for(i=(t/2)-1; i>=0; i--){

        constroi(v, t, i, comp, troc);
    }
}

void heapSort(int* v, int t, long long int *comp, long long int *troc){

    int i;

    peneira(v, t, comp, troc);

    for(i=t-1; i>=0; i--){

        troca(&v[0], &v[i]);

        int heapTam = i;

        constroi(v, heapTam, 0, comp, troc);
    }
}