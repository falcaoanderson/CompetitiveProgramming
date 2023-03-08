// 09/10/20 // 12:00 PM //

#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
#define pb push_back
#define mp make_pair
#define int long long

const int MAXF = (1e2) + 10;

int n, k;
int freq_frutas[MAXF];
vector<pair<int, int>> arvores;

int32_t main(){
    fast_io;

    cin >> n >> k;

    for(int i=1; i<=k; i++){
        int temp;
        cin >> temp;

        freq_frutas[temp]++;
    }

    for(int i=1; i<=100; i++)
        if(freq_frutas[i]>0)
            arvores.pb(mp(i, freq_frutas[i]));

    int total = 0;
    while(n--){
        char temp;
        cin >> temp;
        int tdia = (temp=='C'? 1: -1);

        for(int i=0; i<(int)arvores.size(); i++){
            if(arvores[i].first<=0) continue;

            arvores[i].first += tdia;

            if(arvores[i].first<=0) continue;

            total += arvores[i].first*arvores[i].second;
        }
    }

    cout << total << endl;

    return 0;
}
