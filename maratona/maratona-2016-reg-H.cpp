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
const int MAXN = (1e5) + 5;
const int MOD  = (1e9) + 7;

int n, k;
int v[MAXN];

int main(){
    fast_io;

    cin >> n >> k;
    for(int i=0; i<n; i++){
        cin >> v[i];
    }

    priority_queue<int> pqueue;
    int resp = 0;

    for(int i=n-1; i>=0; i--){
        resp += v[i];
        pqueue.push(v[i]);

        if(((i+1)%(k+1))==0){
            resp -= pqueue.top();
            pqueue.pop();
        }
    }

    cout << resp << endl;

    return 0;
}
