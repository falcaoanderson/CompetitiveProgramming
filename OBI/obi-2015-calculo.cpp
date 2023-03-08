// 22/03/19 // 8:46 PM //

#include <iostream>

using namespace std;

#define MAXN 10010

int m, n;
int seq_1[MAXN];
int seq_2[MAXN];
int soma[MAXN];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> m >> n;

    for(int i=1; i<=m; i++)
        cin >> seq_1[i];
    for(int i=1; i<=n; i++)
        cin >> seq_2[i];

    m = max(m,n);

    for(int i=m; i>=0; i--){
        soma[i] = seq_1[i] + seq_2[i];

        if(soma[i]==2){
            soma[i] = 0;
            seq_1[i-1]++;
        }
        else if(soma[i]==3){
            soma[i] = 1;
            seq_1[i-1]++;
        }
    }

    for(int i=m; i>=0; i--){
        if(soma[i]==0)
            m--;
        else
            break;
    }

    if(soma[0]==1)
        cout << "1 ";

    for(int i=1; i<=m; i++)
        cout << soma[i] << " ";
    cout << "\n";

    return 0;
}
