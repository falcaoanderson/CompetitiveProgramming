// 07/02/19 // 8:35 PM //

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define MAXN 1000010

int n, m;
int  sm[MAXN];
pair<int, int> sn[MAXN]; // first = valor // second = index //
vector<int> seq;

int buscab(int x){
    int inicio=1;
    int fim = n;
    int meio=0;

    while(inicio<=fim){
        meio = (inicio+fim)/2;

        if(sn[meio].first==x) return sn[meio].second;

        else if(sn[meio].first > x) fim = meio -1;
        else if(sn[meio].first < x) inicio = meio + 1;
    }

    return -1;
}

int lis(vector<int> v){

    vector<int> pilha;
    vector<int>::iterator it;

    for(int i=0; i<v.size(); i++){

        it = lower_bound(pilha.begin(), pilha.end(), v[i]);

        if(it==pilha.end())
            pilha.push_back(v[i]);
        else
            *it = v[i];
    }

    return pilha.size();
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    for(int i=1; i<=n; i++){
        cin >> sn[i].first;
        sn[i].second = i;
    }
    for(int i=1; i<=m; i++){
        cin >> sm[i];
    }

    sort(sn+1, sn+n+1);

    for(int i=1; i<=m; i++){
        int a = buscab(sm[i]);

        if(a==-1) continue;

        seq.push_back(a);
    }

    cout << lis(seq) << "\n";

    return 0;
}

