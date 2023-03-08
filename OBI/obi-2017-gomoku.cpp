#include <iostream>
using namespace std;

int main(){
    int m[15][15];
    int i,j,x=0,y=0;
    int ta=0,tn=0,c=1,r=0;

    for(i=0; i<15; i++){
        for(j=0; j<15; j++){
            cin>>m[i][j];
        }
    }

// linhas

    for(i=0; i<15; i++){
        for(j=0; j<15; j++){
            tn=m[i][j];
            if(tn==ta and tn!=0){
                c+=1;
            }else{
                c=1;
            }
            if(c==5){
                r=tn;
                break;
            }
            ta=tn;
        }
        ta=0;
        if(c==5){c=1;break;}
        c=1;
    }

//  colunas
    for(j=0; j<15; j++){
        for(i=0; i<15; i++){
            tn=m[i][j];
            if(tn==ta and tn!=0){
                c+=1;
            }else{
                c=1;
            }
            if(c==5){
                r=tn;
                break;
            }
            ta=tn;
        }
        ta=0;
        if(c==5){c=1;break;}
        c=1;
    }
// diagonais esquerda para direita
    //linha
    for(i=0; i<15; i++){
        y=i;
        while(x<15 and y<15){
            tn=m[x][y];
            if(tn==ta and tn!=0){
                c+=1;
            }else{
                c=1;
            }
            if(c==5){
                r=tn;
                break;
            }
            ta=tn;
            x+=1;
            y+=1;
        }
        x=0;
        y=0;
        ta=0;
        if(c==5){c=1;break;}
        c=1;
    }
    //coluna
    for(i=0; i<15; i++){
        x=i;
        while(x<15 and y<15){
            tn=m[x][y];
            if(tn==ta and tn!=0){
                c+=1;
            }else{
                c=1;
            }
            if(c==5){
                r=tn;
                break;
            }
            ta=tn;
            x+=1;
            y+=1;
        }
        x=0;
        y=0;
        ta=0;
        if(c==5){c=1;break;}
        c=1;
    }
// diagonais direita para esquerda
    //linha
    for(i=14; i>=0; i--){
        y=i;
        while(x<15 and y>=0){
            tn=m[x][y];
            if(tn==ta and tn!=0){
                c+=1;
            }else{
                c=1;
            }
            if(c==5){
                r=tn;
                break;
            }
            ta=tn;
            x+=1;
            y-=1;
        }
        x=0;
        y=0;
        ta=0;
        if(c==5){c=1;break;}
        c=1;
    }
    //coluna
    for(i=0; i<15; i++){
        x=i;
        y=14;
        while(x<15 and y>=0){
            tn=m[x][y];
            if(tn==ta and tn!=0){
                c+=1;
            }else{
                c=1;
            }
            if(c==5){
                r=tn;
                break;
            }
            ta=tn;
            x+=1;
            y-=1;
        }
        ta=0;
        if(c==5){c=1;break;}
        c=1;
    }

    cout<<r;
    return 0;
}
