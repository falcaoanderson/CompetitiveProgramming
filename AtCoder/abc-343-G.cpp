/*
11/09/25 

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

int z[MAXN];

void calc_z(string s){
    memset(z, 0, sizeof(z));
    int l=0, r=0, n=SZ(s);

    for(int i=1; i<n; i++){
        if(l<i && i<=r){
            z[i] = min(z[i-l], r-i+1);
        }
        while(i+z[i]<n && s[i+z[i]] == s[z[i]]){
            z[i]++;
        }
        if(i+z[i]-1>r){
            l=i;
            r=i+z[i]-1;
        }
    }
}

int main(){
    fast_io;

    int n;
    cin >> n;

    int new_n=0;
    vector<string> s(n), new_s(n);
    vector<vector<int>> overlap(n, vector<int>(n));
    vector<bool> rmv(n);

    for(int i=0; i<n; i++){
        cin >> s[i];
    }

    for(int i=0; i<n; i++){
        if(rmv[i]) continue;

        for(int j=0; j<n; j++){
            if(i==j || rmv[j]) continue;
            
            calc_z(s[j]+s[i]);
            
            int a = SZ(s[i]), b = SZ(s[j]);

            for(int k=b; k<=a; k++){
                if(z[k]>=b){
                    rmv[j] = 1;
                    break;
                }
            }
        }
    }
    
    for(int i=0; i<n; i++){
        if(!rmv[i]) swap(s[i], new_s[new_n++]);
    }

    for(int i=0; i<new_n; i++){
        for(int j=0; j<new_n; j++){
            if(i==j) continue;
            
            calc_z(new_s[j]+new_s[i]);
            
            int a = SZ(new_s[i]), b = SZ(new_s[j]);
            
            for(int k=b; k<a+b; k++){
                if(k+z[k]==a+b){
                    overlap[i][j] = z[k];
                    break;
                }
            }
        }
    }

    vector<vector<int>> memo(new_n, vector<int>((1<<new_n), INF));

    for(int i=0; i<new_n; i++){
        memo[i][(1<<i)] = SZ(new_s[i]);        
    }
    for(int mask=3; mask<(1<<new_n); mask++){
        for(int i=0; i<new_n; i++){
            if(((1<<i)^mask)==0 || ((1<<i)&mask)==0) continue;

            for(int j=0; j<new_n; j++){
                if(i==j || ((1<<j)&mask)==0) continue;

                memo[i][mask] = min(memo[i][mask], 
                                    memo[j][mask^(1<<i)] + SZ(new_s[i]) - overlap[j][i]);
            }
        }
    }

    int resp = INF;
    for(int i=0; i<new_n; i++){
        resp = min(resp, memo[i][(1<<new_n)-1]);
    }
    cout << resp << endl;

    return 0;
}
