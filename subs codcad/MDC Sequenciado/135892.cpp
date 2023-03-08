// 13/01/19 // 9:51 PM

#include <iostream>
using namespace std;

#define MAXN 100010

int n, v[MAXN];

int mdc(int a, int b){
    if(b==0) return a;

    return mdc(b, a%b);
}

int main(){
    cin >> n;

    for(int i=0; i<n; i++) cin >> v[i];

    int temp=mdc(v[0],v[1]);
    for(int i=2; i<n; i++)
        temp = mdc(temp,v[i]);

    cout << temp << endl;

    return 0;
}
