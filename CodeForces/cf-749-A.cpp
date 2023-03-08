// 15/01/2020 // 8:14 PM //

#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define pb push_back
#define mp make_pair

const int INF = 0x3f3f3f3f;

int main(){
    fastio;

    int n, two=0, three=0;

    cin >> n;

    two   = n/2;
    if(n&1){
        two--;
        three++;
    }

    cout << two + three << endl;
    for(int i=0; i<two; i++)
        cout << "2 ";
    if(three)
        cout << "3";
    cout << endl;

    return 0;
}
