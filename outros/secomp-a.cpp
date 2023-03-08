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

    int n, m;
    while(cin >> n >> m){
        int cont = 0;
        if(n==0) break;

        for(int i=n; i<=m; i++){
            string num = to_string(i);
            int flag = 1;

            for(int j=0; j<(int)num.size(); j++)
                for(int l=j+1; l<(int)num.size(); l++)
                    if(num[j]==num[l])
                        flag = 0;
            cont += flag;
        }

         cout << cont << endl;
    }

    return 0;
}
