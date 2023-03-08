// 05/01/20 // 3:19 PM //

#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

int main(){
    fastio;

    string num;
    int m;

    cin >> num >> m;

    long long resp=0;

    for(int i=0; i<(int)num.size(); i++){
        resp = (10*resp + (long long)num[i]-'0')%m;
    }

    cout << resp << endl;

    return 0;
}
