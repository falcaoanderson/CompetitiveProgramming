// 02/06/23 //
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

    int n, m, s;
    cin >> n >> m >> s;
    
    int resp = -1;
    for(int i=m; i>=n; i--){

        int num = i, sum=0;

        while(num){
            sum += num%10;

            num /= 10;
        }

        if(sum==s){
            resp = i;
            break;
        }
    }

    cout << resp << endl;
    return 0;
}
