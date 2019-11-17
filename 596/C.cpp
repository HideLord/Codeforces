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

int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    int n,p;
    cin >> n >> p;
    for (int k=0; k<=200000; k++) {
		int t=n-p*k;
		int br=0;
		while (t) {
			br+=(t&1);
			t>>=1;
		}
		if (br<=k && k<=n-p*k) { 
            cout << k << endl;
            return 0; 
        }
	}
    cout << -1 << endl;
}