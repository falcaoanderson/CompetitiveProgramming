// 04/01/20 // 9:16 PM //

#include <iostream>

using namespace std;

#define endl "\n"
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

int main(){
    fastio;

    int n;
    string seq;

    cin >> n;

    while(n--){
        cin >> seq;

        int sete, q, j, k, a;
        sete = q = j = k = a = 0;

        for(char c : seq){
            if(c=='7')
                sete++;
            else if(c=='Q' && sete>q)
                q++;
            else if(c=='J' && q>j)
                j++;
            else if(c=='K' && j>k)
                k++;
            else if(c=='A' && k>a)
                a++;
        }

        cout << (int)seq.size()-5*a << endl;
    }

    return 0;
}
