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

const int INF  = 0x3f3f3f3f;
const int MAXN = (2e5) + 5;
const int MOD  = (1e9) + 7;

int main(){
    fast_io;

    vector<string> v;

    int msize=0;

    while(true){
        string num;
        cin >> num;

        if(num=="0") break;

        msize = max(msize, (int)num.size());
        v.PB(num);
    }

    string resp = "";
    int last=0;

    for(int i=0; i<=110; i++){
        int digit=last;

        for(string num: v){
            int num_size = num.size();

            if(num_size>=i+1){
                digit += (int)num[num_size-1-i]-48;
            }
        }

        //sif(i==msize && digit==0) continue;

        resp += char(digit%10 + 48);
        last = digit/10;
    }

    bool flag = 0;
    for(int i=(int)resp.size()-1; i>=0; i--){
        flag = flag || (resp[i]!='0');

        if(flag) cout << resp[i];
    }
    cout << endl;

    return 0;   
}
