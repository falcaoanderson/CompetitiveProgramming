// 20/04/23 //
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
#define PB push_back
#define EB emplace_back
#define ff first
#define ss second

typedef pair<int, int> pii;
typedef tuple<int, int, int> tiii;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    while(n--){
        int a;
        cin >> a;

        int count=0;    

        for(int i=1; i*i<=a; i++){
            if(i*i==a){
                count += 1;
            }
            else if(a%i==0){
                count += 2;
            }
        }

        cout << count << endl;
    }

    return 0;
}