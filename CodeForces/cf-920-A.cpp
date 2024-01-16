#include <iostream>
 
using namespace std;
 
int main()
{
    int t;
    cin >> t;
    
    while(t--){
        int x1, x2, x3, x4;
        int y1, y2, y3, y4;
        
        cin >> x1 >> y1;
        cin >> x2 >> y2;
        cin >> x3 >> y3;
        cin >> x4 >> y4;
        
        int lx = min(min(x1, x2), min(x3, x4));
        int rx = max(max(x1, x2), max(x3, x4));
        int ly = min(min(y1, y2), min(y3, y4));
        int ry = max(max(y1, y2), max(y3, y4));
        
        cout << (rx-lx) * (ry - ly) << endl;
    }
 
    return 0;
}
