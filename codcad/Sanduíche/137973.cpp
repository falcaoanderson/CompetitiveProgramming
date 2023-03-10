// 07/02/19 // 10:10 PM //

#include <iostream>

using namespace std;

#define MAXN 2000010  // 2 * 10^6 //

int n, d, v[MAXN], soma[MAXN];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> d;

    for(int i=1; i<=n; i++){
        cin >> v[i];
        v[i+n] = v[i];
    }
    for(int i=1; i<=2*n; i++)
        soma[i] = v[i] + soma[i-1];


    int a=0, b=1, total=0;
    for(int a=0; a<n; a++){

        while(a+n>=b){
            int atual = soma[b] - soma[a];

            if(atual==d){
                total++;
                b++;
                break;
            }
            else if(atual>d){
                break;
            }
            b++;
        }

    }

    cout << total << "\n";

    return 0;
}
