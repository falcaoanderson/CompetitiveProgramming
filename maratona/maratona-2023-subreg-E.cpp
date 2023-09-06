// 06/08/23 //
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

    int n, k;
    cin >> n >> k;

    vector<int> freq(1e6+1);
    
    for(int i=0; i<n; i++){
        int val;
        cin >> val;

        freq[val]++;
    }

    int resp = 0;
    for(int i=1e6; i>0; i--){
        if(freq[i]==0) continue;
    
        int p=i, sum = 0;
        while(p>0){
            sum += p%10;
            p /= 10;
        }

        k -= freq[i];
        freq[i-sum] += freq[i];

        if(k<=0){
            resp = sum;
            break;
        }
    }

    cout << resp << endl;

    return 0;
}
