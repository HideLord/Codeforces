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
 
        vector<int> A,B;
 
int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    
    int Q;
    cin >> Q;
    while(Q--){
        int n;
        cin >> n;
        A.resize(n);
        B.resize(n);
        for(int i = 0; i < n; i++)cin>>A[i];
        for(int i = 0; i < n; i++)cin>>B[i];
        int k, prev = 0,br=0;
        for(int i = 0; i < n; i++){
            int dif = A[i]-B[i];
            if(dif!=prev)br++;
            if(dif>0)br=1000;
            prev = dif;
        }
        br+=prev!=0;
        if(br==2||br==0)cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}