// 24/03/19 // 2:36 PM //

#include <iostream>

using namespace std;

#define MAXN 1010

int n;
int v[MAXN];

int main(){
    cin >> n;

    for(int i=0; i<n; i++) cin >> v[i];

    if(n==1){cout << "1\n";return 0;}

    long long dif = v[1]-v[0];
    int total = 0;
    int i=0;

    while(i<n){
        long long temp = v[i+1] - v[i];

        if(i==n-1){total++;break;}
        if(dif!=temp){
            total++;
            dif=temp;
            i--;
        }

        i++;
    }

    cout << total <<"\n";

    return 0;
}
