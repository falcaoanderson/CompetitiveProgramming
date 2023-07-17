#include <bits/stdc++.h>
 
using namespace std;
 
#define PB push_back
#define EB emplace_back
#define endl "\n"
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
 
    int dest, muro, martelo;
    cin >> dest >> muro >> martelo;
 
    if(0<muro && muro<dest && muro<martelo){
        cout << -1 << endl;
    }
    else if(0>muro && muro>dest && muro>martelo){
        cout << -1 << endl;
    }
    else if((0<muro && dest<muro) || (0>muro && dest>muro)){
        cout << abs(dest) << endl;
    }
    else{
        cout << abs(martelo) + abs(dest-martelo) << endl;
    }
 
 
 
    return 0;
}