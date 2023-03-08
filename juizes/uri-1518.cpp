// 22/08/19 // 11:42 PM //

#include <bits/stdc++.h>

using namespace std;

struct tartaruga{
    int x, y;
    char direcao;
};

#define MAXN 10
#define MAXT 200010
#define INF 0x3f3f3f3f

int temp_hx, temp_hy;
tartaruga v[MAXN];
vector<int> ordem = {1,2,3};

int tempo(float hx, float hy, float tx, float ty){
    return ceil( (abs(hx-tx) + abs(hy-ty))/2 );
}

int buscab(int i, int hx, int hy, int tx, int ty){
    int ini=1, fim=MAXT, meio, melhor;

    while(ini<=fim){
        int temp_tx = tx, temp_ty = ty;
        meio = (ini+fim)/2;

        if(v[i].direcao=='D') temp_tx += meio;
        else                  temp_ty += meio;

        int aux = tempo(hx, hy, temp_tx, temp_ty);

        if(meio >= aux){
            temp_hx = temp_tx;
            temp_hy = temp_ty;
            melhor = meio;
            fim = meio -1;
        }
        else
            ini = meio+1;
    }

    return melhor;
}


int main(){
    int ini_hx, ini_hy;

    cin >> ini_hx >> ini_hy;

    for(int i=0; i<3; i++)
        cin >> v[i].x >> v[i].y >> v[i].direcao;

    int resp = INF;

    for(int k=0; k<6; k++){
        int temp=0;
        temp_hx = ini_hx;
        temp_hy = ini_hy;

        for(int i=0; i<3; i++){
            int aux = ordem[i];

            if(v[aux].direcao=='D')
                temp += buscab(aux, temp_hx, temp_hy, v[aux].x + temp, v[aux].y       );
            else
                temp += buscab(aux, temp_hx, temp_hy, v[aux].x       , v[aux].y + temp);
        }

        resp = min(resp, temp);

        next_permutation(ordem.begin(),ordem.end());
    }

    cout << resp << "\n";

    return 0;
}
