// 09/05/2019 // 7:33 PM //

#include <iostream>

using namespace std;

#define MAXM 100

int n, total=0;
pair<int, int> botas[MAXM];

int main(){

    cin >> n;

    for(int i=0; i<n; i++){
        int tam;
        char pe;

        cin >> tam >> pe;

        if(pe=='D')
            botas[tam].second++;
        else
            botas[tam].first++;
    }

    for(int i=30; i<=60; i++)
        total += min(botas[i].first, botas[i].second);

    cout << total << "\n";

    return 0;
}
