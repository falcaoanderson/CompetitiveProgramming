// 24/06/23 //
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <tuple>
#include <cstring>
#include <stack>

using namespace std;

#define ll long long
#define endl "\n"
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
#define PB push_back
#define EB emplace_back
#define ff first
#define ss second

typedef pair<int, int> pii;
typedef tuple<int, int, int> tiii;

char dominante = '0';

int val(string text){
    if(text[0]=='A'){
        return 10 + 4*(int)(text[1]==dominante);
    }
    if(text[0]=='J'){
        return 11 + 4*(int)(text[1]==dominante);
    }
    if(text[0]=='Q'){
        return 12 + 4*(int)(text[1]==dominante);
    }
    
    return 13 + 4*(int)(text[1]==dominante);
}

int main(){
    fast_io;

    string carta;
    cin >> carta;
    dominante = carta[1];

    int luana = 0, edu=0;
    
    for(int i=0; i<3; i++){
        cin >> carta;
        luana += val(carta);
    }
    for(int i=0; i<3; i++){
        cin >> carta;
        edu += val(carta);
    }

    if(luana>edu){
        cout << "Luana" << endl;
    }
    else if(luana==edu){
        cout << "empate" << endl;
    }
    else{
        cout << "Edu" << endl;
    }

    return 0;
}
