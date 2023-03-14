#include <iostream>

using namespace std;

int main(){
    string v;
    cin >> v;


    int count=1, max_count = 1;
    for(int i=1; i<(int)v.size(); i++){
        if(v[i]==v[i-1]){
            count++;
            max_count = count>max_count?count:max_count;
        }
        else{
            count=1;
        }
    }

    cout << max_count << endl;

    return 0;
}