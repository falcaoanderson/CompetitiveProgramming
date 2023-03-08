// 29/07/19 // 5:46 PM //

#include <iostream>

using namespace std;

#define MAXN 3010

string a, b;
int memo[MAXN][MAXN];

void bottom_lcs(){
    a = " " + a;
    b = " " + b;

    for(int i=1; i<a.size(); i++){
        for(int j=1; j<b.size(); j++){
            if(a[i]==b[j])
                memo[i][j] = 1 + memo[i-1][j-1];
            else
                memo[i][j] = max(memo[i-1][j], memo[i][j-1]);
        }
    }

    int i = a.size()-1, j = b.size()-1;
    string resp = "";
    while(i!=0 && j!=0){
        if(memo[i-1][j-1]==memo[i-1][j] && memo[i-1][j-1]==memo[i][j-1] && memo[i-1][j-1]+1==memo[i][j]){
            resp += a[i];
            i--;
            j--;
        }
        else if(memo[i][j]==memo[i-1][j])
            i--;
        else if(memo[i][j]==memo[i][j-1])
            j--;
    }

    for(i=resp.size()-1; i>=0; i--)
        cout << resp[i];
    cout << "\n";
}

int main(){

    cin >> a >> b;

    bottom_lcs();

    return 0;
}
