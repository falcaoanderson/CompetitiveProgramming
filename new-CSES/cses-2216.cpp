// 31/03/23 //
#include <iostream>
#include <vector>
#include <algorithm>
 
using namespace std;
 
#define endl "\n"
#define PB push_back

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    
    vector<int> v(n, 0);
    
    for(int i=0; i<n; i++) cin >> v[i];
    
    vector<bool> collected(n+1, 0);
    int total = 0;

    for(int i=0; i<n; i++){
        if(!collected[v[i]-1]) total++;        

        collected[v[i]] = 1;
    }

    cout << total << endl;

    return 0;
}