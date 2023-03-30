// 30/03/23 //
// brute force para testa a ideia // <- nao funciona
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
 
using namespace std;
 
#define endl "\n"

typedef long long ll;
typedef pair<int, int> pii;

inline int abs(int a){
    return (a>0 ? a: -a);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    
    vector<ll> v(n, 0);
    map<int, int> compress;

    for(int i=0; i<n; i++){
        cin >> v[i];
        compress[v[i]] = 0;
    }

    int count=0;

    for(map<int, int>::iterator it=compress.begin(); it!=compress.end(); it++){
        (it -> second) = ++count;
    }
    
    for(int i=0; i<n; i++){
        v[i] = compress[v[i]];
    }
    
    vector<int> aux(n+1, -1);
    
    int count = 0;
    int resp  = 0;

    for(int i=0; i<n; i++){
        if(aux[v[i]]!=-1){

        }
    }

    return 0;
}