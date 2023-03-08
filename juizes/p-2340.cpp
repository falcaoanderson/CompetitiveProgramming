#include <cstdio>
#include <string>
using namespace std;

int main(){
    char numero[6];

    scanf("%s",&numero);

    if((numero[0]-'0')%2==0){
        printf("%d\n",stoi(numero)+2);
    }else{
        printf("%d\n",stoi(numero)+1);
    }
    return 0;
}
