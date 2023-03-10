#include <iostream>
#include <map>
using namespace std;

map<string, string> dic;
int m, n, t;
string pj, pp;

int main(){
    cin >> t;

    for(int j=0; j<t; j++){
        cin >> m >> n;
        cin.ignore();

        for(int i=0; i<m; i++){
            getline(cin, pj);
            getline(cin, pp);
            dic.insert(make_pair(pj,pp));
        }

        for(int i=0; i<n; i++){
            pp="";
            getline(cin, pj);
            for(int i=0; i<pj.size(); i++){
                if(pj[i]!=' '){
                    pp+=pj[i];
                }
                if(pj[i]==' ' or i==pj.size()-1){
                    if(dic.find(pp)!=dic.end())
                        cout << dic[pp] << ' ';
                    else
                        cout << pp << ' ';
                    pp="";
                }

            }
            cout << endl;
        }
        cout << endl;
        dic.clear();
    }
    return 0;
}
