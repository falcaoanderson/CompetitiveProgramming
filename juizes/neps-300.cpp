// 23/10/20 // 12:35 PM //

#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
#define pb push_back
#define mp make_pair
//#define int long long

const int INF  = 0x3f3f3f3f;
const int MAXN = (1e5) + 10;

int n;
vector<int> seq;

int onda(){
    vector<int> pilha, cres(n), des(n);

    for(int i=0; i<n; i++){ // crescente
        vector<int>::iterator it = lower_bound(pilha.begin(), pilha.end(), seq[i]);

        if(it==pilha.end()){
            pilha.pb(seq[i]);
            cres[i] = pilha.size();
        }
        else{
            (*it) = seq[i];
            cres[i] = it - pilha.begin() + 1;
        }
    }
    pilha.clear();
    for(int i=n-1; i>=0; i--){ // decrescente
        vector<int>::iterator it = lower_bound(pilha.begin(), pilha.end(), seq[i]);

        if(it==pilha.end()){
            pilha.pb(seq[i]);
            des[i] = pilha.size();
        }
        else{
            (*it) = seq[i];
            des[i] = it - pilha.begin() + 1;
        }
    }

    int resp = 1;
    for(int i=0; i<n; i++)
        resp = max(resp, 2*min(cres[i], des[i])-1);

    return resp;
}

int main(){
    fast_io;

    cin >> n;
    seq.resize(n);
    for(int i=0; i<n; i++) cin >> seq[i];

    cout << onda() << endl;

    return 0;
}
