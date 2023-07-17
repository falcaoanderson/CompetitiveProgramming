#include <bits/stdc++.h>
 
using namespace std;
 
#define PB push_back
#define EB emplace_back
#define endl "\n"
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
 
    int t;
    cin >> t;
 
    while(t--){
        string s;
        cin >> s;
 
        bool flag=true;
        for(int i=1; i<(int)s.size(); i++){
            if(s[i]!=s[i-1]) flag = false;
        }
 
        if(flag){
            cout << -1 << endl;
        }
        else{
            sort(s.begin(), s.end());
 
            cout << s << endl;
        }
    }
 
    return 0;
}