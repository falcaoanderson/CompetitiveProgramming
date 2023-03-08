// 07/02/19 // 7:34 PM //

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define MAXN 100010

int n;
int cres[MAXN], decres[MAXN];

void lis(vector<int> v){

    vector<int> pilha;
    vector<int>::iterator it;
    int tamanho = 0;

    for(int i=0; i<v.size(); i++){

        it = lower_bound(pilha.begin(), pilha.end(), v[i]);

        if(it==pilha.end()){
            pilha.push_back(v[i]);
            tamanho++;
        }
        else
            *it = v[i];

        cres[i] = tamanho;
    }

}

void rlis(vector<int> v){

    reverse(v.begin(), v.end());
    vector<int> pilha;
    vector<int>::iterator it;

    int tamanho = 0, vsize=v.size();

    for(int i=0; i<vsize; i++){

        it = lower_bound(pilha.begin(), pilha.end(), v[i]);

        if(it==pilha.end()){
            pilha.push_back(v[i]);
            tamanho++;
        }
        else
            *it = v[i];

        decres[vsize-1-i] = tamanho;
    }

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> v;

    cin >> n;

    for(int i=0; i<n; i++){
        int a;
        cin >> a;

        v.push_back(a);
    }

    lis(v);
    rlis(v);

    int maior =0;
    for(int i=0; i<v.size(); i++){
        maior = max(maior, min(cres[i],decres[i])*2-1);
    }
    cout << maior;

    return 0;
}
