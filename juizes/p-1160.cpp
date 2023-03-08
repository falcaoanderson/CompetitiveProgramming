#include <cstdio>
#include <cmath>
using namespace std;

float distancia(int x1,int y1,int x2, int y2){
    return sqrt(pow((x1-x2),2) + pow((y1-y2),2));
}


int main(){
    int x2,y2;

    scanf("%i%i",&x2,&y2);

    printf("Distancia para Hogsmeade: %.2f\n",distancia(x2,y2,34,220));
    printf("Distancia para Kakariko: %.2f\n",distancia(x2,y2,0,0));
    printf("Distancia para Solitude: %.2f\n",distancia(x2,y2,140,456));

    return 0;
}
