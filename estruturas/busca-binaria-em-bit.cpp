// 03/09/2020 // 06:29 // 

#include <bits/stdc++.h>

using namespace std;

#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl "\n"
//#define int long long

const int MAXN = (2e5) + 10;
const int MOD  = (1e9) + 7;
const int INF  = 0x3f3f3f3f;

int n, bit[MAXN];

void update(int i, int val){
	while(i<=n){
		bit[i] += val;
		i += (i&-i);
	}
}
int query(int i){
	int sum=0;
	while(i>0){
		sum += bit[i];
		i -= (i&-i);
	}
	return sum;
}

int bb_bit(int val){
	
	int sum=0, pos=0;
	
	for(int i=30; i>=0; i--){
		if(pos+(1<<i)<=n && sum+bit[pos+(1<<i)]<=val){
			pos += (1<<i);
			sum += bit[pos]; 
		}
	}
	
	return pos;
}

int	main(){
	fast_io;
	
	cin >> n;
	for(int i=1; i<=n; i++){
		int a;
		cin >> a;
		update(i, a);
	}
	
	for(int i=1; i<=n; i++)
		cout << query(i) << " ";
	cout << endl;
	
	return 0;
}
