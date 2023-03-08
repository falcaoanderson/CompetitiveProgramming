// 29/10/20 // xx:xx PM //

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
    
    int n;
    cin >> n;

    stack<pii> pilha;
   
    for(int i=1; i<=n; i++){
        int val;
        cin >> val;

        while(!pilha.empty() && pilha.top().first>=val) pilha.pop();

        if(pilha.empty())
            cout << 0 << " ";
        else
            cout << pilha.top().second << " ";
        
        pilha.push(mp(val, i));
    }

    cout << endl;

    return 0;
}
