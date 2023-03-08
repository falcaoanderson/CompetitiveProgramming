// 25/11/20 // xx:xx PM //

#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
#define pb push_back

const int MAXN = (1e5) + 10;

struct Evento{
    int x, yi, yf, tipo;
    Evento(){}
    Evento(int _x, int _yi, int _yf, int _tipo){
        x = _x;
        yi = _yi;
        yf = _yf;
        tipo = _tipo;
    }

    bool operator< (const Evento& temp){
        return (x<temp.x);
    }
};

int n;
vector<Evento> evento;

int main(){
    fast_io;

    cin >> n;
    for(int i=1; i<=n; i++){
        int xi, yi, xf, yf;
        cin >> xi >> yf >> xf >> yi;

        evento.pb(Evento(xi, yi, yf, 0)); // abertura
        evento.pb(Evento(xf, yi, yf, 1)); // fechamento
    }

    sort(evento.begin(), evento.end());

    map<int, int> y_ant;
    int resp = 0;

    for(int i=0; i<2*n; i++){
        int yi = evento[i].yi, yf = evento[i].yf;

        if(!evento[i].tipo){ // abertura
            y_ant[yi] = 0;
            y_ant[yf] = 0;
        }
        else{ // fechamento
            if(y_ant[yi]==0) resp++; // se o yi ainda esta marcado com '0', esse retangulo esta vazio
            
            // agora devemos marcar o possivel retangulo anterior que contem o atual
            auto it = y_ant.find(yi); it--;
            it->second = 1;

            // e removemos as marcacoes desse retangulo
            y_ant.erase(yi);
            y_ant.erase(yf);
        }
    }

    cout << resp << endl;

    return 0;
}
