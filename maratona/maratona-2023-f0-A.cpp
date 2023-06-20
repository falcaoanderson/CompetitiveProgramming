// 17/06/23 //
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

int main(){
    fast_io;

    string jogo;
    cin >> jogo;

    int qnt_x=0, qnt_o=0, pos_o=-1;

    for(int i=0; i<3; i++){
        qnt_x += int(jogo[i]=='X');
        qnt_o += int(jogo[i]=='O');

        if(jogo[i]=='O') pos_o = i;
    }

    if(qnt_x!=2 || qnt_o!=1){
        cout << "?" << endl;
    }
    else if(pos_o==1){
        cout << "*" << endl;
    }
    else{
        cout << "Alice" << endl;
    }


    return 0;
}
