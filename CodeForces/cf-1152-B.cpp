/*
05/08/25 

*/

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl "\n"
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
#define PB push_back
#define EB emplace_back
#define FF first
#define SS second
#define sz(x) (int)(x).size()

typedef pair<int, int> pii;
typedef tuple<int, int, int> tiii;

const int INF  = 0x3f3f3f3f;
const  ll LINF = 0x3f3f3f3f3f3f3f3f;
const int MAXN = (2e5) + 5;
const int MOD  = (1e9) + 7;

int main(){
    fast_io;

    int x;
    cin >> x;
    
    int qnt=0;
    vector<int> resp;
    while( x!=0 && (-(x+1)&(x+1)) != (x+1) ){
        qnt++;

        if(qnt%2==0){
            x++;
            continue;
        }

        int i=0;
        while( ((1<<i)&x) != 0 ){
            x ^= (1<<i);
            i++;
        }
        while( ((1<<i)&x) == 0 ){
            x ^= (1<<i);
            i++;
        }
        resp.PB(i);
    }

    cout << qnt << endl;

    for(int x: resp){
        cout << x << " ";
    }
    if(!resp.empty()) cout << endl;

    return 0;
}
