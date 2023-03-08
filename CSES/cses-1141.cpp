// 26/10/20 // 11:19 PM //

#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
#define pb push_back
#define mp make_pair
#define ll long long
//#define int long long

typedef pair<int, int> pii;

const int INF  = 0x3f3f3f3f;
const int MAXN = (1e5) + 10;

int main(){
    fast_io;

    int n;
    cin >> n;

    set<int> seq;
    vector<int> v(n);
    unordered_map<int, int> pos;
    pos.reserve(n);

    int melhor = 0, ini=0;

    for(int i=0; i<n; i++){
        cin >> v[i];

        if(seq.find(v[i])!=seq.end()){
            for(int k=ini; k<pos[v[i]]; k++)
                seq.erase(v[k]);
            ini = pos[v[i]] + 1;

            pos[v[i]] = i;
        }
        else{
            seq.insert(v[i]);
            pos[v[i]] = i;
        }

        melhor = max(melhor, (int)seq.size());
    }

    cout << melhor << endl;

    return 0;
}

