// 30/05/20 // 15:56 PM //

#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define pb push_back
#define mp make_pair

const int INF  = 0x3f3f3f3f;
const int MAXN = 60;

int n;
int ma[MAXN][MAXN], linha[MAXN], coluna[MAXN];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cin >> ma[i][j];

            linha[i]  += ma[i][j];
            coluna[j] += ma[i][j];
        }
    }

    int sum, l, c;

    if(linha[1]==linha[2]) sum = linha[1];
    else if(linha[1]==linha[3]) sum = linha[1];
    else if(linha[2]==linha[3]) sum = linha[2];

    for(int i=1; i<=n; i++){
        if(linha[i] != sum) l=i;
        if(coluna[i]!= sum) c=i;
    }

    cout << sum + ma[l][c] - linha[l] << " " << ma[l][c] << endl;

    return 0;
}
