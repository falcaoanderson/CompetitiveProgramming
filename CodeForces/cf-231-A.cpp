// 24/08/25 //
#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int resp=0;
    while(n--){
        int a, b, c;
        cin >> a >> b >>c;
        resp += ((a+b+c)>1);
    }
    cout << resp << endl;
    return 0;
}