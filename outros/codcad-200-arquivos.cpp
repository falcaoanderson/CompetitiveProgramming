#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, b_max, total=0;
vector<int> files;

int buscab(){
    int inicio, fim, meio, dif=-1, p_dif=-1;
    inicio=1;
    fim=n;

    while(inicio<=fim){
        meio=(inicio+fim)/2;

        int soma = files[1] + files[meio];
        if(soma==b_max) return meio;
        if(soma<b_max) inicio=meio+1;
        if(soma>b_max) fim=meio-1;

        if(soma>dif and soma<b_max){
            p_dif=meio;
            dif=soma;
        }
    }

    return p_dif;
}

int main(){
    cin >> n >> b_max;

    files.push_back(-10);
    for(int i=0; i<n; i++){
        int temp;
        cin >>temp;
        files.push_back(temp);
    }

    sort(files.begin(), files.end());

    while(n>0){
        int b = buscab();
        if(b>1){
            files.erase(files.begin()+b);
            n--;
        }

        files.erase(files.begin()+1);

        n--;
        total++;
    }
    cout << total << endl;

    return 0;
}
