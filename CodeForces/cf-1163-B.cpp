/*
29/07/25 

*/

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl "\n"
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
#define PB push_back
#define EB emplace_back
#define FF first
#define SS second
#define sz(x) (int)(x).size()

typedef pair<int, int> pii;
typedef tuple<int, int, int> tiii;

const int INF  = 0x3f3f3f3f;
const  ll LINF = 0x3f3f3f3f3f3f3f3f;
const int MAXN = (1e5) + 5;
const int MOD  = (1e9) + 7;

int freq[MAXN], freqfreq[MAXN];

int main(){
    fast_io;

    int n;
    cin >> n;

    int count = 0, resp=1;

    for(int i=0; i<n; i++){
        int x;
        cin >> x;

        if(freq[x]>0){
            freqfreq[freq[x]]--;
        
            if(freqfreq[freq[x]]==0){
                count--;
            }
        }
        freq[x]++;
        if(freqfreq[freq[x]]==0){
            count++;
        }
        freqfreq[freq[x]]++;

        if(count==1 && freqfreq[1]==i+1){ // todos sao diferentes
            resp = i+1;
        }
        else if(count==1 && freq[x]==i+1){ // todos sao iguais
            resp = i+1;
        }
        else if(count==2 && freqfreq[1]==1){ // um unico numero diferente
            resp = i+1;
        }
        else if(count==2 && freqfreq[freq[x]+1]==1){ // o grupo diferente execede em uma unidade na frequencia
            resp = i+1;
        }
        else if(count==2 && freqfreq[freq[x]-1]>0 && freqfreq[freq[x]]==1){ // o mesmo
            resp = i+1;
        }
    }

    cout << resp << endl;
    
    return 0;
}
