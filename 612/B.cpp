#include <bits/stdc++.h>
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)((x).size())
#define mp make_pair

using namespace std;

typedef unsigned long long ull;
typedef pair<int,int> ii;

template<class U,class T>ostream& operator<<(ostream& out, pair<U,T> & P){
    return out << "[" << P.first << ", " << P.second << "]";
}
template<class T>ostream& operator<<(ostream& out, vector<T> & V){
    if(!V.empty())out << "[";
    for(int i = 0; i < sz(V); i++)out << V[i] << (i+1==sz(V)?"]":", ");
    return out;
}

int n,k;

vector<string> V;

unordered_map<string,int> M;

int solve(){
    int ans = 0;
    for(int i = 0; i < V.size(); i++){
        for(int j = i+1; j < V.size(); j++){
            bool dif = false;
            string S(k,'-');
            for(int p = 0; p < k; p++){
                if(V[i][p]!=V[j][p]){
                    if(V[i][p] != 'S' && V[j][p] != 'S') S[p] = 'S';
                    if(V[i][p] != 'E' && V[j][p] != 'E') S[p] = 'E';
                    if(V[i][p] != 'T' && V[j][p] != 'T') S[p] = 'T';
                    dif = true;
                }else{
                    S[p] = V[i][p];
                }
            }
            auto it = lower_bound(V.begin() + j, V.end(),S);
            auto it2 = upper_bound(it, V.end(),S);
            if(dif)ans += distance(it,it2);
            else ans += distance(it,it2)-2;
        }
    }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin >> n >> k;
    V.resize(n);
    for(int i = 0; i < n; i++){
        cin >> V[i];
    }
    sort(all(V));
    cout << solve() << endl;
}