#include<iostream>
#include<vector>

using namespace std;

int main(){

    int n, x;
    vector<int> v;

    int sum = 0;

    cin >> n;

    while(n--){

        cin >> x;
        v.push_back(x);
    }

    for(int i=0; i<v.size(); i++){

        sum += v[i];
    }

    cout << sum;

    return 0;
}
