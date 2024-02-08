// 27/01/24 //
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
#include <functional>
#include <cmath>

using namespace std;

#define ll long long
#define endl "\n"
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
#define PB push_back
#define EB emplace_back
#define FF first
#define SS second

typedef pair<int, int> pii;
typedef tuple<int, int, int> tiii;

const int INF  = 0x3f3f3f3f;
const  ll LINF = 0x3f3f3f3f3f3f3f3f;
const int MAXN = (2e5) + 5;
const int MOD  = (1e9) + 7;

int cnt, placar[10], splacar[10];

void brute(int i){

    if(i==7){
        bool flag = 1;

        for(int j=1; j<=4 && flag; j++) flag = (placar[j]==splacar[j]);

        cnt += (int)flag;

        return;
    }

    int a=0, b=0;
    if(i<=3){
        a = 1;
        b = i+1;
    }
    else if(i<=5){
        a = 2;
        b = i-1;
    }
    else if(i==6){
        a = 3;
        b = 4;
    }


    splacar[a] += 3;
    brute(i+1);
    splacar[a] -= 3;

    splacar[b] += 3;
    brute(i+1);
    splacar[b] -= 3;

    splacar[a] += 1;
    splacar[b] += 1;
    brute(i+1);
    splacar[a] -= 1;
    splacar[b] -= 1;
}

int main(){
    fast_io;

    int t;
    cin >> t;

    for(int k=1; k<=t; k++){
        for(int i=1; i<=4; i++) cin >> placar[i];
        
        cnt = 0;
        brute(1);

        cout << "Case #" << k << ": ";
        if(cnt==1){
            cout << "Yes" << endl;
        }
        else if(cnt==0){
            cout << "Wrong Scoreboard" << endl;
        }
        else{
            cout << "No" << endl;
        }

    }

    return 0;
}
