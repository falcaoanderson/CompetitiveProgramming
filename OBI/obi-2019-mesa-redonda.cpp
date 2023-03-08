#include <bits/stdc++.h>

using namespace std;

bool cadeira[10];

int main(){
    int a, b;
    cin >> a >> b;

    cadeira[a%3] = 1;
    if(a%3==b%3) cadeira[(b+1)%3] = 1;
    else     cadeira[b%3] = 1;

    for(int i=0; i<3; i++)
        if(!cadeira[i]) cout << i << endl;

    return 0;
}
