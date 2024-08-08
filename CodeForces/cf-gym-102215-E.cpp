/*
07/08/24 
Problem: 
Complexity:
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
const int MAXN = (2e5) + 5;
const int MOD  = (1e9) + 7;

int main(){
    fast_io;

    int n, m;
    cin >> n >> m;

    vector<tiii> v;
    for(int i=0; i<n; i++){
        int l, r;
        cin >> l >> r;

        v.EB(l, r, i+1);
    }
    sort(v.begin(), v.end());

    int x=1, best=-INF, best_id=0;
    bool flag = 1;
    vector<int> resp;

    for(int i=0; i<n; i++){
        int l, r, id;
        tie(l, r, id) = v[i];

        if(l<=x){
            if(r>best){
                best = r;
                best_id = id;
            }

            if(i==n-1){
                if(best==m){
                    resp.PB(best_id);
                }
                else{
                    flag = 0;
                }
            }
        }
        else if(best_id==0){
            flag = 0;
            break;
        }
        else{
            resp.PB(best_id);

            if(best==m){
                break;
            }

            x = best+1;
            best_id = 0;
            i--;
        }
    }

    if(flag){
        cout << "YES" << endl;
        cout << resp.size() << endl;
        for(int x: resp) cout << x << " ";
        cout << endl;
    }
    else{
        cout << "NO" << endl;
    }

    return 0;
}
