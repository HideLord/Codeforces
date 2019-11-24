#include <bits/stdc++.h>
#define all(x) (x).begin(),(x).end()
#define sz(x) int((x).size())
#define mp make_pair
 
using namespace std;
 
typedef long long ll;
typedef pair<int,int> ii;
typedef vector<ii> vii;
 
template<class T>
ostream& operator<<(ostream& out, vector<T> V){
    for(auto &i:V)out << i << " ";
    return out;
}
 
vector<int> V;
int inTime;
vector<int> sol;
 
    unordered_set<int> U;
    unordered_set<int> S;
int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        int a;
        cin >> a;
        V.push_back(a);
    }
    int sum = 0;
    if(n%2){
        cout << -1 << endl;
        return 0;
    }
    for(int i = 0,br=0; i < n; i++){
        if(V[i]>0){
            br++;
            if(S.count(V[i])){
                cout << -1 << endl;
                return 0;
            }
            S.insert(V[i]);
            U.insert(V[i]);
        }else{
            if(!U.count(-V[i])){
                cout << -1 << endl;
                return 0;
            }
            U.erase(-V[i]);
            br++;
            if(U.empty()){
                S.clear();
                sol.push_back(br);
                br = 0;
            }
        }
    }
    if(!U.empty()){
        cout << -1 << endl;
        return 0;
    }
    cout << sol.size() << endl;
    cout << sol << endl;
}