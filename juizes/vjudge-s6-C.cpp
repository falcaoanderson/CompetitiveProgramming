// 06/07/23 //
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

int main(){
    fast_io;

    int n;
    string a, b;
    cin >> n >> a >> b;

    int resp = 0;

    for(int i=0; i<n-1; i++){
        if(a[i]!=a[i+1] && a[i]!=b[i] && a[i+1]!=b[i+1]){
            swap(a[i], a[i+1]);
            resp++;
        }
        else if(a[i]!=b[i]){
            resp++;
        }
    }
    resp += (int)(a[n-1]!=b[n-1]);

    cout << resp << endl;

    return 0;
}
