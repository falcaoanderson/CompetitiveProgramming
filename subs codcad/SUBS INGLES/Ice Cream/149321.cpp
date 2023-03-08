// 12/08/19 // 1:35 PM //

#include <iostream>

using namespace std;

#define MAXN 10010

int p, s;
int praia[MAXN];
int aux[MAXN];

int main(){
    cin >> p >> s;

    for(int i=0; i<s; i++){
        int u, v;

        cin >> u >> v;

        aux[u]++;
        aux[v]--;
    }

    if(aux[0]>=1) praia[0]=1;
    for(int i=1; i<=p; i++){
        aux[i]+=aux[i-1];
        praia[i] = aux[i];
    }


    if(praia[0]>0) cout << "0 ";
    for(int i=1; i<=p; i++){
        if(praia[i]>0 && praia[i-1]==0) cout << i << " ";
        if(praia[i]==0 && praia[i-1]>0) cout << i << "\n";
    }


    return 0;
}
