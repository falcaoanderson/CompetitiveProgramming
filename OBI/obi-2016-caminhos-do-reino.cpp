// 19/09/19 // 11:23 AM //

#include <bits/stdc++.h>

using namespace std;

#define MAXN 100010

int n, q;
int dist_per[MAXN];              // distancia ate o ciclo
int pos_ciclo[MAXN];             // posicao no ciclo

int dist_ciclo[MAXN], tam_ciclo=0; // para os nos do ciclo

int filho[MAXN], qnt_pais[MAXN];                 // destino da estrada que sai da cidade

void dfs_ciclo(int i){
    tam_ciclo++;
    pos_ciclo[i] = i;
    dist_per[i]  = 0;

    if(pos_ciclo[filho[i]]==filho[i]){ // se o filho ja foi visitado ele eh o começo do ciclo
        dist_ciclo[i] = 1;
        return;
    }

    dfs_ciclo(filho[i]);

    dist_ciclo[i] = dist_ciclo[filho[i]] + 1;
    if(dist_ciclo[i]==tam_ciclo)dist_ciclo[i]=0;
}

void dfs_per(int i){

    if(qnt_pais[i]>1){ // se esse vertice faz parte do ciclo, significa que sai da periferia
        if(pos_ciclo[i]==0) dfs_ciclo(i); // se o ciclo ainda nao foi visitado eu faço
        return;
    }

    // se nao eu chamo o dfs para meu filho

    dfs_per(filho[i]);

    pos_ciclo[i] = pos_ciclo[filho[i]]; // a saida da periferia de i e igual a saida da periferia de filho[i]
    dist_per[i] = dist_per[ filho[i] ] + 1; // a distancia ate a saida e igual a distancia do filho ate a saida + 1
}

void debug(){
    cout << "\ntamanho do ciclo: " << tam_ciclo << "\n\n";
    for(int i=1; i<=n; i++){
        cout << i << " Posicao no ciclo: " <<pos_ciclo[i] << "\n";

        if(pos_ciclo[i]==i){
            cout << "distancia no ciclo: "<<dist_ciclo[i] << "\n";
        }
        else{
            cout << "distancia ATE o ciclo: " << dist_per[i] << "\n";
        }

        cout << "\n";
    }
}

int mod(int a, int b){
    return (a%b>=0? a%b : b + a%b);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    for(int i=1; i<=n; i++){
        cin >> filho[i];

        qnt_pais[filho[i]]++;
    }

    for(int i=1; i<=n; i++){
        if(qnt_pais[i]==0){
            dfs_per(i);
        }
    }

    //debug();


    cin >> q;

    for(int i=0; i<q; i++){
        int a, b;

        cin >> a >> b;

        if(pos_ciclo[a]==pos_ciclo[b] && pos_ciclo[a]!=a && pos_ciclo[b]!=b){ // se os dois estao em uma mesma periferia
            cout << abs(dist_per[a]-dist_per[b]) << "\n";
        }
        else{
            int tempda = dist_per[a];
            int tempdb = dist_per[b];

            a = pos_ciclo[a];
            b = pos_ciclo[b];

            int resp = min( max(tempda, tempdb + mod(dist_ciclo[b]-dist_ciclo[a], tam_ciclo) ),
                            max(tempda + mod(dist_ciclo[a]-dist_ciclo[b], tam_ciclo), tempdb) );

            cout << resp << "\n";
        }

    }

    return 0;
}
