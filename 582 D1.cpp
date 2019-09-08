#include <iostream>
#include <stack>
#include <vector>
#include <map>
#include <set>
using namespace std;

int M[100001][20];

int calc(int j, int k){
    int res = 0;
    for(int i = 0; i < 20; i++){
        res += min(M[j][i],k)*i;
        k = max(k-M[j][i],0);
        if(k==0)break;
    }
    if(k)return 10000000;
    return res;
}

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int n, k, maxi = -123123123;
    cin >> n >> k;
    for(int i = 0; i < n; i++){
        int a, br = 0;
        cin >> a;
        maxi = max(maxi,a);
        while(a){
            M[a][br]++;
            a/=2;
            br++;
        }
    }
    int mini = 10000000;
    for(int i = 0; i <= maxi; i++){
        mini = min(mini,calc(i,k));
    }
    cout << mini << endl;
}



