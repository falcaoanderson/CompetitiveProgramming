// 19/07/23 //
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

int main(){
    fast_io;

    int n;
    while(true){
        cin >> n;
        if(n==0) break;

        priority_queue< int, vector<int>, greater<int> > pqueue;

        for(int i=0; i<n; i++){
            int val;
            cin >> val;

            pqueue.push(val);
        }

        ll resp = 0;
        while((int)pqueue.size()!=1){
            int aux=0;

            aux += pqueue.top();
            pqueue.pop();
            aux += pqueue.top();
            pqueue.pop();

            resp += (ll)aux;

            pqueue.push(aux);
        }

        cout << resp << endl;
    }

    return 0;
}
