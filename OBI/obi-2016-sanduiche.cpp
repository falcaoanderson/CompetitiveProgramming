// 28/05/19 // 10:51 AM //

#include <iostream>

using namespace std;

#define MAXN 1000010

int n, d, resposta=0;
int tam[2*MAXN];
int presum[2*MAXN];

int main(){

    cin >> n >> d;

    for(int i=1; i<=n; i++){
        cin >> tam[i];
        tam[i+n] = tam[i];
    }

    for(int i=1; i<=2*n; i++)
        presum[i] = presum[i-1] + tam[i];


    int temp = 1;
    for(int i=0; i<n; i++){
        while(temp-i<=n){

            if(presum[temp]-presum[i]==d){
                resposta++;
                break;
            }
            if(presum[temp]-presum[i]>d){
                temp--;
                break;
            }

            temp++;
        }
    }
    cout << resposta << "\n";

    return 0;
}
