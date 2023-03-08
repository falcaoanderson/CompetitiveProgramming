// 00/00/20 // 00:00 XX //

#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define pb push_back
#define mp make_pair
#define ff first
#define ss second

const int INF = 0x3f3f3f3f;
const int MAXN = 1e5 + 10;

int main(){
    fastio;

    int t;
    cin >> t;

    while(t--){
        string num;
        cin >> num;

        int resp = (num.size()-1)*9 + max(num[0]-'0'-1, 0);

        bool flag = 1;
        for(char c: num)
            if(c!=num[0]){
                flag = (c>num[0]);
                break;
            }


        cout << resp + flag << endl;
    }

    return 0;
}
