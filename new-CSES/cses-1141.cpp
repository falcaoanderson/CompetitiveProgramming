// 30/03/23 //
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
 
using namespace std;
 
#define endl "\n"

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    
    vector<int> v(n, 0);

    for(int i=0; i<n; i++) cin >> v[i];

    map<int, int> last;
    vector<int> s(n+1, 0);

    s[0] = 1;
    last[v[0]] = 0;
    int resp  = 1;

    for(int i=1; i<n; i++){
        if(last.find(v[i])==last.end()){
            s[i] = s[i-1] + 1;
        }   
        else{
            s[i] = min(i-last[v[i]], s[i-1]+1);    
        }
        
        last[v[i]] = i;
        resp = max(resp, s[i]);
    }

    cout << resp << endl;

    return 0;
}