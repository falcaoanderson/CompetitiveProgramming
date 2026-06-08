/*
19/01/26

*/
#include <bits/stdc++.h>

using namespace std;

#define fast_io ios_base::sync_with_stdio(false);cin.tie(nullptr)
#define endl "\n"
#define FF first
#define SS second
#define PB push_back
#define EB emplace_back

using ll = long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;

const int MAXVAL = 1e6 + 5;
const int MAXN = 3e4 + 5;

int main(){
    fast_io;

    int n;

    while(cin >> n){
        if(n==0) break;

        stack<int> pa, pb;
        int aux = 0;

        for(int i=0; i<n; i++){
            int x;
            cin >> x;

            pb.push(x);
        }

        while(!pb.empty()){
            pa.push(pb.top());
            pb.pop();
        }

        while(true){
            if(!pa.empty() && pa.top() == aux+1){
                pa.pop();
                aux++;
            }
            else if(!pb.empty() && pb.top() == aux+1){
                pb.pop();
                aux++;
            }
            else if(!pa.empty()){
                pb.push(pa.top());
                pa.pop();
            }
            else{
                break;
            }
        }

        cout << (aux==n? "yes": "no") << endl;
    }

    return 0;
}