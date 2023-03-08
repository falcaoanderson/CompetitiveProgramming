// 28/08/19 // 9:30 //

#include <bits/stdc++.h>

using namespace std;

#define MAXN 200010
#define mp make_pair
#define INF 0x3f3f3f3f3f3f3f3f
#define ll long long

int n;
ll value[MAXN];
ll lazy[3*MAXN];
pair<ll, int> seg[3*MAXN]; // first = value / second = index //

void build(int no, int i, int j){
    if(i==j){
        seg[no].first  = value[i];
        seg[no].second = i;
    }
    else{
        int mid   = (i+j)/2;
        int left  = 2*no;
        int right = 2*no+1;

        build( left,     i, mid);
        build(right, mid+1,   j);

        if( seg[left].first < seg[right].first){
            seg[no].first  = seg[left].first;
            seg[no].second = seg[left].second;
        }
        else{
            seg[no].first  = seg[right].first;
            seg[no].second = seg[right].second;
        }
    }
}

void push(int no, int i, int j){
    int mid   = (i+j)/2;
    int left  = 2*no;
    int right = 2*no+1;

    seg[no].first += lazy[no];

    if(i!=j){
        lazy[left]  += lazy[no];
        lazy[right] += lazy[no];
    }

    lazy[no] = 0;
}

void update(int no, int i, int j, int a, int b, ll sum){
    int mid   = (i+j)/2;
    int left  = 2*no;
    int right = 2*no+1;

    if(lazy[no]) push(no, i, j);

    if(i>j || a>b || b<i || j<a){
        return;
    }
    else if(a<=i && j<=b){
        lazy[no] += sum;

        push(no, i, j);
    }
    else{
        update( left,     i, mid, a, b, sum);
        update(right, mid+1,   j, a, b, sum);

        if( seg[left].first < seg[right].first){
            seg[no].first  = seg[left].first;
            seg[no].second = seg[left].second;
        }
        else{
            seg[no].first  = seg[right].first;
            seg[no].second = seg[right].second;
        }
    }
}

pair<ll, int> query(int no, int i, int j, int a, int b){
    int mid   = (i+j)/2;
    int left  = 2*no;
    int right = 2*no+1;

    if(lazy[no]) push(no, i, j);

    if(i>j || b<i || j<a){
        return mp(-1,-1);
    }
    else if(a<=i && j<=b){
        return seg[no];
    }
    else{
        pair<ll, int> op_left, op_right;

        op_left  = query( left,     i, mid, a, b);
        op_right = query(right, mid+1,   j, a, b);

        if(op_left.first==-1)  return op_right;
        if(op_right.first==-1) return op_left;

        if(op_left.first<op_right.first)
            return op_left;
        else
            return op_right;
    }
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    for(int i=1; i<=n; i++)
        cin >> value[i];

    build(1, 1, n);

    int resp[MAXN];

    for(int i=1; i<=n; i++){
        pair<ll,int> temp = query(1, 1, n, 1, n);          //acho o primeiro 0 a direita

        resp[ temp.second ] = i;                           // salvo o numero que ele representa

        update(1, 1, n,   temp.second, temp.second,  INF); // defino ele como INF na seg para n repetir
        update(1, 1, n, temp.second+1,           n,   -i); // retiro ele de todos os elementos a direita dele
    }

    for(int i=1; i<=n; i++)
        cout << resp[i] << " ";
    cout << "\n";

    return 0;
}
