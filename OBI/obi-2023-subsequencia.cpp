#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int na, nb;
    cin >> na >> nb;

    vector<int> sa(na), sb(nb);
    
    for(int i=0; i<na; i++) cin >> sa[i];
    for(int i=0; i<nb; i++) cin >> sb[i];

    int j=0;
    bool flag_sub=true;

    for(int i=0; i<nb; i++){
        while(j<na){
            if(sa[j]==sb[i]){
                j++;
                break;
            }
            j++;
        }

        if(j==na && (i<nb-1 || (i==nb-1 && sa[na-1]!=sb[nb-1])) ){
            flag_sub=false;
            break;
        }
    }

    cout << (flag_sub?"S":"N") << endl;

    return 0;
}