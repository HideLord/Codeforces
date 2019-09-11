#include <iostream>
#include <map>
#include <vector>

using namespace std;

string s,t;
map<int,int> mem[200001];
int mem2[200001];
/*
zywmerhahxlqsjekpqsdqxnjiduyjrytswiweohctztgpiorwimhjmdfofqynyggcrtzslbyvkuvqrsgwyacyvcuathplliwwshusluiqwuhutnzwvuchfedhwwfdzizltdxibtsaocpnqezstblgkfdcvfsjjyzwalkksumsaljqljmmkcyejwwdkolmcgmodoiclte
zywmehahxlqjekqsdqjidytswwztgiowimhmffqygctzslbykurwacyvcuaplwshsluiqwuhutnwchfewwfdizttcpnqestgkfvsjylkksumaljmmkcjwwdkolmcgodcle
*/
int findlast(int m) {
    if(mem2[m])
        return mem2[m];
    int k = t.size()-1;
    if(k==m)
        return mem2[m] = s.size()-1;
    for(int i = s.size()-1; i >= 0; i--) {
        k -= (s[i] == t[k]);
        if(k == m)
            return mem2[m] = i;
    }
    return mem2[m] = -1;
}

int rec(int prev, int m) {
    if(mem[prev][m])
        return mem[prev][m];
    if(m==t.size())
        return s.size() - prev;
    if(prev >= int(s.size()))
        return -1;

    int maxi = -1;
    for(int i = prev; i < s.size(); i++)
        if(s[i] == t[m]) {
            int p = rec(i+1,m+1);
            if(p>=0)
                maxi =max(maxi,max(i-prev, p));
            break;
        }
    if(mem2[m] >= prev) {
        int i = mem2[m];
        int p = rec(i+1,m+1);
        if(p>=0)
            maxi = max(maxi,max(i-prev, p));
    }

    return mem[prev][m] = maxi;
}

int main() {
    cin.tie(0);
    cout.tie(0);
    std::ios_base::sync_with_stdio(false);

    cin >> s >> t;

    int n = s.size(), m = t.size();
    vector<int> a(n+1), b(n+1);
    int idx = 0;
    for(int i = 0; i < n; i++){
        if(idx<m&&s[i]==t[idx]){
            ++idx;
            a[i+1]=idx;
        }
        else a[i+1]=a[i];
    }
    idx = 0;
    for(int i = n-1; i>=0;--i){
        if(idx<m&&s[i]==t[m-1-idx]){
            ++idx;
            b[i]=idx;
        }
        else b[i]=b[i+1];
    }
    int ans = 0;
    for(int i = 0; i <= n; i++){
        int idx = lower_bound(a.begin(), a.end(), m-b[i])-a.begin();
        ans = max(ans,i-idx);
    }
    cout<<ans<<endl;
    return 0;
}
