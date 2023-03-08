#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;

    cin >> t;
    while(t--){
        bool q=0, j=0, k=0, a=0;
        string seq;

        cin >> seq;

        for(char c : seq){
            if(c=='Q')      q = 1;
            else if(c=='J') j = 1;
            else if(c=='K') k = 1;
            else if(c=='A') a = 1;
        }

        if(q && j && k && a)
            cout << "Aaah muleke\n";
        else
            cout << "Ooo raca viu\n";
    }

    return 0;
}
