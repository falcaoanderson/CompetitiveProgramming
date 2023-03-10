// 13/08/19 // 5:16 PM //

#include <bits/stdc++.h>

using namespace std;

#define MAXNUM 0x3f3f3f3f

int n, cont=0;
bool carta[MAXNUM];
int resp;

void funcao(int i, int mask, int num){


    if(i==n){
        if(carta[num]==0){
            resp = num;
        }
        return;
    }


    for(int j=0; j<n; j++)
        if((mask&(1<<j))==0)
            funcao(i+1, mask|(1<<j), num + (j+1)*pow(10, i));


}

int fat(int i){
    if(i==0) return 1;

    return i*fat(i-1);
}

int main(){

    cin >> n;
    getchar();

    for(int i=0; i<fat(n)-1; i++){
        int num=0, aux=n-1;
        string temp, temp2="";

        getline(cin, temp);

        for(int j=0; j< 2*n-1; j++)
            if(j%2==0)
                temp2 += temp[j];

        num = stoi(temp2);

        carta[num]=1;
    }

    funcao(0, 0, 0);


    string number = to_string(resp);
    for(int i=0; i<number.size()-1; i++)
        cout << number[i] << " ";
    cout << number[number.size()-1] << "\n";


    return 0;
}
