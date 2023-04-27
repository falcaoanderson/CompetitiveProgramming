// 27/04/23 // dp iterativa 
#include <iostream>
#include <vector>
 
using namespace std;
 
#define ll long long 
#define endl "\n"
  
const int MAXX = 1e5+5;
 
int memo[MAXX];
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, x;
    cin >> n >> x;
 
    vector<int> price(n+1), pages(n+1);
 
    for(int i=1; i<=n; i++) cin >> price[i];
    for(int i=1; i<=n; i++) cin >> pages[i];
    
    for(int i=1; i<=n; i++){
        for(int j=x; j>=price[i]; j--){
            memo[j] = max(memo[j], memo[j-price[i]] + pages[i]);
        }
    }
 
    cout << memo[x] << endl;
 
    return 0;
}