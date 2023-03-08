// 00/00/20 // 00:00 XX //

#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define pb push_back
#define mp make_pair
#define ff first
#define ss second

const int INF = 0x3f3f3f3f;
const int MAXN = 1e5 + 10;

vector<char> aux = {'a', 'b', 'c'};

void solve(){
    string seq;
    cin >> seq;

    for(int i=0; i<(int)seq.size(); i++)
        if(seq[i]==seq[i+1] && seq[i]!='?'){
            cout << "-1\n";
            return;
        }

    if(seq[0]=='?')
        for(char  c : aux)
            if(seq.size()==1 || c!=seq[1])
                seq[0] = c;

    for(int i=1; i<(int)seq.size()-1; i++)
        if(seq[i]=='?')
            for(char c : aux)
                if(c!=seq[i-1] && c!=seq[i+1]){
                    seq[i] = c;
                    break;
                }
    if(seq[seq.size()-1]=='?')
        for(char  c : aux)
            if(seq.size()==1 || c!=seq[seq.size()-2])
                seq[seq.size()-1] = c;

    cout << seq << endl;
}

int main(){
    fastio;

    int t;
    cin >> t;

    while(t--) solve();

    return 0;
}
