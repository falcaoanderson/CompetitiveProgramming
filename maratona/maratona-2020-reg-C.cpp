/*
17/10/23 
Problem: ICPC Latam 2020 Regional - C. Crisis at the Wedding 
Complexity: O(n)
*/

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
#include <stack>
#include <functional>
#include <cmath>

using namespace std;

#define ll long long
#define endl "\n"
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)

int main(){
    fast_io;

    int n;
    cin >> n;

    vector<int> v(n);
    int qnt = 0;

    for(int i=0; i<n; i++){
        cin >> v[i];
        qnt += v[i];
    }

    qnt /= n;

    vector<int> v_aux = v;

    ll resp1=0;
    for(int i=0; i<2*n; i++){
        if(v_aux[i%n]>qnt){
            int delta = v_aux[i%n] - qnt;
            
            resp1 += (ll)delta;
            
            v_aux[i%n] -= delta; 
            v_aux[(i+1)%n] += delta;
        }
    }
    
    v_aux = v;

    ll resp2=0;
    for(int i=2*n-1; i>=0; i--){
        if(v_aux[i%n]>qnt){
            int delta = v_aux[i%n] - qnt;
            
            resp2 += (ll)delta;
            
            v_aux[i%n] -= delta; 
            v_aux[(i-1+n)%n] += delta;
        }
    }

    cout << min(resp1, resp2) << endl;

    return 0;
}
