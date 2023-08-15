#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)

const int MAXN = 1e5+5;
const int INF = 0x3f3f3f3f;

int last[MAXN];

int main(){
    fast_io;

    int n;
    cin >> n;

    vector<int> v(n+1);
    for(int i=1; i<=n; i++) cin >> v[i];

    int crr=0, resp = 0;
    for(int i=1; i<=n; i++){
        int x = v[i];

        if(last[x]==0){
            crr++;
            last[x] = i;
        }
        else{
            for(int j=i-crr; j<last[x]; j++) last[v[j]] = 0; 

            crr = i - last[x];
            last[x] = i;
        }

        resp = max(resp, crr);
    }
    
    cout << resp << endl;

    return 0;
}