#include <iostream>
#include <cmath>
using namespace std;

int main(){
    cin.tie(0);
    cout.tie(0);
    std::ios_base::sync_with_stdio(false);

    string s;
    cin >> s;
    bool bigger = false;
    for(int i = 1; i < s.size(); i++)bigger += (s[i] == '1');
    cout << ceil(s.size()/2.0) - (s.size()%2 && !bigger) << endl;
}
