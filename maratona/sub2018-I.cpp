/*
16/08/25 

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
#define sz(x) (int)(x).size()

typedef pair<int, int> pii;
typedef tuple<int, int, int> tiii;

const int INF  = 0x3f3f3f3f;
const  ll LINF = 0x3f3f3f3f3f3f3f3f;
const int MAXN = (2e5) + 5;
const int MOD  = (1e9) + 7;

vector<int> switcher[MAXN];

int main(){
    fast_io;

    int n, m;
    cin >> n >> m;

    int l;
    cin >> l;
    vector<bool> lamp(m+1);
    for(int i=0; i<l; i++){
        int x;
        cin >> x;
        lamp[x] = 1;
    }
    
    for(int i=0; i<n; i++){
        int k;
        cin >> k;

        while(k--){
            int x;
            cin >> x;
            switcher[i].PB(x);
        }
    }

    bool flag = 0;
    int resp = 0, qnt=l;

    for(int round=0; round<2 && !flag; round++){
        for(int i=0; i<n && !flag; i++){
            resp++;

            for(int x: switcher[i]){
                if(lamp[x]){
                    qnt--;
                    lamp[x]=0;
                }
                else{
                    qnt++;
                    lamp[x]=1;
                }
            }

            if(qnt==0){
                flag = 1;
                break;
            }
        }
    }

    if(flag){
        cout << resp << endl;
    }
    else{
        cout << -1 << endl;
    }


    return 0;
}
