/*
22/08/25 

*/

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define endl "\n"
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
#define PB push_back
#define EB emplace_back
#define FF first
#define SS second
#define SZ(x) (int)(x).size()

typedef pair<int, int> pii;
typedef tuple<int, int, int> tiii;

const int INF  = 0x3f3f3f3f;
const  ll LINF = 0x3f3f3f3f3f3f3f3f;
const int MAXN = (2e5) + 5;
const int MOD  = (1e9) + 7;

int main(){
    fast_io;

    string s;
    cin >> s;
    int n = SZ(s);

    vector<int> freq(26);
    int maxfreq=0, id_maxfreq=0;

    for(char c: s){
        freq[c-'A']++;
        
        if(maxfreq<freq[c-'A']){
            maxfreq = freq[c-'A'];
            id_maxfreq = c-'A';
        }
    }

    if(maxfreq > n-maxfreq+1){
        cout << -1 << endl;
        return 0;
    }

    vector<int> resp(n);
    for(int i=0; i<n-2*maxfreq+1; i++){
        int f=-1, s=-1;
        for(int j=0; j<26; j++){
            if(freq[j]>0){
                if(f==-1){
                    f = j;
                }
                else{
                    s = j;
                    break;
                }
            }
        }

        int op = 0;
        if(i==0 || resp[i-1]!=f) op = f;
        else op = s;
        resp[i] = op;
        freq[op]--;

        if(op!=id_maxfreq) continue;

        maxfreq=0, id_maxfreq=0;
        for(int j=0; j<26; j++){
            if(maxfreq<freq[j]){
                maxfreq = freq[j];
                id_maxfreq = j;
            }
        }
    }

    for(int i=n-2*maxfreq+1; i<n; i++){
        if(i%2==(n-2*maxfreq+1)%2){
            resp[i] = id_maxfreq;
            continue;
        }

        int f=-1;
        for(int j=0; j<26 && f==-1; j++){
            if(j!=id_maxfreq && freq[j]>0){
                f = j;
                freq[j]--;
            }
        }
        resp[i] = f;
    }

    for(int x: resp) cout << (char)(65+x);
    cout << endl;


    return 0;
}
