// 26/06/23 //
#include <iostream>
#include <vector>
using namespace std;

int main(){

    vector<int> v(5);
    for(int &i: v){
        cin >> i;
    }

    int a=1, b=0;
    bool flag=0;
    for(int i=1; i<5; i++){
        if(!flag){
            if(v[i]==v[i-1])
                a++;
            else{
                b=1;
                flag=1;
            }
        }
        else{
            if(v[i]==v[i-1])
                b++;
            else{
                break;
            }
        }
    }

    cout << a << " " << b << endl;

    return 0;
}