// 07/04/23 //
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <tuple>

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
    
    int n, k;
    cin >> n >> k;

    vector<int> v(n, 0);

    for(int i=0; i<n; i++){
        cin >> v[i];
    }

    int j=0;
    ll resp=0;
    
    int distincts=0;
    unordered_map<int, int> qnt_val;

    for(int i=0; i<n; i++){
        
        while(j<n && ((qnt_val.find(v[j])!=qnt_val.end() && qnt_val[v[j]]!=0)|| distincts<k)){
            if(qnt_val.find(v[j])==qnt_val.end() || qnt_val[v[j]]==0){
                qnt_val[v[j]] = 1;
                distincts++;
            }
            else{
                qnt_val[v[j]]++;
            }

            j++;
        }
        
        if(j==n){
            ll aux = n-i;
            resp += (aux*(aux+1LL))/2LL;
            break; 
        }

        resp += j-i;

        qnt_val[v[i]]--;
    
        if(qnt_val[v[i]]==0){
            distincts--;
        }
    }

    cout << resp << endl;

    return 0;
}