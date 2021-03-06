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

struct A{
    A() {}
    A(int a) : m_a(a){}
    virtual ~A(){}

    int get(){
        return m_a;
    }
private:
    int m_a;
};

template<typename T, T t>
class B{
    const static T value = t;
};

void use(A foo){
    cout << foo.get() << endl;
}

int main(){
    cout << sizeof(B<A, 42>) << endl;
}