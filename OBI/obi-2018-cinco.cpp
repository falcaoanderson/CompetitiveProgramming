// 31/03/19 // 10:30 AM //

#include <iostream>

using namespace std;

#define MAXN 1010

int n;
char seq[MAXN];

void print(){
    for(int i=0; i<n; i++)
        cout << seq[i] << " ";
    cout << "\n";
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    cin >> n;

    for(int i=0; i<n; i++)
        cin >> seq[i];

    for(int i=0; i<n; i++){
        if( (seq[i]=='0' || seq[i] == '5') && seq[i]<seq[n-1] ){
            swap(seq[i], seq[n-1]);
            print();
            return 0;
        }
    }

    for(int i=n-1; i>=0; i--){
        if(seq[i]=='0' || seq[i] == '5'){
            swap(seq[i], seq[n-1]);
            print();
            return 0;
        }
    }

    cout << "-1";

    return 0;
}
