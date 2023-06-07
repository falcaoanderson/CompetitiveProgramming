// 03/06/23 //
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

const int MAXN = 105;

bool presente[MAXN];

int main(){
    fast_io;

    int n;
    cin >> n;


    int posx=0, posy=0;

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            int val;
            cin >> val;

            presente[val] = 1;
            
            if(val==0){
                posx=i;
                posy=j;
            }
        }
    }

    int num=0;
    for(int i=1; i<=n*n; i++) if(!presente[i]) num = i;

    cout << num << endl << posx << endl << posy << endl;

    return 0;
}
