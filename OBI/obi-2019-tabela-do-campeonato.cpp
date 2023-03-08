// 09/10/20 // 2:46 PM //

#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)

const int MAXN = (1e5) + 10;

int main(){
    fast_io;

    int j, p, v, e, d;
    cin >> j >> p >> v >> e >> d;

    if(j==-1 && p==-1){
        j = v+e+d;
    }
    if(j==-1 && v==-1){
        j = (p-e)/3 + e + d;
    }
    if(j==-1 && e==-1){
        j = v + (p-3*v) + d;
    }
    if(j==-1 && d==-1){
        //d = j - v - e
    }
    if(p==-1 && v==-1){
        v = j -e - d;
    }
    if(p==-1 && e==-1){
        e = j - v - d;
    }
    if(p==-1 && d==-1){
        d = j-v-e;
    }
    if(v==-1 && e==-1){
        v = (p-j+d)/2;
    }
    if(v==-1 && d==-1){
        v = (p-e)/3;
    }
    if(e==-1 && d==-1){
        e = p-3*v;
    }

    if(j==-1){
        if(v==-1) v = (p-e)/3;
        if(e==-1) e = p - 3*v;
        j = v+e+d;
    }
    if(p==-1){
        if(v==-1) v = j-e-d;
        if(e==-1) e = j-v-d;
        p = 3*v+e;
    }
    if(v==-1){
        v = j-e-d;
    }
    if(e==-1) e = p-3*v;
    if(d==-1) d = j-v-e;

    cout << j << " " << p << " " << v << " " << e <<" "<< d;

    return 0;
}


