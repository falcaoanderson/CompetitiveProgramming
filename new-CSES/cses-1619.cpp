// 26/03/23 //
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define endl "\n"
#define PB push_back

typedef pair<int, int> pii;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    
    vector<pii> v;
    
    for(int i=1; i<=n; i++){
        int a, b;
        cin >> a >> b;
        
        v.PB(pii(a, i));
        v.PB(pii(b, -i));
    }
    
    int crr=0, maxc=0;
    
    sort(v.begin(), v.end());
    
    for(pii x : v){
        if(x.second>0){
            crr++;
        }
        else{
            crr--;
        }
        
        maxc = (crr>maxc ? crr : maxc);
    }
    
    cout << maxc << endl;
    
    return 0;
}
