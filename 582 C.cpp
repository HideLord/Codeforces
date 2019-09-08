#include <iostream>
#include <stack>
#include <vector>
using namespace std;

vector<int> matrix[11];
int sum[11] = {0};
int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    for(int i = 1; i < 10; i++){
        bool used[11] = {0};
        for(int j = i; j < 10000; j+=i){
            if(used[j%10])break;
            used[j%10] = 1;
            matrix[i].push_back(j%10);
            sum[i]+=(j%10);
        }
    }
    long long n, m, q;
    cin >> q;
    while(q--){
        cin >> n >> m;
        if(m%10 == 0){
            cout << 0 << endl;
            continue;
        }
        long long res = ((n/m)/matrix[m%10].size())*sum[m%10];
        for(int i = 0; i < (n/m)%matrix[m%10].size(); i++){
            res += matrix[m%10][i];
        }
        cout << res << endl;
    }
}


