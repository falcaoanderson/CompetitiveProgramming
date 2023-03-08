// 13/10/20 // 5:00 PM //

#include <bits/stdc++.h>

using namespace std;

int main(){

    int n;
    vector<int> qnum(10,0);

    cin >> n;
    for(int i=1; i<=n; i++){
        int num;
        char op;

        cin >> num >> op;

        if(op=='*'){
            if(num==4)
                qnum[2]+=2;
            else if(num==6){
                qnum[2]++;
                qnum[3]++;
            }
            else if(num==8)
                qnum[2]+=3;
            else if(num==9)
                qnum[3]+=2;
            else
                qnum[num]++;
        }
        else{
            if(num==4)
                qnum[2]-=2;
            else if(num==6){
                qnum[2]--;
                qnum[3]--;
            }
            else if(num==8)
                qnum[2]-=3;
            else if(num==9)
                qnum[3]-=2;
            else
                qnum[num]--;
        }
    }

    double temp = 1;
    for(int i=2; i<=9; i++){
        temp *= pow(i, qnum[i]);
    }

    cout.precision(0);
    cout.setf(ios::fixed);

    cout << temp << endl;

    return 0;
}
