#include <iostream>
#include <cmath>

using namespace std;

int n;
long long A[1001][1001];
int main(){
    cin.tie(0);
    cout.tie(0);
    std::ios_base::sync_with_stdio(false);

    cin >> n;
    for(int i = 0; i < n; i++)for(int j = 0; j < n; j++)cin >> A[i][j];

    long long a1 = round(sqrt((A[0][1]*A[0][2])/A[1][2]));

    cout << a1 << " ";

    for(int i = 1; i < n; i++)cout << round(A[0][i]/a1) << " ";
    cout << endl;
}
