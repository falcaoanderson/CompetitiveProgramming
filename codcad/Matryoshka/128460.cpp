#include <iostream>
#include <algorithm>
using namespace std;
#define MAXN 100005

int main(){
    int n,cont=0, v[MAXN], ov[MAXN];
    int verrado[MAXN];

    cin>>n;

    for(int i=0; i<n; i++){
        cin >> v[i];
        ov[i]=v[i];
    }

    sort(ov , ov+n);

    for(int i=0; i<n; i++){
        if(v[i]!=ov[i]){
            verrado[cont]=v[i];
            cont++;
        }
    }
    sort(verrado,verrado+cont);

    cout<<cont<<endl;
    for(int i=0; i<cont; i++){
        cout<<verrado[i]<<" ";
    }
    cout<<endl;
    return 0;
}
