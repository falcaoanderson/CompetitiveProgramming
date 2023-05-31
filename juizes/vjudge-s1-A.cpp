// 30/05/23 //
#include <bits/stdc++.h>

using namespace std;

int main(){
    string seq;
    cin >> seq;

    bool state = (seq[0]=='U');
    int op1=0;

    for(int i=1; i<(int)seq.size(); i++){
        if(seq[i]=='U'){
            op1 += (state==0);
            state=1;        
        }
        else{
            op1 += (state==1);
            state = 0;
        }

        op1 += (state==0);
        state = 1;
    }

    state = (seq[0]=='U');
    int op2=0;
    for(int i=1; i<(int)seq.size(); i++){
        if(seq[i]=='U'){
            op2 += (state==0);
            state=1;        
        }
        else{
            op2 += (state==1);
            state = 0;
        }

        op2 += (state==1);
        state = 0;
    }

    state = (seq[0]=='U');
    int op3=0;
    for(int i=1; i<(int)seq.size(); i++){
        if(seq[i]=='U'){
            op3 += (state==0);
            state=1;        
        }
        else{
            op3 += (state==1);
            state = 0;
        }

        op3 += (state!=((seq[i]=='U')));
        state = (seq[i]=='U');
    }

    cout << op1 << endl;
    cout << op2 << endl;
    cout << op3 << endl;

    return 0;
}