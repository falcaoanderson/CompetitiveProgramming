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

    vector<int> v1(5), v2(5);

    for(int i=0; i<5; i++) cin >> v1[i];
    for(int i=0; i<5; i++) cin >> v2[i];

    bool flag = 1;
    for(int i=0; i<5; i++){
        if(v1[i]==v2[i])
            flag = 0;
    }

    if(flag)
        cout << "Y" << endl;
    else
        cout << "N" << endl;

    return 0;
}

