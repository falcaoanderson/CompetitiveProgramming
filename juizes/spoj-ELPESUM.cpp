// 29/01/23 //
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

int main(){
    fast_io;

    int t;
    cin >> t;

    for(int z=1; z<=t; z++){
        int n;
        cin >> n;

        vector<int> v(n);
        for(int i=0; i<n; i++) cin >> v[i];

        sort(v.begin(), v.end());

        int l=1, r=n-1;
        int a = v[0], b = v[0], resp=0;

        //cout << a << " " << b << endl;
        while(l<=r){
            int op1 = abs(a - v[l]), op2 = abs(a - v[r]),
                op3 = abs(b - v[l]), op4 = abs(b - v[r]);

            vector<pii> aux;
            aux.EB(op1, 1);
            aux.EB(op2, 2);
            aux.EB(op3, 3);
            aux.EB(op4, 4);
            sort(aux.begin(), aux.end());

            resp += aux[3].FF;
            //cout << aux[3].SS << endl;
            if(aux[3].SS==1){
                a = v[l++];
            }
            if(aux[3].SS==2){
                a = v[r--];
            }
            if(aux[3].SS==3){
                b = v[l++];
            }
            if(aux[3].SS==4){
                b = v[r--];
            }

            //cout << a << " " << b << endl;
        }

        cout << "Case " << z << ": " << resp << endl;
    }

    return 0;
}
