#include <iostream>
using namespace std;

int main(){
    string num;

    cin >> num;

    int u = num.size()-1, soma=0;

    for(int i=0; i<=u; i++){
        soma += (num[i]-'0');
    }

    if( (num[u]-'0')%2==0 )
        cout << "S\n";
    else
        cout << "N\n";

    if(soma%3==0)
        cout << "S\n";
    else
        cout << "N\n";

    if( (num[u]-'0')%5==0 )
        cout << "S\n";
    else
        cout << "N\n";

    return 0;
}
