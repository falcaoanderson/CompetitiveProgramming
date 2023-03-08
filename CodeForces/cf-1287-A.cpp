// 17/01/20 // 9:15 PM //

#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define pb push_back
#define mp make_pair

const int INF = 0x3f3f3f3f;

int main(){
    fastio;

    int t;
    cin >> t;

    while(t--){
        string row;
        int sz, resp=0, mresp=0;
        bool flag = false;

        cin >> sz >> row;

        for(int i=0; i<sz; i++){
            if(row[i]=='A'){
                flag = true;
                resp  = 0;
            }
            else if(flag){
                resp++;
                mresp = max(mresp, resp);
            }
        }

        cout << mresp << endl;
    }

    return 0;
}
