// 17/09/19 // 10:44 PM //

#include <bits/stdc++.h>

using namespace std;

#define MAXN 10010
#define pb push_back

int n;
bool stop=0;

vector<string> text;
set<string> prefix, sufix;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    for(int i=0; i<n; i++){
        string temp;
        cin >> temp;

        text.pb(temp);

        if(!stop && sufix.find(temp)!=sufix.end()){
            cout << temp << "\n";
            stop = 1;
        }

        for(int j=0; j<10; j++){
            string aux1  = temp.substr(0,j+1);
            string aux2  = temp.substr(j+1, 9-j);

            sufix.insert(aux1);

            if(j<9) prefix.insert(aux2);

            if(!stop && prefix.find(aux1)!=prefix.end() && sufix.find(aux2)!=sufix.end()){
                cout << (aux1+aux2) << "\n";
                stop=1;
            }

        }
    }

    if(!stop)
        cout << "ok\n";

    return 0;
}
