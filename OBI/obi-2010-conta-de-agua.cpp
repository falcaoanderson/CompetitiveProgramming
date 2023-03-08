// 27/10/20 // 12:19 PM //

#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
#define pb push_back
#define mp make_pair
#define ll long long
//#define int long long

typedef pair<int, int> pii;

const int INF  = 0x3f3f3f3f;
const int MAXN = (1e5) + 10;

int main(){
    fast_io;

    int m;
    cin >> m;
    
    int custo = 7;

    if(m>10 && m<=30) 
        custo += (m-10) * 1;
    if(m>=31 && m<=100)
        custo += 20 + (m-30) * 2;
    if(m>100)
        custo += 160 + (m-100) * 5;
    
    cout << custo << endl;

    return 0;
}
