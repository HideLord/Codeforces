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

int main(){
    ios_base::sync_with_stdio(false);
    int Q;
    cin >> Q;
    while(Q--){
        int N;
        cin >> N;
        
        vector<int> S;
        string A;
        cin >> A;

        for(int i = 0; i < N; i++){
            if(A[i] == 'A')S.push_back(1);
            else S.push_back(0);
        }
        
            int steps = 0;
        while(1){
            bool ang = false;
            for(int i = 0; i+1 < S.size(); i++){
                if(S[i] && !S[i+1])S[i+1]=1, i+=1, ang = 1;
            }
            if(!ang){
                cout << steps << endl;
                break;
            }
            steps++;
        }
    }
}