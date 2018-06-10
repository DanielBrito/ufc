int separa(int p, int r, int* v, int* comp){

    int c, j, k, t;
    c = v[r];
    j = p;

    for(k=p; k<r; k++){

        ++(*comp);

        if(v[k]<=c){

            t = v[j];
            v[j] = v[k];
            v[k] = t;
            j++;
        }
    }

    v[r] = v[j];
    v[j] = c;

    return j;
}

void quickSort(int p, int r, int* v, int* comp){

    int j;

    if(p<r){

        j = separa(p, r, v, comp);
        quickSort(p, j-1, v, comp);
        quickSort(j+1, r, v, comp);
    }
}
