#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 105
using namespace std;

int dup[MAXN][MAXN];

int main(){
    int n, m, x, y;
    int soma=-1, tsoma, banda[3];

    while(true){
        soma=-1;

        scanf("%d%d",&n, &m);
        if(n==0 and m==0){break;}

        memset(dup, 0, sizeof(dup));

        for(int i=0; i<m; i++){
            scanf("%d%d%d",&x, &y, &tsoma);
            x--;y--;
            dup[x][y]= dup[y][x] = tsoma;
        }

        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                for(int z=j+1; z<n; z++){
                    tsoma = dup[i][j] + dup[i][z] + dup[j][z];
                    if(tsoma > soma){
                        soma = tsoma;
                        banda[0]=i; banda[1]=j; banda[2]=z;
        }}}}

        sort(banda,banda+3);
        printf("%d %d %d\n", banda[0]+1, banda[1]+1, banda[2]+1);
    }
    return 0;
}
