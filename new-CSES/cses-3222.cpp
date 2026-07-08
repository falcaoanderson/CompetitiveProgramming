/*
04/03/26 

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

    int n, k;
    cin >> n >> k;

    int count = 0;
    vector<int> v(k);
    map<int, int> freq;    
    for(int i=0; i<k; i++){
        cin >> v[i];

        if(freq.find(v[i]) == freq.end()){
            freq[v[i]] = 1;
            count++;
        }
        else{
            freq[v[i]]++;
        }
    }
    cout << count << " ";
    for(int i=k; i<n; i++){
        int xold = v[i % k];
        cin >> v[i % k];
        int xnew = v[i % k]; 
        
        freq[xold]--;
        if(freq[xold] == 0) count--;
        
        if(freq.find(xnew) == freq.end() || freq[xnew] == 0){
            freq[xnew] = 1;
            count++;
        }
        else{
            freq[xnew]++;
        }

        cout << count << " ";
    }
    cout << endl;

    return 0;
}
