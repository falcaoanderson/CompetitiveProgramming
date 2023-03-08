// 15/0/20 // 8:36 PM //

#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define pb push_back
#define mp make_pair

const int INF  = 0x3f3f3f3f;
const int MAXN = 1e2 + 10;

int main(){
    fastio;

    int n, total=0, melhor=-1, melhorAtual=-1;

    cin >> n;

    for(int i=0; i<n; i++){
        int temp;
        cin >> temp;

        total += temp;
        temp   = (temp? -1: 1);

        melhorAtual = max(temp, melhorAtual + temp);
        melhor      = max(melhor, melhorAtual);
    }

    cout << total+ melhor << endl;

    return 0;
}
