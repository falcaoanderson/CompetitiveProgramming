// 14/01/19 // 8:14 //

#include <iostream>
using namespace std;

int n, x1, x2, y1, y2;

bool func(int i1, int j1, int i2, int j2){
    int metade=n/2;

    if( (i1<=metade && i2>metade) || (j1<=metade && j2>metade) )
        return true;
    return false;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> x1 >> y1 >> x2 >> y2;

    if( func(x1,y1,x2,y2) || func(x2,y2,x1,y1) )
        cout << "S\n";
    else
        cout << "N\n";


    return 0;
}
