// 07/03/19 // 8:15 PM //

#include <iostream>

using namespace std;

#define MAXN 100010
#define MAXI 15

int n, m, temp, ant=0;
int tab[MAXI][MAXN];
int resp[MAXI];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    for(int i=1; i<=n; i++){
        cin >> temp;

        for(int k=0; k<=9; k++)
            tab[k][i] = tab[k][i-1];

        tab[temp][i]++;
    }

    for(int i=0; i<m; i++){
        cin >> temp;

        if(temp>ant){
            for(int k=0; k<=9; k++)
                resp[k] += tab[k][temp] - tab[k][ant];
        }
        else{
            for(int k=0; k<=9; k++)
                resp[k] += tab[k][ant-1] - tab[k][temp-1];
        }

        ant = temp;
    }

    for(int i=0; i<=9; i++)
        cout << resp[i] << " ";
    cout << "\n";

    return 0;
}

