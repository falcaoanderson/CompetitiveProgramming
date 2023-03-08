// 09/10/20 // 12:00 PM //

 #include <bits/stdc++.h>

 using namespace std;

int main(){
    int a1, a2, d1, d2;

    cin >> a1 >> d1 >> a2 >> d2;

    if(a1!=d2 && d1==a2)
        cout << "1" << endl;
    else if(a1==d2 && d1!=a2)
        cout << "2" << endl;
    else
        cout << "-1" << endl;

    return 0;
}
