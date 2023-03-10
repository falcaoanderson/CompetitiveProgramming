#include <iostream>

using namespace std;

string title(string F){
    for(int i=0; i<F.size(); i++){
        if(int(F[i])>=97 and int(F[i])<=122 and (i==0 or F[i-1]==' ')){
            F[i]= char(int(F[i]) - 32);
        }
        else if(int(F[i])>=65 and int(F[i])<=90 and i!=0 and F[i-1]!=' '){
            F[i]= char(int(F[i]) + 32);
        }
    }
    return F;
}

int main(){
	string F;

	getline(cin, F);

	cout<<title(F)<<"\n";
}