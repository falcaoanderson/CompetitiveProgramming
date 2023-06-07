// 07/06/23 //
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

int main(){
    fast_io;

    while(true){
        int n, m;
        cin >> n >> m;

        if(n==0 && m==0) break;

        vector<int> va(n), vb(m);

        for(int i=0; i<n; i++) cin >> va[i];
        for(int i=0; i<m; i++) cin >> vb[i];

        int a=0, b=0, resp=0;

        while(a<n && b<m){
            if(va[a]==vb[b]){
                resp++;
                a++;
                b++;
            }
            else if(va[a]<vb[b]){
                a++;
            }
            else{
                b++;
            }
        }

        cout << resp << endl;
    }

    return 0;
}
