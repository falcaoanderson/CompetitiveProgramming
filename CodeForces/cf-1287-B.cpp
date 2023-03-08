// 17/01/20 // 10:07 PM //

#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define pb push_back
#define mp make_pair

const int INF  = 0x3f3f3f3f;
const int MAXN = 1e3 + 510;

int n, k;
set< string > deck;
string v[MAXN];

int main(){
    fastio;

    cin >> n >> k;

    for(int i=1; i<=n; i++){
        cin >> v[i];

        deck.insert(v[i]);
    }

    int resp = 0;

    for(int i=1; i<=n; i++){
        for(int j=i+1; j<=n; j++){
            string temp="";

            for(int l=0; l<k; l++){
                if(v[i][l]==v[j][l])
                    temp += v[i][l];
                else if((v[i][l]=='S' && v[j][l]=='E') || (v[i][l]=='E' && v[j][l]=='S'))
                    temp += 'T';
                else if((v[i][l]=='S' && v[j][l]=='T') || (v[i][l]=='T' && v[j][l]=='S'))
                    temp += 'E';
                else if((v[i][l]=='E' && v[j][l]=='T') || (v[i][l]=='T' && v[j][l]=='E'))
                    temp += 'S';

            }

            resp += (deck.find(temp)!=deck.end());
        }
    }

    cout << resp/3 << endl;

    return 0;
}
