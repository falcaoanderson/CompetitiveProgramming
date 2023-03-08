// 31/01/19 // 19:21 //

#include <iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int la, lb, fa, fb;

    cin >> la >> lb >> fa >> fb;

    if(la==fa && lb==fb)
        cout << "0\n";
    else if( (la!=fa && lb!=fb) || (la!=fa && lb==fb))
        cout << "1\n";
    else
        cout << "2\n";

    return 0;
}
