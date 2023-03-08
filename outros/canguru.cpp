#include <bits/stdc++.h>

using namespace std;

int main(){

    int maxs = -1;
    for(int c=0; c<=9; c++){
        for(int a=0; a<=9; a++){
            for(int n=0; n<=9; n++){
                for(int g=0; g<=9; g++){
                    for(int u=0; u<=9; u++){
                        for(int r=0; r<=9; r++){
                            if(c==a || c==n || c==g || c==u || c==r
                               || a==n || a==g || a==u || a==r
                               || n==g || n==u || n==r
                               || g==u || g==r
                               || u==r) continue;

                            if( (100*c+10*a+n)+(100*g+10*u+r) == 111*u ){
                                cout << c << a << n << endl << g << u << r << endl << u << u << u<<endl;
                                cout << endl;

                                maxs = max(maxs, c+a+n);
                            }
                        }
                    }
                }
            }
        }
    }

    cout << maxs << endl;

    return 0;
}
