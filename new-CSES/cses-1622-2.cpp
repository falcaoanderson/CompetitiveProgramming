#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

#define endl "\n"

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    string ss;
    cin >> ss;
    
    set<string> sol;

    string pss = ss;
    while(true){
        sol.insert(pss);

        next_permutation(pss.begin(), pss.end());
        
        if(pss==ss) break;
    }

    cout << sol.size() << endl;
    for(string x : sol)
        cout << x << endl;

    return 0;
}