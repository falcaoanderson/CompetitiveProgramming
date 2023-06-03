// 03/06/23 // union-find
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <tuple>
#include <cstring>

using namespace std;

#define ll long long
#define endl "\n"
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
#define PB push_back
#define EB emplace_back
#define ff first
#define ss second

typedef pair<int, int> pii;
typedef tuple<int, int, int> tiii;

const int MAXN = (1e5) + 5;

int n, m;
int pai[MAXN], tam[MAXN], dist[MAXN];

int find(int a){
    if(pai[a] == a) return a;

    return pai[a] = find(pai[a]);
}

void join(int a, int b){
    a = find(a);
    b = find(b);

    if(a==b) return;

    n--;

    if(dist[a] < dist[b]){
        pai[a] = b;
        tam[b] += tam[a];
    }
    else if(dist[a] > dist[b]){
        pai[b] = a;
        tam[a] += tam[b];
    }
    else{
        pai[a] = b;
        tam[b] += tam[a];
        dist[b]++;
    }
}

int main(){
    fast_io;

    cin >> n >> m;
    
    for(int i=1; i<=n; i++){
        pai[i] = i;
        tam[i] = 1;
    }

    int big=1;

    while(m--){
        int a, b;
        cin >> a >> b;

        join(a, b);

        big = max(big, tam[find(a)]);

        cout << n << " " << big << endl;
    }

    return 0;
}
