// 22/09/23 //
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
#define ff first
#define ss second

typedef pair<int, int> pii;
typedef tuple<int, int, int> tiii;

int x;
void brute_force(vector<int> &v, unordered_map<int, int> &qnt){
    int sz = v.size();

    for(int i=1; i<(1<<sz); i++){
        
        int crr = 0;
        for(int j=0; j<sz; j++){
            if((i&(1<<j))!=0){
                crr += v[j];

                if(crr>x) break;
            }
        }

        if(crr<=x){
            if(qnt.find(crr)==qnt.end())
                qnt[crr] = 1;
            else
                qnt[crr]++;
        }
    }
}

int main(){
    fast_io;

    int n;
    cin >> n >> x;

    vector<int> vl, vr;

    for(int i=0; i<n; i++){
        int val;
        cin >> val;

        if(i<n/2 && val<=x) vl.PB(val);
        if(i>=n/2 && val<=x) vr.PB(val);
    }

    unordered_map<int, int> qleft, qright;
    //qleft.reserve(1024);
    //qright.reserve(1024);
    qleft.max_load_factor(0.25);
    qright.max_load_factor(0.25);

    brute_force(vl, qleft);
    brute_force(vr, qright);

    qleft[0] = 1;

    ll resp = 0;

    for(pii p: qleft){
        if(p.ff == x){
            resp += (ll)p.ss;
        }
        else{
            if(qright.find(x-p.ff)!=qright.end()){
                resp += (ll)p.ss * (ll)qright[x-p.ff];
            }
        }
    }

    cout << resp << endl;

    return 0;
}
