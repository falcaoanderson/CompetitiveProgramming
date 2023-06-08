// 08/06/23 //
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

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;

        bool ok = true;
        unordered_set<string> prefix, total;

        while(n--){
            string num;
            cin >> num;

            if(!ok) continue;

            for(int i=0; i<=(int)num.size(); i++){
                string sub_num = num.substr(0,i); 
                
                if(total.find(sub_num)!=total.end()){
                    ok = false;
                    break;
                }

                if(i<(int)num.size()) prefix.insert(sub_num);
            }
            
            if(prefix.find(num)!=prefix.end()){
                ok = false;
                continue;
            }

            total.insert(num);
        }
        
        cout << (ok?"YES":"NO") << endl;
    }

    return 0;
}