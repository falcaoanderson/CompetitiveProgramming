#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int n,m,v[105],t[105];
    cin >> n >> m;

    int tv=0,tt=0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>tv;
            tt+=tv;
        }
        v[i]=tt;
        t[i]=tt;
        tt=0;
    }
    sort(t,t+n);

    for(int i=0; i<3; i++){
        for(int j=0; j<n; j++){
            if(t[i]==v[j]){
                cout << j+1 <<endl;
                break;
            }
        }
    }

    return 0;
}
