// 12/09/23 //
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

const int MAXN = 1e2;

double memo[MAXN+5][6*MAXN+5];

int main(){
    fast_io;

    int n;
    int a, b;
    cin >> n >> a >> b;

    memo[0][0] = 1.0;
    for(int i=1; i<=n; i++){
        for(int j=i; j<=6*i; j++){
            for(int k=1; k<=6; k++)
                memo[i][j] += memo[i-1][j-k];
            memo[i][j] /= 6.0;
        }
    }

    double resp = 0;
    for(int i=a; i<=b; i++) resp += memo[n][i];

    cout.precision(6);
    cout.setf(ios::fixed);

    cout << resp << endl;

    return 0;
}
