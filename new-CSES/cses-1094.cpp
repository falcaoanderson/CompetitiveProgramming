#include <iostream>

using namespace std;

const int MAXN = 2e5+5;

int n, v[MAXN];

int main(){
    
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> v[i];
    }

    long long total=0LL; 

    for(int i=0; i<n-1; i++){
        if(v[i]>v[i+1]){
            total += (long long)(v[i]-v[i+1]);
            v[i+1] = v[i];
        }
    }

    cout << total << endl;

    return 0;
}