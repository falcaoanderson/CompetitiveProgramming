// 15/06/20 // 11:40 PM //

#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define pb push_back

const int MAXN = 1e5 + 10;
const int INF  = 0x3f3f3f3f;

int n;
map<string, int> files;
vector<int> grafo[MAXN];
int tam[MAXN], pai[MAXN], qnt[MAXN];

int pre_dfs(int no){
	if((int)grafo[no].size() == 0) return 1;
	
	for(int adj: grafo[no]){
		qnt[no] += pre_dfs(adj);
	}
	
	tam[no] = tam[no]*max(qnt[no], 1);
	for(int adj: grafo[no]){
		tam[no] += tam[adj];
	}
	
	return qnt[no];
}

int dfs(int no){
	int sum = 0;
	
	for(int adj: grafo[no]){
		sum += tam[adj];
	}
	
	if(no!=1){
		sum += dfs(pai[no]) + 3*(qnt[1]-qnt[no]) - tam[no];
	}
	
	return sum;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n;
	
	tam[1] = 0;
	int cont = 1;
	
	for(int i=0; i<n; i++){
		string dir;
		cin >> dir;
		
		string temp="";
		int ant = 1;
		
		for(char c: dir){
			temp += c;
			
			if(c == '/'){
				if(files.find(temp)==files.end()){
					files[temp] = (++cont);
					tam[cont] = temp.size();
					
					grafo[ant].pb(cont);
					pai[cont] = ant;
				}
			
				ant = files[temp];
				temp = "";
			}
		}
		files[temp] = (++cont);
		tam[cont] = temp.size();
		grafo[ant].pb(cont);
		pai[cont] = ant;
	}
	
	pai[1] = 1;
	pre_dfs(1);
	
	int resp = INF;
	for(int i=1; i<=cont; i++){
		if(qnt[i]>0) resp = min(resp, dfs(i));
	}
	
	cout << resp << endl;
	
    return 0;
}

