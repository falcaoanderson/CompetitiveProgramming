// 15/04/23 // dp iterativa com otimizacao de memoria
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
 
const int MAXN = 5e5+5;
 
int memo[5][MAXN];
 
/* dp recursiva
int solve(int a, int b){
    if(memo[a][b]!=-1) return memo[a][b];
 
    if(a==0){
        return memo[a][b] = b;
    }
    if(b==0){
        return memo[a][b] = a;
    }
 
    if(s1[a]==s2[b]) return memo[a][b] = solve(a-1, b-1);
 
    return memo[a][b] = 1 + min(solve(a-1, b), min(solve(a, b-1), solve(a-1, b-1)));
}
*/
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    string s1, s2;
    cin >> s1 >> s2;
    
    // solve[i][j] a menor edit distance entre os i primeiros caracteres de s1 e os j primeiros caracteres de s2
 
    s1 = " " + s1;
    s2 = " " + s2;
    
    /*
    for(int i=0; i<(int)s1.size(); i++){
        memo[i][0] = i;
    }
    */
    for(int i=0; i<(int)s2.size(); i++){
        memo[0][i] = i;
    }
 
    for(int i=1; i<(int)s1.size(); i++){
        memo[(i-1)%2][0] = i-1;
        memo[i%2][0] = i;
 
        for(int j=1; j<(int)s2.size(); j++){
            if(s1[i]==s2[j]){
                memo[i%2][j] = memo[(i-1)%2][j-1];
            }
            else{
                memo[i%2][j] = 1 + min(memo[(i-1)%2][j-1], min(memo[(i-1)%2][j], memo[i%2][j-1]));
            }
        }
    }
 
    cout << memo[((int)s1.size()-1)%2][(int)s2.size()-1] << endl;
    
    return 0;
}