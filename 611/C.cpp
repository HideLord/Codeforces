#include <bits/stdc++.h>
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)((x).size())
#define mp make_pair

using namespace std;

typedef unsigned long long ull;
typedef pair<int,int> ii;

template<class U,class T>ostream& operator<<(ostream& out, pair<U,T> & P){
    return out << "[" << P.first << ", " << P.second << "]";
}
template<class T>ostream& operator<<(ostream& out, vector<T> & V){
    if(!V.empty())out << "[";
    for(int i = 0; i < sz(V); i++)out << V[i] << (i+1==sz(V)?"]":", ");
    return out;
}

vector<int> F;
set<int> receive;
set<int> give;
int N;
inline int read()
{
	char ch=getchar();
	int s=0;
	while(ch<'0'||ch>'9') ch=getchar();
	while(ch>='0'&&ch<='9')
	{
		s*=10;
		s+=ch-48;
		ch=getchar();
	}
	return s;
}
inline void write(int a)
{
    if(a>=10) write(a/10);
    putchar(a%10+48);
}

int main(){
    N = read();
    F.resize(N+1);
    for(int i = 1; i <= N; i++)receive.insert(i),give.insert(i);
    for(int i = 1; i <= N; i++){
        F[i] = read(), receive.erase(F[i]);
        if(F[i]) give.erase(i);
    }
    for(int g = 1; g <= N; g++){
        if(F[g])continue;
        if(!receive.count(g))continue;
        for(auto r:receive){
            if(g!=r){
                F[g] = r;
                receive.erase(r);
                break;
            }
        }
    }

    for(auto g:give){
        if(F[g])continue;
        for(auto r:receive){
            if(g!=r){
                F[g] = r;
                receive.erase(r);
                break;
            }
        }
    }
    for(int i = 1; i <= N; i++)write(F[i]),putchar(' ');
}