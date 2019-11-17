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
    int da,db;
    cin >> da >> db;
    if(db==1 && da==9){
        cout << 9 << " " << 10 << endl;
    }
    if(db-da>1)cout << -1 << endl;
    else if(db-da<0)cout << -1 << endl;
    else{
        if(db-da==1){
            cout << da << "9 " << db << "0" << endl;
        }else{
            cout << da << "8 " << db << "9 " << endl;
        }
    }
}