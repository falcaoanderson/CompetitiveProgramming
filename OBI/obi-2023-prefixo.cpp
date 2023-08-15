#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)

const int MAXN = 1e5;
const int INF = 0x3f3f3f3f;


int main(){
    fast_io;

    int n1, n2;
    string s1, s2;

    cin >> n1 >> s1 >> n2 >> s2;

    int resp = 0;
    for(int i=0; i<min(n1, n2) && s1[i]==s2[i]; i++){
        resp = i + 1;
    }

    cout << resp << endl;
    

    return 0;
}