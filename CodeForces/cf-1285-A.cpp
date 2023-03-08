// 16/01/20 // 08:06 PM //

#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define pb push_back
#define mp make_pair

const int INF = 0x3f3f3f3f;

int main(){
    fastio;

    int n, left=0, right=0;

    cin >> n;

    while(n--){
        char c;
        cin >> c;

        if(c=='L') left++;
        else       right++;
    }

    cout << left + right + 1 << endl;

    return 0;
}
