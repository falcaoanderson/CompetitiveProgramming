#include <iostream>
#include <cstring>
using namespace std;

#define MAXN 110

int aerop, voos, ap[MAXN];
int e, s, cont = 0;

int main(){

    while(cin >> aerop >> voos)
    {
        if(aerop == 0 && voos == 0) break;

        cont++;
        memset(ap, 0, sizeof(ap));

        for(int i=0; i<voos; i++){
            cin >> e >> s;
            ap[e]++;
            ap[s]++;
        }

        int maior = -10;

        for(int i=1; i<=aerop; i++){
            if(ap[i]>maior) maior = ap[i];
        }

        cout << "Teste " << cont << "\n";

        for(int i=1; i<=aerop; i++){
            if(ap[i] == maior)
                cout << i << " ";
        }
        cout << "\n\n";
    }

    return 0;
}