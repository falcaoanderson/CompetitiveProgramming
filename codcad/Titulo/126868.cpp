#include <iostream>

using namespace std;

char maiusculo(char letra){
    if(int(letra)>=97 and int(letra)<=122){
        letra = char(int(letra) - 32);
    }
    return letra;
}
char minusculo(char letra){
    if(int(letra)>=65 and int(letra)<=90){
        letra = char(int(letra) + 32);
    }
    return letra;
}
string title(string F){
    for(int i=0; i<F.size(); i++){
        if(i==0){
            F[i] = maiusculo(F[i]);
        }
        else if(F[i-1]==' '){
            F[i] = maiusculo(F[i]);
        }
        else{
            F[i] = minusculo(F[i]);
        }
    }
    return F;
}

int main(){
	string F;

	getline(cin, F);

	cout<<title(F)<<"\n";

	return 0;
}