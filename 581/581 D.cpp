#include <iostream>

using namespace std;

int main() {
    cin.tie(0);
    std::ios::sync_with_stdio(false);

    string s;
    cin >> s;

    int n = s.size();

    int dp0[n+1] = {0};
    int dp1[n + 1] = {0};

    for(int i = n-1; i >= 0; i--){
        if(s[i] == '0'){
          dp0[i] = max(dp0[i + 1], dp1[i + 1]) + 1;
          dp1[i] = dp1[i + 1];
        }else{
          dp0[i] = dp0[i + 1];
          dp1[i] = dp1[i + 1] + 1;
        }
    }
    string ans(n, 0);
    for(int i = n-1; i >= 0; i--){
        int x = max(dp0[i], dp1[i]);
        int y = max(dp0[i + 1], dp1[i + 1]);
        ans[i] = x > y ? '0' : s[i];
    }
    cout << ans << endl;
}
