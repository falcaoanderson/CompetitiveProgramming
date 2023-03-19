#include <iostream>
#include <set>

using namespace std;

#define endl "\n"

int n;
string ss;
set<string> sol;

void permutation(int i, int mask, string pss){
    if(i>=n){
        sol.insert(pss);
        return;    
    }

    for(int k=0; k<n; k++){
        if((mask&(1<<k))==0){
            permutation(i+1, mask|(1<<k), pss+ss[k]);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> ss;
    n = ss.size();
    
    permutation(0, 0, "");

    cout << sol.size() << endl;

    for(set<string>::iterator it=sol.begin(); it!=sol.end(); it++){
        cout << (*it) << endl;
    }

    return 0;
}