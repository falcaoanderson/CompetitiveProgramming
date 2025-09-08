/*
31/08/25 

*/

#include <bits/stdc++.h>

using namespace std;

int main(){

    string s;
    cin >> s;

    bool a=0, b=0, resp=0;
    
    for(char c: s){
        if(c=='T') a = 1;
        if(c=='A' && a) b = 1;
        if(c=='P' && b) resp = 1;
    }

    cout << (resp? 'S': 'N') << endl;

    return 0;
}