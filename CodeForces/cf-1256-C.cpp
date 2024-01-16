/*
16/01/24 
Problem: cf 598 div3 C
Complexity:
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
#define PB push_back
#define EB emplace_back
#define FF first
#define SS second

typedef pair<int, int> pii;
typedef tuple<int, int, int> tiii;

int main(){
    fast_io;

    int n, m, d;
    cin >> n >> m >> d;

    int sum=0;
    vector<int> v(m+1);
    for(int i=0; i<m; i++){
        cin >> v[i];
        sum += v[i];
    }

    d--;

    if( (m+1)*d + sum < n){
        cout << "NO" << endl;
    }
    else{
        cout << "YES" << endl;

        int sobra = (m+1)*d + sum - n;

        for(int i=0; i<m+1; i++){
            if(sobra>0){
                int aux = min(d, sobra);
                sobra -= aux;

                for(int j=0; j<d-aux; j++) cout << 0 << " ";
            }
            else{
                for(int j=0; j<d; j++) cout << 0 << " ";
            }

            for(int j=0; j<v[i]; j++) cout << i+1 << " ";
        }
    }

    return 0;
}
