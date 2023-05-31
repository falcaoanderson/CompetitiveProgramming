// 30/05/23 //
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
const int MAXN = 10;
const int MOD  = (1e9) + 7;

int row[10], col[10], dig1[20], dig2[20];

int main(){
    fast_io;
    
    for(int i=1; i<=8; i++){
        for(int j=1; j<=8; j++){
            char aux;
            cin >> aux;

            if(aux=='*'){
                row[i]++;
                col[j]++;
                dig1[i-j+7]++;
                dig2[i+j-2]++;
            }
        }
    }

    bool flag = true;

    for(int i=1; i<=8; i++){
        flag = (flag && row[i]==1 && col[i]==1);
    }
    for(int i=0; i<=14; i++){
        flag = (flag && dig1[i]<=1 && dig2[i]<=1);
    }

    if(flag)
        cout << "valid" << endl;
    else
        cout << "invalid" << endl;

    return 0;
}