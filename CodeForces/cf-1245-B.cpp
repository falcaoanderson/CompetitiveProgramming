// 00/01/20 // 00:00 XM //

#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define pii pair<int,int>

const int INF = 0x3f3f3f3f;
const int MAXN = (int)(1e5) + 10;

void solve(){
    int n, a, b, c;
    string seq;

    cin >> n >> a >> b >> c >> seq;

    int win = 0;
    vector<char> resp(n);

    for(int i=0; i<n; i++){
        if(seq[i]=='R' && b>0){
            win++;
            b--;
            resp[i]='P';
        }
        if(seq[i]=='P' && c>0){
            win++;
            c--;
            resp[i]='S';
        }
        if(seq[i]=='S' && a>0){
            win++;
            a--;
            resp[i]='R';
        }
    }

    for(int i=0; i<n; i++){
        if(resp[i]==0){
            if(b>0){
                b--;
                resp[i]='P';
            }
            else if(c>0){
                c--;
                resp[i]='S';
            }
            else{
                a--;
                resp[i]='R';
            }
        }
    }

    if(win<n-win)
        cout << "NO\n";
    else{
        cout << "YES\n";

        for(char c : resp) cout << c;
        cout << endl;
    }
}

int main(){
    fastio;

    int t;
    cin >> t;
    while(t--) solve();

    return 0;
}
