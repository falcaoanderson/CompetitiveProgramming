/*
09/02/26 

*/

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define endl "\n"
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
#define PB push_back
#define EB emplace_back
#define FF first
#define SS second
#define SZ(x) (int)(x).size()

typedef pair<int, int> pii;
typedef tuple<int, int, int> tiii;

const int INF  = 0x3f3f3f3f;
const  ll LINF = 0x3f3f3f3f3f3f3f3f;
const int MAXN = (2e5) + 5;
const int MOD  = (1e9) + 7;

struct Node{
    int id;
    Node *ptrNext, *ptrPrev;

    Node(int id) : id(id), ptrNext(nullptr), ptrPrev(nullptr) {}
};

struct LinkedList{
    int sz;
    Node *ptrFront, *ptrBack;

    LinkedList() : sz(0), ptrFront(nullptr), ptrBack(nullptr) {}
 
    ~LinkedList() {
        Node* current = ptrFront;
        while (current != nullptr) {
            Node* next = current->ptrNext;
            delete current;
            current = next;
        }
    }
 
    void push_back(int x){
        Node *aux = new Node(x);
        sz++;
        if(ptrFront == nullptr){
            ptrFront = aux;
            ptrBack = aux;
        }
        else{
            ptrBack -> ptrNext = aux;
            aux->ptrPrev = ptrBack;
            ptrBack = aux;    
        }
    }

    bool empty(){
        return sz == 0;
    }

    void remove(Node* ptrRemove){
        sz--;

        if(ptrRemove != ptrFront)
            ptrRemove -> ptrPrev -> ptrNext = ptrRemove -> ptrNext;
        else{
            ptrFront = ptrRemove -> ptrNext;
        }

        if(ptrRemove != ptrBack)
            ptrRemove -> ptrNext -> ptrPrev = ptrRemove -> ptrPrev;
        else{
            ptrBack = ptrRemove -> ptrPrev;
        }

        delete ptrRemove;
    }
};


void solve(){
    int n;
    cin >> n;
    vector<int> a(n), d(n);
    for(int i=0; i<n; i++) cin >> a[i];
    for(int i=0; i<n; i++) cin >> d[i];

    LinkedList v;
    queue<Node*> toCheck;
    for(int i=0; i<n; i++){
        v.push_back(i);
        toCheck.push(v.ptrBack);
    }

    vector<int> ans(n);
    for(int i=0; i<n && v.sz > 1; i++){
        // cout << "Round " << i << endl;
        vector<Node*> toRemove;

        while(!toCheck.empty()){
            Node *ptrCrr = toCheck.front();
            toCheck.pop();

            int crrDamage = 0;
            if(ptrCrr->ptrPrev != nullptr) crrDamage += a[ptrCrr->ptrPrev->id];
            if(ptrCrr->ptrNext != nullptr) crrDamage += a[ptrCrr->ptrNext->id];

            if(crrDamage > d[ptrCrr -> id]){
                toRemove.push_back(ptrCrr);
            }
        }
        // cout << "toRemove: " << SZ(toRemove) << endl;
        if(toRemove.empty()) break;

        Node* ptrLast = nullptr;
        for(int j = 0; j < SZ(toRemove); j++){
            Node* ptrCrr = toRemove[j];

            if(ptrCrr->ptrPrev != nullptr && ptrCrr->ptrPrev != ptrLast){
                toCheck.push(ptrCrr->ptrPrev);
                ptrLast = ptrCrr->ptrPrev;
            }
            if(ptrCrr->ptrNext != nullptr && (j == SZ(toRemove)-1 || ptrCrr->ptrNext != toRemove[j+1])){
                toCheck.push(ptrCrr->ptrNext);
                ptrLast = ptrCrr->ptrNext;
            }

            v.remove(ptrCrr);
        }

        ans[i] = toRemove.size();
    }

    for(int x: ans) cout << x << " ";
    cout << endl;
}

int main(){
    fast_io;

    int t;
    cin >> t; 
    while(t--) solve();

    return 0;
}
