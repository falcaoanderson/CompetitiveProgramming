/*
05/08/24 
Problem: 
Complexity:
*/

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl "\n"
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
#define PB push_back
#define EB emplace_back
#define FF first
#define SS second
#define sz(x) (int)(x).size()

typedef pair<int, int> pii;
typedef tuple<int, int, int> tiii;

const int INF  = 0x3f3f3f3f;
const  ll LINF = 0x3f3f3f3f3f3f3f3f;
const int MAXN = (3e2) + 5;
const int MOD  = (1e9) + 7;

int l, c;
int ma[MAXN][MAXN];

void swap_line(int i, int j){
    for(int k=0; k<c; k++){
        swap(ma[i][k], ma[j][k]);
    }
}

void swap_column(int i, int j){
    for(int k=0; k<l; k++){
        swap(ma[k][i], ma[k][j]);
    }
}

void solve(){
    int cont = 0;

    for(int i=0; i<c; i++){
        int r=i;
        for(int j=i+1; j<c; j++){
            if(ma[0][r]>ma[0][j]) r = j;
        }

        if(r>i){
            swap_column(i, r);
            cont++;
        }
    }

    for(int i=0; i<l; i++){
        int r=i;
        for(int j=i+1; j<l; j++){
            if(ma[r][0]>ma[j][0]) r = j;
        }

        if(r>i){
            swap_line(i, r);
            cont++;   
        }
    }

    bool flag = 1;
    for(int i=0; i<l && flag; i++){
        for(int j=0; j<c && flag; j++){
            flag = (ma[i][j]==i*c+j+1);
        }
    }

    if(flag){
        cout << cont << endl;
    }
    else{
        cout << "*" << endl;
    }
}

int main(){
    fast_io;

    while(cin >> l >> c){
        if(c==0) break;

        for(int i=0; i<l; i++){
            for(int j=0; j<c; j++){
                cin >> ma[i][j];
            }
        }

        solve();
    }
    
    return 0;
}
