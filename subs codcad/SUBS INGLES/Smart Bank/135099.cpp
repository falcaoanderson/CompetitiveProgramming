#include <iostream>
#include <cstring>
using namespace std;

#define MAXC 7
#define MAXS 5010

int s, qnt[MAXC], valor[MAXC]={2,5,10,20,50,100,0};
long long memo[MAXC][MAXS];

long long funcao(int i, int falta){
    if(memo[i][falta]>=0) return memo[i][falta];

    if(falta==0) return memo[i][falta]=1LL;
    if(falta<0) return 0LL;
    if(i>5)return memo[i][falta]=0LL;

    long long resposta=0LL;

    for(int k=0; k<=qnt[i]; k++){
        int temp = falta - k*valor[i];
        if(temp>=0)
            resposta += funcao(i+1,temp);
        else
            break;
    }

    return memo[i][falta] = resposta;
}

int main(){
    memset(memo, -1, sizeof(memo));

    cin >> s;
    for(int i=0; i<6; i++)
        cin >> qnt[i];

    cout << funcao(0,s) << endl;

    return 0;
}
