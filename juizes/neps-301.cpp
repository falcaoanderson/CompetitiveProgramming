// 23/10/20 // 12:00 PM //

#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
#define pb push_back
#define mp make_pair
//#define int long long

const int INF  = 0x3f3f3f3f;
const int MAXN = (1e5) + 10;

int n, m;
vector<int> seq;
unordered_map<int, int> pos;

int main(){
    fast_io;

    cin >> n >> m;

    pos.reserve(n);
    for(int i=0; i<n; i++){
        int temp;
        cin >> temp;

        pos[temp] = i;
    }

    for(int i=0; i<m; i++){
        int temp;
        cin >> temp;

        if(pos.find(temp)!=pos.end())
            seq.pb(pos[temp]);
    }

    vector<int> pilha;
    for(int i=0; i<(int)seq.size(); i++){
        vector<int>::iterator it = lower_bound(pilha.begin(), pilha.end(), seq[i]);

        if(it==pilha.end())
            pilha.pb(seq[i]);
        else
            (*it) = seq[i];
    }

    cout << pilha.size() << endl;

    return 0;
}

