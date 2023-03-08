#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define pb push_back

int t;
vector<int> num;
int zeros;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string cnum;
    cin >> t;

    while(t--){
        num.clear();
        zeros = 0;

        cin >> cnum;

        for(char calg : cnum){
            if(calg == '0') zeros++;
            else num.pb( (int)(calg - '0') );
        }
        sort(num.begin(), num.end());

        cout << num[0];
        for(int i=0; i<zeros; i++) cout << "0";
        for(int i=1; i<(int)num.size(); i++) cout << num[i];
        cout << endl;
    }

    return 0;
}
