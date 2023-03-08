// 01/03/19 // 18:36 //

#include <iostream>
#include <cstring>

using namespace std;

#define MAXL 2010

int n;
int memo[MAXL][MAXL];
string u1, u2;

int funcao(int i, int j){

    if(memo[i][j]>=0) return memo[i][j];


    if(i==0 && j==0)
        if(u1[i]==u2[j]) return memo[i][j] = 0;
        else             return memo[i][j] = 1;


    if(i==0)
        if(u1[i]==u2[j]) return memo[i][j] = funcao(i, j-1);
        else             return memo[i][j] = 1 + funcao(i, j-1);
    if(j==0)
        if(u1[i]==u2[j]) return memo[i][j] = funcao(i-1, j);
        else             return memo[i][j] = 1 + funcao(i-1, j);

    if(u1[i] == u2[j])
        return memo[i][j] = funcao(i-1, j-1);

    return memo[i][j] = 1 + min( funcao(i-1,j-1), min(funcao(i-1,j), funcao(i,j-1)) );
}

int main(){

    cin >> n;
    cin.ignore();

    for(int i=0; i<n; i++){
        memset(memo, -1, sizeof(memo));

        getline(cin, u1);
        getline(cin, u2);

        if(min(u1.size(), u2.size())==0)
            cout << max(u1.size(), u2.size()) << "\n";
        else
            cout << funcao(u1.size()-1, u2.size()-1) << "\n";
    }

    return 0;
}
