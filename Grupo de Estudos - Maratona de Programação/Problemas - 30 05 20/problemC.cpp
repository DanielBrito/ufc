// https://www.urionlinejudge.com.br/judge/en/problems/view/1557

#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

int countDigits(int n){

    int count = 0;

    while(n>9){

        n/=10;
        count++;
    }

    return count+1;
}

int main(){

    vector<int> dim;
    bool finish = false;
    int N, v, i, j, k, max, spaces;;

    while (!finish){

        cin >> N;

        if(N!=0) dim.push_back(N);
        else finish = true;
    }

    for (v=0; v<dim.size(); v++){

        // Find max number of the matrix:

        for (i = 1; i < pow(2, dim[v]); i *= 2){

            for (j = i; j < pow(2, dim[v]) * i; j *= 2){

                max = j;
            }
        }

        spaces = countDigits(max);

        // Print matrix with tabulation:

        for (i = 1; i < pow(2, dim[v]); i *= 2){

            for (j = i; j < pow(2, dim[v]) * i; j *= 2){

                for(k=0; k<spaces-countDigits(j); k++) printf(" ");

                cout << j << " ";
            }

            cout << "\n";
        }

        cout << "\n";
    }

    return 0;
}