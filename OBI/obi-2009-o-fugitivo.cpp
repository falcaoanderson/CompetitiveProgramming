// 22/02/19 // 10:46 PM //

#include <iostream>

using namespace std;

int n;
long long m, x=0, y=0;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    m = m*m;

    int dist;
    char direc;
    bool saida = 0;

    for(int i=0; i<n; i++){
        cin >> direc >> dist;

        if(!saida){

            if(direc=='N')
                y += dist;
            else if(direc=='S')
                y -= dist;
            else if(direc=='L')
                x += dist;
            else if(direc=='O')
                x -= dist;

            if( (x*x + y*y)> m) saida = 1;
        }
    }

    cout << saida << "\n";

    return 0;
}
