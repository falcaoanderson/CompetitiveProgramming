#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int p, s, u, v;
    pair<int,int> parte[5010];

    cin >> p >> s;

    for(int i=0; i<s; i++){
        cin >> parte[i].first >> parte[i].second;
    }

    sort(parte,parte+s);

    for(int i=0; i<s-1; i++){
        if(parte[i].second==0){continue;}

        for(int j=i+1; j<s; j++){
            if(parte[i].second>=parte[j].first){
                if(parte[j].second > parte[i].second){
                    parte[i].second = parte[j].second;
                }
                parte[j].first=0;
                parte[j].second=0;
            }
            else{break;}
        }
    }

    for(int i=0; i<s; i++){
        if(parte[i].second!=0){
            cout << parte[i].first << " " << parte[i].second << endl;
        }
    }


    return 0;
}