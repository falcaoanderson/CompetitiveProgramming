// 04/04/23 //
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>
#include <tuple>
 
using namespace std;
 
#define endl "\n"
#define PB push_back
#define EB emplace_back
#define ff first
#define ss second

typedef pair<int, int> pii;
typedef tuple<int, int, int> tiii;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;

    vector<tiii> events;

    for(int i=1; i<=n; i++){
        int a, b;
        cin >> a >> b;

        events.EB(a, -i, b);
        events.EB(b,  i, a);
    }

    sort(events.begin(), events.end());

    int curr_rooms=0, max_rooms=0;

    set<pii> oc_rooms; // min_queue
    queue<int> empty_rooms;

    vector<pii> resp;
    
    for(tiii ev: events){
        int a, b, ind;
        tie(a, ind, b) = ev;
        
    
        //cout << a << " " << ind << endl;
        
        
        if(ind<0){ //entrada            
            if(curr_rooms == max_rooms){
                max_rooms++;
                curr_rooms++;

                oc_rooms.emplace(b, curr_rooms);

                resp.EB(-ind, curr_rooms);
            }
            else{
                curr_rooms++;

                oc_rooms.emplace(b, empty_rooms.front());

                resp.EB(-ind, empty_rooms.front());

                empty_rooms.pop();
            }
        }
        else{ //saida
            curr_rooms--;

            auto it = oc_rooms.begin();

            empty_rooms.push(it->second);

            oc_rooms.erase(it);
        }
        
    }

    sort(resp.begin(), resp.end());

    cout << max_rooms << endl;
    for(pii i: resp){
        cout << i.ss << " ";
    }
    cout << endl; 

    return 0;
}