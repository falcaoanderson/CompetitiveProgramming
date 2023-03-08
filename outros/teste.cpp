#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1000;
const int MAXV = 1000;

vector<int> moeda = {1, 5, 10, 25, 50, 100, 200};
int memo[MAXN][MAXV];

int solve(int i, int value){
    if(memo[i][value]!=-1) return memo[i][value];

    if(value==0) return memo[i][value] = 1;
    if(i==moeda.size()) return memo[i][value] = 0;

    memo[i][value] = 0;
    for(int k=0; k*moeda[i]<=value; k++)
        memo[i][value] += solve(i+1, value - k*moeda[i]);

    return memo[i][value];
}

int main(){
    memset(memo, -1, sizeof(memo));

    cout << solve(0, 200) << endl;


    /*
    int cont = 0;
    for(int a=0; a<=200; a++) // moeda de 1
       for(int b=0; b<=40; b++) // moeda de 5
            for(int c=0; c<=20; c++) // moeda de 10
                for(int d=0; d<=8; d++) // moeda de 25
                    for(int e=0; e<=4; e++) // moeda de 50
                        for(int f=0; f<=2; f++) // moerda de 100
                            for(int g=0; g<=1; g++) // cedula de 200
                                if(a+b*5+c*10+d*25+e*50+f*100+g*200==200) cont++;
    */

    return 0;
}
