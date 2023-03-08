// 26/09/19 // 8:23 PM //

#include <bits/stdc++.h>

using namespace std;

#define MAXN 20
#define pb push_back
#define mp make_pair

#define num first
#define naipe second
typedef pair<int, int> pii;

int total_jog, carta_jogador, total_pilha;

int sentido = 1, davez=0;
queue<pii> pilha;
vector<pii> deck[MAXN];

// paus - 1 // ouros - 2 // copas = 3 // espadas = 4 //

int mod(int a, int b){
    return ( (a%b>=0)? a%b: b+a%b);
}

void acao(pii carta){
    if(carta.num==12){
        sentido*=-1;
        davez = mod(davez+sentido, total_jog);
        davez = mod(davez+sentido, total_jog);
    }
    else if(carta.num==7){
        deck[davez].pb(pilha.front());
        pilha.pop();
        deck[davez].pb(pilha.front());
        pilha.pop();

        davez = mod(davez+sentido, total_jog);
    }
    else if(carta.num==1){
        deck[davez].pb(pilha.front());
        pilha.pop();

        davez = mod(davez+sentido, total_jog);
    }
    else if(carta.num==11){
        davez = mod(davez+sentido, total_jog);
    }
}

pii jogada(pii topo){
    pii c1=mp(-1,-1), c2=mp(-1,-1);
    int pc1=-1, pc2=-1;

    for(int i=0; i<deck[davez].size(); i++){
        pii temp = deck[davez][i];

        if(temp.num == topo.num && c1.naipe < temp.naipe){
            c1 = temp;
            pc1 = i;
        }
        if(temp.naipe == topo.naipe && c2.num < temp.num){
            c2 = temp;
            pc2 = i;
        }
    }

    if(c1.num==-1 && c2.num==-1){
        c1 = pilha.front();
        pilha.pop();

        if(c1.num == topo.num || c1.naipe == topo.naipe){
            return c1;
        }
        else{
            deck[davez].pb(c1);
            return mp(-1,-1);
        }
    }



    if(c1.num>c2.num){
        deck[davez].erase(pc1 + deck[davez].begin());
        return c1;
    }
    if(c2.num>c1.num){
        deck[davez].erase(pc2 + deck[davez].begin());
        return c2;
    }
    if(c1.naipe>c2.naipe){
        deck[davez].erase(pc1 + deck[davez].begin());
        return c1;
    }
    deck[davez].erase(pc2 + deck[davez].begin());
    return c2;
}

int main(){

    ios_base::sync_with_stdio(false);cin.tie(NULL);

    while(cin >> total_jog >> carta_jogador >> total_pilha){

        if(total_jog==0 && carta_jogador==0 && total_pilha==0) break;

        davez   = 0;
        sentido = 1;
        while(!pilha.empty()) pilha.pop();


        for(int i=0; i<total_pilha; i++){
            int tempn, tempn2;
            char tempc;

            cin >> tempn >> tempc;

            if     (tempc=='C') tempn2 = 1;
            else if(tempc=='D') tempn2 = 2;
            else if(tempc=='H') tempn2 = 3;
            else                tempn2 = 4;

            pilha.push( mp(tempn, tempn2) );
        }

        for(int i=0; i<total_jog; i++){
            deck[i].clear();
            for(int j=0; j<carta_jogador; j++){
                deck[i].pb(pilha.front());
                pilha.pop();
            }
        }
        //cout << davez <<"\n";
        pii descarte = pilha.front();
        pilha.pop();
        acao(descarte);

        bool aux=0;
        //cout << davez << "  -- "<<descarte.num << " - " << descarte.naipe << "\n";
        while(true){
            //cout << davez << "  -- "<<descarte.num << " " << descarte.naipe << "\n";
            if(aux) {
                acao(descarte);
                aux = 0;
            }

            pii temp = jogada(descarte);

            if(temp.num!=-1){
                if(deck[davez].size() == 0){
                    cout << davez+1 << "\n";
                    break;
                }

                aux = 1;
                descarte = temp;
            }


            davez = mod(davez+sentido, total_jog);
        }

    }

    return 0;
}

