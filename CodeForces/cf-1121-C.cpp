/*
11/08/25 

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

    int n, k;
    cin >> n >> k;

    queue<pii> fila;
    int bound_time = 0;
    for(int i=0; i<n; i++){
        int val;
        cin >> val;
        fila.push({val, i});
        bound_time += val;
    }

    queue< pair<pii, int> > process;
    int time = 0, done=0;
    set<int> resp;

    while(time<=bound_time && !(fila.empty() && process.empty())){
        int perc = (200*done + n)/(2*n);
        // cout << time << " " << perc << " " << done << endl;
        // time+0

        while((int)process.size()<k && !fila.empty()){
            pii p = fila.front();
            fila.pop();

            process.push({{time, p.FF}, p.SS});
        }        

        // time+0.5
        int sz = process.size();
        for(int i=0; i<sz; i++){
            auto crr = process.front();
            process.pop();

            int test_value = time - crr.FF.FF + 1;
            if(test_value==perc){
                resp.insert(crr.SS);
                // cout << "resp++" << endl;
            }

            process.push(crr);
        }
        for(int i=0; i<sz; i++){
            auto crr = process.front();
            process.pop();

            int test_value = time - crr.FF.FF + 1;

            if(test_value<crr.FF.SS){
                process.push(crr);
            }
            else{
                done++;
            }
        }

        time++;
    }

    cout << resp.size() << endl;

    return 0;
}
