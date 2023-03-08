// 20/09/2020 // 07:51 PM // 

#include <bits/stdc++.h>

using namespace std;

#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl "\n"

const int MAXN = (2e5) + 10;
const int INF  = 0x3f3f3f3f;

int n, m;
int seg[4*MAXN], v[MAXN];

void build(int no, int i, int j){
	int mid=(i+j)/2, left=2*no, right=2*no+1;
	
	if(i==j){
		seg[no] = i;
	}
	else{
		build(left, i, mid);
		build(right, mid+1, j);
		
		if(v[seg[left]]>=v[seg[right]])
			seg[no] = seg[left];
		else
			seg[no] = seg[right];
	}
} 
void update(int no, int i, int j, int pos, int sub){
	int mid=(i+j)/2, left=2*no, right=2*no+1;
	
	if(i==j){
		v[i] -= sub;
	}
	else{
		if(pos<=mid) update( left,     i, mid, pos, sub);
		else         update(right, mid+1,   j, pos, sub);
		
		if(v[seg[left]]>=v[seg[right]])
			seg[no] = seg[left];
		else
			seg[no] = seg[right];
	}
}

int bs_seg(int no, int i, int j, int val){
	int mid=(i+j)/2, left=2*no, right=2*no+1;
	
	if(i==j && v[i]>=val)
		return i;
	if(v[seg[left]]>=val)
		return bs_seg(left, i, mid, val);
	if(v[seg[right]]>=val)
		return bs_seg(right, mid+1, j, val);
	
	return 0;
}

int	main(){
	fast_io;
	
	cin >> n >> m;
	for(int i=1; i<=n; i++) cin >> v[i];
	
	build(1, 1, n);
	
	for(int i=1; i<=m ;i++){
		int temp, room;
		cin >> temp;
		
		room = bs_seg(1, 1, n, temp);
		
		cout << room << " ";
		
		if(room != 0) update(1, 1, n, room, temp);
	}
	cout << endl;
	
	return 0;
}
