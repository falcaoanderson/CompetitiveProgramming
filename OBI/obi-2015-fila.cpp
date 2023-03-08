// 24/11/20 // xx:xx PM //

#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
#define pb push_back
#define mp make_pair
#define ll long long

typedef pair<int, int> pii;

const int INF  = 0x3f3f3f3f;
const int MAXN = 1200000 + 500;

int n, q, tam=0;
int op[MAXN], pos[MAXN], v[MAXN]; 
int bit[MAXN], seg[4*MAXN], h[MAXN];

void update(int i, int val){
    while(i<=tam){
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
int bs_bit(int val){
    int ind=0, sum=0;

    for(int i=30; i>=0; i--){
        if(ind+(1<<i)<=tam && sum+bit[ind+(1<<i)]<val){
            ind += (1<<i);
            sum += bit[ind];
        }
    }

    return ind+1;
}

void update_seg(int no, int i, int j, int k, int val){
    int l=2*no, r=2*no+1, mid=(i+j)/2;

    if(i==j){
        seg[no] = val;
    }
    else{
        if(k<=mid) update_seg(l, i, mid, k, val);
        else       update_seg(r, mid+1, j, k, val);

        seg[no] = max(seg[l], seg[r]);
    }
}

int bs_seg(int no, int i, int j, int k, int val){
    int l=2*no, r=2*no+1, mid=(i+j)/2;

    if(seg[no]<=val || k<=i) return 0;

    if(i==j) return i;

    if(k<=mid+1) return bs_seg(l, i, mid, k, val);

    if(seg[l]<=val) return bs_seg(r, mid+1, j, k, val);
    if(seg[r]<=val) return bs_seg(l, i, mid, k, val);

    if(j<=k && seg[r]>val) return bs_seg(r, mid+1, j, k, val);
    
    return max(bs_seg(l, i, mid, k, val), bs_seg(r, mid+1, j, k, val));
}

int main(){
    fast_io;

    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> v[i];
        pos[i] = i-1;
    }
    
    cin >> q;
    for(int i=n+1; i<=n+q; i++){
        cin >> op[i] >> pos[i] >> v[i];
        if(!op[i]) tam++;
    }
    tam += n;
    
    for(int i=1; i<=tam; i++) update(i, 1);
    
    for(int i=n+q; i>=1; i--){
        if(op[i]){
            pos[i] = bs_bit(pos[i]);
        }
        else{
            pos[i] = bs_bit(pos[i]+1);
            update(pos[i], -1);
        }
    }

    for(int i=1; i<=n+q; i++){
        if(op[i]){ // consulta
            int x = bs_seg(1, 1, tam, pos[i], h[pos[i]]+v[i]);
            
            cout << query(x) << endl;
        }
        else{ // atualizacao
            h[pos[i]] = v[i];
            update(pos[i], 1);
            update_seg(1, 1, tam, pos[i], v[i]);
        }
    }

    return 0;
}
