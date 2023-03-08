#include <bits/stdc++.h>

using namespace std;

stack<char> seq;

void limpa(){
    while(!seq.empty()) seq.pop();
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    string cartas;
    cin >> n;

    while(n--){
        bool flag = 0;
        limpa();

        cin >> cartas;


        for(char c : cartas){
            if(c=='Q'){
                if(seq.empty())seq.push('Q');
            }
            else if(seq.empty()){
                continue;
            }
            else if(c=='J'){
                if(seq.top()=='Q') seq.push('J');
                //else limpa();
            }
            else if(c=='K'){
                if(seq.top()=='J') seq.push('K');
                //else limpa();
            }
            else if(c=='A'){
                if(seq.top()=='K'){
                    flag=1;
                    break;
                }
                //else limpa();
            }
        }

        if(flag)
            cout << "Agora vai\n";
        else
            cout << "Agora apertou sem abracar\n";
    }

    return 0;
}
