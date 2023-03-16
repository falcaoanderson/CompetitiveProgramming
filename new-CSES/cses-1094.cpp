#include <iostream>
#include <map>
using namespace std;

const int MAXN = 2e5+5;

int n, q;
int v[MAXN], seg[4*MAXN];

void ini(int no, int i, int j){
    int left = 2*no, right=2*no+1;

    if(i==j){
        seg[no] = v[i];
        return;
    }

    ini(left, i, (i+j)/2);
    ini(right, (i+j)/2+1, j);

    seg[no] = seg[left] + seg[right];
}

int query(int no, int i, int j, int x, int y){
    int left=2*no, right=2*no+1;

    if(x<=i && j<=y){
        return seg[no];
    }
    if(y<i || j<x){
        return 0;
    }

    return query(left, i, (i+j)/2, x, y) + query(right, (i+j)/2+1, j, x, y);
}

int main(){
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);

    cin >> n >> q;

    for(int i=1; i<=n; i++){
        cin >> v[i];
    }

    map<int, int> a;

    for(int i=1; i<=n; i++){
        if(a.find(v[i])==a.end()){
            a[v[i]] = 0;
        }
    }

    int count = 0;
    for(map<int,int>::iterator it=a.begin(); it!=a.end(); it++){
        it->second = ++count;
        cout << (it->first) << " " << (it->second) << endl;
    }

    /*
    ini(1, 1, n);

    int x, y;
    while(q--){
        cin >> x >> y;
        cout << query(1, 1, n, x, y) << endl;
    }
    */

    return 0;
}