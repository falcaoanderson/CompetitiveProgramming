// 09/10/20 // 2:38 PM //

#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
#define pb push_back
#define mp make_pair
//#define int long long

const int MAXN = (1e5) + 10;

int main(){
    fast_io;

    int n;
    char ini;
    cin >> n >> ini;

    int a=0, b=0, c=0;
    if(ini=='A')a=1;
    if(ini=='B')b=1;
    if(ini=='C')c=1;

    while(n--){
        int temp;
        cin >> temp;

        if(temp==1) swap(a, b);
        if(temp==2) swap(b, c);
        if(temp==3) swap(a, c);
    }

    if(a==1)cout << "A" << endl;
    if(b==1)cout << "B" << endl;
    if(c==1)cout << "C" << endl;

    return 0;
}

