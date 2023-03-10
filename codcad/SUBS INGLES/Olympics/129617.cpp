#include <iostream>
#include <algorithm>
using namespace std;

#define MAXN 105

struct pais{
    int ouro;
    int prata;
    int bronze;
    int ni;
};


int ordn(pais a, pais b){
    if (a.ouro != b.ouro){
        return a.ouro>b.ouro;
    }
    else if(a.prata != b.prata){
        return a.prata>b.prata;
    }
    else if(a.bronze != b.bronze){
        return a.bronze>b.bronze;
    }
    else{
        return a.ni < b.ni;
    }
}

int main(){
    pais v[MAXN];
    int n,m;
    int ou,pr,br;

    cin >> n >> m;

    for(int i=0; i<n; i++){
        v[i].ni = i;
        v[i].ouro = 0;
        v[i].prata = 0;
        v[i].bronze = 0;
    }
    for(int i=0; i<m; i++){
        cin >> ou >> pr >> br;
        v[ou-1].ouro   += 1;
        v[pr-1].prata  += 1;
        v[br-1].bronze += 1;
    }
    sort(v, v+n, ordn);

    for(int i=0; i<n; i++){
        cout << v[i].ni + 1 << " ";
    }
    cout << endl;

    return 0;
}