// 01/07/23 //
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <tuple>
#include <cstring>
#include <stack>

using namespace std;

#define ll long long
#define endl "\n"
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
#define PB push_back
#define EB emplace_back
#define ff first
#define ss second

typedef pair<int, int> pii;
typedef tuple<int, int, int> tiii;

const int INF  = 0x3f3f3f3f;
const int MAXN = (2e5) + 5;
const int MOD  = (1e9) + 7;

int main(){
    fast_io;

    int n, s, r;
    cin >> n >> s >> r;
    
    vector<bool> damaged(n+1);

    while(s--){ //damaged
        int val;
        cin >> val;

        damaged[val] = 1;
    }

    vector<int> reserva(r);
    for(int i=0; i<r; i++){
        cin >> reserva[i];
    }
    sort(reserva.begin(), reserva.end());

    for(int i: reserva){
        if(i==1){
            if(damaged[i+1]) damaged[i+1]=0;
        }
        else{
            if(damaged[i-1]) damaged[i-1] = 0;
            else if(damaged[i+1]) damaged[i+1]=0;
        }
    }

    int resp=0;
    for(int i: damaged) resp += (int)i;

    cout << resp << endl;

    return 0;
}
