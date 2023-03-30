// 30/03/23 //
// brute force para testa a ideia // <- nao funciona
#include <iostream>
#include <vector>
#include <algorithm>
 
using namespace std;
 
#define endl "\n"

typedef long long ll;

inline int abs(int a){
    return (a>0 ? a: -a);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    
    vector<ll> v(n, 0);
    
    for(int i=0; i<n; i++) cin >> v[i];
    
    int total = 0;
    
    while(true){
        int last = 0;

        for(int i=0; i<n; i++){
            if(v[i]>last){
                last = v[i];
                v[i]=-1;
            }
        }

        if(last==0) break;
        total++;
    }

    cout << total << endl;
    
    return 0;
}