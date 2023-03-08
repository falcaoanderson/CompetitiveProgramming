// 25/11/20 // xx:xx PM //

#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
#define pb push_back
#define mp make_pair
#define ll long long

typedef pair<int, int> pii;

const int INF  = 0x3f3f3f3f;
const int MAXN = (2e5);

int n;
vector<tuple<int, int, int, int>> event;
ll bit[MAXN+10];

void update(int i, ll val){
    while(i<=MAXN){
        bit[i] += val;
        i += (i&-i);
    }
}
ll query(int i){
    ll sum = 0LL;
    while(i>0){
        sum += bit[i];
        i -= (i&-i);
    }
    return sum;
}

int main(){
    fast_io;

    cin >> n;

    map<int, int> compress;

    for(int i=1; i<=n; i++){
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        if(x1==x2){ // vertical
            event.pb({x1, 2, y1, y2});
        }
        else{ // horizontal
            event.pb({x1, 1, y1, y1});
            event.pb({x2, 3, y2, y2});
        }

        compress[y1] = 0;
        compress[y2] = 0;
    }

    int ii=0;
    for(auto i: compress) compress[i.first] = ++ii;
    for(int i=0; i<(int)event.size(); i++){
        get<2>(event[i]) = compress[get<2>(event[i])];
        get<3>(event[i]) = compress[get<3>(event[i])];
    }

    sort(event.begin(), event.end());

    ll resp = 0LL;

    for(auto i: event){
        int a, b, c, d;
        tie(a, b, c, d) = i;

        if(b==1) update(c, 1);
        if(b==3) update(c, -1);
        if(b==2) resp += query(d) - query(c-1);
    }
    
    cout << resp << endl;

    return 0;
}
