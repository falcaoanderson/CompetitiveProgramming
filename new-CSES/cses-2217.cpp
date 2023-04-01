// 01/04/23 //
#include <iostream>
#include <vector>
#include <algorithm>
 
using namespace std;
 
#define endl "\n"
#define PB push_back
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m;
    cin >> n >> m;
    
    vector<int> v(n, 0);
    vector<int> pos(n+1, 0);
    pos[0] = n;

    for(int i=0; i<n; i++){
        cin >> v[i];

        pos[v[i]] = i;
    }

    int total = 0;
    vector<bool> inv(n+1, 0);

    for(int i=0; i<n; i++){
        if(pos[v[i]-1]>pos[v[i]]){
            inv[v[i]] = 1;
            total++;
        }
    }

    
    while(m--){
        int a, b;
        cin >> a >> b;
        a--; b--;

        pos[v[a]] = b;
        pos[v[b]] = a;
        swap(v[a], v[b]);

        for(int x=v[a]; x<=v[a]+1 && x<=n; x++){
            if( (pos[x-1]>pos[x])^(inv[x])){
                inv[x] = !inv[x];
                total += (int)inv[x] * 2 -1;
            }
        }

        for(int x=v[b]; x<=v[b]+1 && x<=n; x++){
            if( (pos[x-1]>pos[x])^(inv[x])){
                inv[x] = !inv[x];
                total += (int)inv[x] * 2 -1;
            }
        }

        cout << total << endl;
    }
     
    return 0;
}