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

int n, k;

int main(){
    fast_io;

    cin >> n >> k;

    vector<pii> event;

    for(int i=0; i<n; i++){
        int l, r;
        cin >>  l >> r;

        event.EB(l, 0);
        event.EB(r, 1);
    }

    sort(event.begin(), event.end());

    int crr=0, last_pos;
    bool flag = 0;

    vector<int> resp;

    for(int i=0; i<2*n; i++){
        int x = event[i].FF, op=event[i].SS;

        if(event[i].SS==0){
            crr++;

            if(!flag && crr>=k){
                resp.PB(x);
                flag = 1;
            }
        }
        else{
            crr--;

            if(flag && crr<k){
                resp.PB(x);
                flag = 0;
            }
        }
    }

    cout << resp.size()/2 << endl;
    for(int i=0; i<(int)resp.size(); i+=2){
        cout << resp[i] << " " << resp[i+1] << endl;
    }

    return 0;
}
