// 28/03/23 //
#include <iostream>
#include <vector>
#include <algorithm>
 
using namespace std;
 
#define endl "\n"

typedef pair<int, int> pii;

int bsearch(vector<pii> &v, int val, int start, int end){ // uper_bound
    int resp = -1;
 
    while(start<=end){
        int mid = (start+end)/2;
 
        if(v[mid].first>=val){
            resp = mid;
            end = mid-1;
        }
        else{
            start = mid+1;
        }
    }
 
    return resp;
}
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    int n, x;
    cin >> n >> x;
 
    vector<pii> v(n, pii(0, 0));
 
    for(int i=0; i<n; i++){
        cin >> v[i].first;
        v[i].second = i;
    }
    
    sort(v.begin(), v.end());
 
    for(int i=0; i<n; i++){
        int pos = bsearch(v, x-v[i].first, i+1, (int)v.size()-1);
        
        if(pos!=-1 && v[pos].first==x-v[i].first){
            cout << v[i].second+1 << " " << v[pos].second+1 << endl;
            return 0;
        }
    }
 
    cout << "IMPOSSIBLE" << endl;
 
    return 0;
}