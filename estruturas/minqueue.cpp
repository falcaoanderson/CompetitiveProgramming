// 31/10/20 // xx:xx PM //

#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
#define pb push_back
#define mp make_pair
#define ll long long
//#define int long long

typedef pair<int, int> pii;

struct MinQueue{
    deque<pii> dq;
    int l=1, r=1; // tempo de tras, tempo da frente

    void init(){
        l = r = 1;
        dq.clear();
    }
    void push(int val){
        while(!dq.empty() && dq.back().first>=val) dq.pop_back();

        dq.push_back(mp(val, l++));
    }
    void pop(){
        if(!dq.empty() && dq.front().second==r) dq.pop_front();
        r++;
    }
    int getMin(){
        return dq.front().first;
    }
};


const int INF  = 0x3f3f3f3f;
const int MAXN = (1e5) + 10;

int main(){
    fast_io;

    

    return 0;
}
