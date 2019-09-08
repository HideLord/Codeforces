#include <iostream>
using namespace std;

int main(){
    int n, br = 0;
    cin >> n;
    for(int i = 0; i < n; i++){
        int a;
        cin >> a;
        br += (a%2);
    }
    cout << min(br,n-br) << endl;
}
