// 23/10/20 // 12:00 PM //

#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
#define pb push_back
#define mp make_pair
//#define int long long

const int INF  = 0x3f3f3f3f;
const int MAXN = (1e5) + 10;

int main(){
    fast_io;

    int n;
    while(cin >> n){
        //if(n==0) break;
        vector<int> pos(n+1);

        for(int i=1; i<=n; i++){
            int temp;
            cin >> temp;

            pos[temp] = i;
        }
        vector<int> v(n+1);
        for(int i=1; i<=n; i++){
            int temp;
            cin >> temp;

            v[i] = pos[temp];
            //cout << v[i] << " ";
        }
        int cont = 0;
        for(int i=1; i<=n; i++)
            for(int j=i+1; j<=n; j++)
                if(v[i]>v[j])
                    cont ++;
        cout << cont << endl;
    }
    return 0;
}
