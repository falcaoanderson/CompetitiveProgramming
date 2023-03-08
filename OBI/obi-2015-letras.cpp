// 23/10/20 // 12:17 PM //

#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
#define pb push_back
#define mp make_pair
//#define int long long

const int INF  = 0x3f3f3f3f;
const int MAXN = (1e5) + 10;

int lis(string seq){
    vector<char> pilha;

    for(int i=0; i<(int)seq.size(); i++){
        vector<char>::iterator it = upper_bound(pilha.begin(), pilha.end(), seq[i]);

        if(it==pilha.end())
            pilha.pb(seq[i]);
        else
            (*it) = seq[i];
    }

    return pilha.size();
}

int main(){
    fast_io;

    string seq;
    cin >> seq;

    cout << lis(seq) << endl;

    return 0;
}

