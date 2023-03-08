#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)

const int MAXN = (2e5) + 10;

int main(){
    fast_io;

    int n, a=0, b=0;
    
    cin >> n;
    
    for(int i=0; i<n; i++){
        int temp; cin >> temp;
        
        if(temp==1) a++;
        else b++;
    }

    int p, m;
    cin >> p >> m;

    if(p>=a && m>=b) cout << "S" << endl;
    else cout << "N" << endl;

    return 0;
}
