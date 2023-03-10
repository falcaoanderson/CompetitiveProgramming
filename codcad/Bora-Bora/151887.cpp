// 09/12/19 // 9:10 PM //

#include <bits/stdc++.h>

using namespace std;

#define MAXP 20
#define pb push_back

struct carta{
    int val = 0, naipe = 0;

    carta(){};
    carta(int tval, int tnaipe){
        val   = tval;
        naipe = tnaipe;
    }

    bool operator> (const carta &temp){
        return ( val > temp.val || (val == temp.val && naipe > temp.naipe)  );
    }
    bool operator==(const carta &temp){
        return (val == temp.val || naipe == temp.naipe);
    }
};

int p, m, n;
int num_mao[MAXP];

queue<carta> saque;
vector<carta> mao[MAXP];

carta descarte;
int jatual, sentido;
bool efeito;

void proxJogador(){
    jatual = (jatual + sentido)%p >= 0 ? (jatual + sentido)%p : p + (jatual + sentido)%p;

    //cout << "proxJogador: " << jatual+1 << "\n";
}
void atualSaca(){
    mao[jatual].pb(saque.front());
    saque.pop();
}
void descartarCarta(){
    carta cMaior;
    int ind = -1;

    for(int i=0; i<mao[jatual].size(); i++){
        carta ctemp = mao[jatual][i];

        if(ctemp==descarte && ctemp>cMaior){
            cMaior = ctemp;
            ind = i;
        }

    }

    if(ind==-1){
        carta ctemp = saque.front();
        saque.pop();

        if(ctemp==descarte){
            descarte = ctemp;
            efeito = 1;
        }
        else{
            mao[jatual].pb(ctemp);
            num_mao[jatual]++;
        }

    }
    else{
        mao[jatual][ind] = carta(0,0);
        num_mao[jatual]--;

        descarte = cMaior;
        efeito = 1;
    }

}
carta recebe_carta(){

    carta tcarta;
    char tnaipe;

    cin >> tcarta.val >> tnaipe;

    if(tnaipe == 'C')
        tcarta.naipe = 1;
    else if(tnaipe == 'D')
        tcarta.naipe = 2;
    else if(tnaipe == 'H')
        tcarta.naipe = 3;
    else
        tcarta.naipe = 4;

    return tcarta;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    while(cin >> p >> m >> n){

        if(p==0)break;

        for(int i=0; i<p; i++){
            mao[i].clear();
            for(int j=0; j<m; j++)
                mao[i].pb(recebe_carta());

            num_mao[i] = m;
        }

        while(!saque.empty()) saque.pop();

        for(int i=0; i<n-p*m; i++) saque.push(recebe_carta());


        descarte = saque.front();
        saque.pop();
        jatual  = 0;
        sentido = 1;
        efeito = 1;
        int cont=0;

        //cout << "\nJogador: " << jatual+1 << "\n";
        //cout << descarte.val << " " << descarte.naipe << "\n\n";

        while(true){
            cont++;
            if(efeito){
                if(descarte.val==12){
                    sentido *= -1;
                    if(cont>1){
                        proxJogador();
                        proxJogador();
                    }

                }
                else if(descarte.val==7){
                    atualSaca();
                    atualSaca();
                    num_mao[jatual] += 2;
                    proxJogador();
                }
                else if(descarte.val==1){
                    //cout << "acao carta 1\n";
                    atualSaca();
                    num_mao[jatual] += 1;
                    proxJogador();
                }
                else if(descarte.val==11){
                    proxJogador();
                }
                efeito = 0;
            }

            descartarCarta();

            //cout << "Jogador: " << jatual+1 << "\n";
            //cout << "Sentido: " << sentido  << "\n";
            //cout << descarte.val << " " << descarte.naipe << "\n\n";

            if(num_mao[jatual]==0){
                cout << jatual + 1 << "\n";
                break;
            }


            proxJogador();
        }
    }

    return 0;
}
