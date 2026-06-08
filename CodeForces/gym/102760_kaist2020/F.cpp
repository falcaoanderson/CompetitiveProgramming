/*
20/01/26

*/

#include <bits/stdc++.h>

using namespace std;

#define fast_io ios_base::sync_with_stdio(false);cin.tie(nullptr)
#define endl "\n"
#define FF first
#define SS second
#define PB push_back
#define EB emplace_back

using ll = long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;

const int MAXN = 3e5 + 5;

int n, v[MAXN];
deque<ll> mq;

void add_mq(ll x){
    while(!mq.empty() && x < mq.back()){
        mq.pop_back();
    }

    mq.push_back(x);
}
ll front_mq(){
    return mq.front();
}
void pop_mq(ll x){
    if(!mq.empty() && mq.front() == x)
        mq.pop_front();
}

bool check(int l){
    mq.clear();

    for(int i=1; i<=l; i++){
        add_mq(v[i]);
    }

    bool resp = (front_mq() >= l);

    for(int i=l+1; i<=n && !resp; i++){
        pop_mq(v[i-l]);
        add_mq(v[i]);

        resp = (front_mq() >= l);
    }

    return resp;
}

int main(){
    fast_io;

    cin >> n;
    
    for(int i=1; i<=n; i++){
        cin >> v[i];
    }

    int l=2, r=3e5;
    int resp = 1;

    while(l<=r){
        int mid = (l+r) / 2;

        if(check(mid)){
            resp = mid;
            l = mid+1;
        }
        else{
            r = mid-1;
        }
    }

    cout << resp << endl;

    return 0;
}