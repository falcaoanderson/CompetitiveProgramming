// 09/10/20 // 12:00 PM //

 #include <bits/stdc++.h>

 using namespace std;

 #define endl "\n"
 #define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)

int main(){
    fast_io;

    vector<int> apostado(6, 0);
    int qnt = 0;

    for(int i=0; i<6; i++)
        cin >> apostado[i];

    for(int i=0; i<6; i++){
        int temp;
        cin >> temp;

        for(int j=0; j<6; j++)
            if(temp==apostado[j]) qnt++;
    }

    if(qnt==3)
        cout << "terno" << endl;
    else if(qnt==4)
        cout << "quadra" << endl;
    else if(qnt==5)
        cout << "quina" << endl;
    else if(qnt==6)
        cout << "sena" << endl;
    else
        cout << "azar" << endl;

    return 0;
}
