// 00/00/20 // 00:00 XX //

#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define pb push_back
#define mp make_pair

const int INF = 0x3f3f3f3f;
const int MAXN = 1e5 + 10;

int main(){
    fastio;

    int t;
    cin >> t;

    while(t--){
        string frase, suffix="";
        cin >> frase;

        for(int i=frase.size()-1; i>=0; i--){
            suffix = frase[i] + suffix;

            if(suffix=="po"){
                cout << "FILIPINO" << endl;
                break;
            }
            else if(suffix == "desu" || suffix == "masu"){
                cout << "JAPANESE" << endl;
                break;
            }
            else if(suffix == "mnida"){
                cout << "KOREAN" << endl;
                break;
            }
        }
    }

    return 0;
}
