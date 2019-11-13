#include <iostream>

using namespace std;

int main(){
    cin.tie(0);
    cout.tie(0);
    std::ios_base::sync_with_stdio(false);

    string s;
    int n;
    cin >> n;
    cin >> s;
    //zr eo n

    int br0 = 0,br1 = 0;
    for(int i = 0; i < s.size(); i++)
        if(s[i]=='z')br0++;
        else if(s[i] == 'n')br1++;

    for(int i = 0; i < br1; i++)cout << "1 ";
    for(int i = 0; i < br0; i++)cout << "0 ";
    cout << endl;
}
