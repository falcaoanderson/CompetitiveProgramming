// 22/02/19 // 9:52 PM //

#include <iostream>
#include <cstring>

using namespace std;

#define MAXN 5010

string num;
int memo[MAXN], tam;

long long funcao(int i){
    if(memo[i]>=0) return memo[i];

    if(i>=tam) return memo[i] = 1;

    if(i<tam-1){
        int alg_2 = (num[i]-'0')*10 + (num[i+1]-'0');

        if(alg_2==20 || alg_2==10)
            return memo[i] = funcao(i+2);

        else if(alg_2<=26 && num[i+2]!='0')
            return memo[i] = funcao(i+1) + funcao(i+2);
    }

    return memo[i] = funcao(i+1);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    while(true){
        cin >> num;
        if(num=="0") break;

        tam = num.size();
        num+="AAA";
        memset(memo, -1, sizeof(memo));

        cout << funcao(0) << "\n";
    }

    return 0;
}
