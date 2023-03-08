// 00/02/19 // 00:00 XX //

#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define pb push_back
#define mp make_pair

const int MAXN = 1e4+10;

int main(){
    fastio;

    string num;
    cin >> num;

    int sz = num.size();
    int cont3=0, cont5=0, pos=MAXN;
    bool flag = true;

    for(int i=0; i<sz; i++){
        if(num[i]=='7' && flag)  pos=i, flag = false;
        if(num[i]=='5') cont5++;
        if(num[i]=='3' && flag) cont3++;
    }

    while(cont3--)
        cout << "3";

    while(cont5--)
        cout << "5";

    for(int i=0; i<sz; i++)
        if(num[i]!='5' && i>=pos)
            cout << num[i];
    cout << endl;

    return 0;
}
