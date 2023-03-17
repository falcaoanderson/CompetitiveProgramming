#include <iostream>
#include <vector>

using namespace std;

#define ll long long

int main(){
    ll n;
    cin >> n;

    ll soma = n*(n+1LL);

    if(soma%4!=0){
        cout << "NO" << endl;
        return 0;
    }

    soma /= 4LL;

    vector<int> v1, v2;

    for(int i=n; i>=1; i--){
        if(soma-i>=0){
            v1.push_back(i);
            soma -= i;
        }
        else{
            v2.push_back(i);
        }
    }

    cout << "YES" << endl;
    cout << v1.size() << endl;
    for(auto i : v1){
        cout << i << " ";
    }
    cout << endl;

    cout << v2.size() << endl;
    for(auto i : v2){
        cout << i << " ";
    }
    cout << endl;
    


    return 0;
}