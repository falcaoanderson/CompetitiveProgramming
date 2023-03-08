#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 105
using namespace std;

int dup[MAXN][MAXN];

int main(){
    int n, m, x, y;
    int soma=-1, tsoma, banda[3];


    soma=-1;
    //cin >> n >> m;
    scanf("%d%d",&n, &m);

    for(int i=0; i<m; i++){
        //cin >> x >> y >> tsoma;
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
                }
            }
        }
    }

    sort(banda,banda+3);
    //cout <<  banda[0]+1 << " " << banda[1]+1 << " " << banda[2]+1 << endl;
    printf("%d %d %d\n", banda[0]+1, banda[1]+1, banda[2]+1);

    return 0;
}
