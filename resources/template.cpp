/*
 * Author : $%U%$
 * Created at $%Y%$-$%M%$-$%D%$ $%h%$:$%m%$:$%s%$
 * powered by codeforce cli
 */

// == FLAGS == //
#define _ISTC                   // remove this to solve non-multiple test problem
#define _NO_NEED_64INT          // remove this to use 64bit int for "int"
#define _CONSTANT_MD            // remove this to use non-static MD from input
#define _USE_TYPICAL_MD         // remove this to use custom constant MD
#define _CUSTOM_MD 1000000007   // edit this to use custom MD
// == FLAGS == //

// == Beginning of template == //
#ifdef _CONSTANT_MD
#ifdef _USE_TYPICAL_MD
constexpr int __MD__ = 998244353;
#else
constexpr int __MD__ = _CUSTOM_MD;
#endif
#else
int __MD__;
#endif
#include <bits/stdc++.h>
using namespace std;using lli=long long;template<typename T>T inverse(T a,T m){T u=0,v=1;while(a){T t=m/a;m-=t*a;swap(a,m);u-=t*v;swap(u,v);}assert(m==1);return u;}template<typename T>class Modular{public:using Type=typename decay<decltype(T::value)>::type;constexpr Modular():value(){}template<typename U>Modular(const U&x){value=normalize(x);}template<typename U>static Type normalize(const U&x){Type v;if(-mod()<=x&&x<mod())v=static_cast<Type>(x);else v=static_cast<Type>(x%mod());if(v<0)v+=mod();return v;}const Type&operator()()const{return value;}template<typename U>explicit operator U()const{return static_cast<U>(value);}constexpr static Type mod(){return T::value;}Modular&operator+=(const Modular&other){if((value+=other.value)>=mod())value-=mod();return*this;}Modular&operator-=(const Modular&other){if((value-=other.value)<0)value+=mod();return*this;}template<typename U>Modular&operator+=(const U&other){return*this+=Modular(other);}template<typename U>Modular&operator-=(const U&other){return*this-=Modular(other);}Modular&operator++(){return*this+=1;}Modular&operator--(){return*this-=1;}Modular operator++(int){Modular result(*this);*this+=1;return result;}Modular operator--(int){Modular result(*this);*this-=1;return result;}Modular operator-()const{return Modular(-value);}template<typename U=T>typename enable_if<is_same<typename Modular<U>::Type,int>::value,Modular>::type&operator*=(const Modular&rhs){value=normalize(static_cast<int64_t>(value)*static_cast<int64_t>(rhs.value));return*this;}template<typename U=T>typename enable_if<is_same<typename Modular<U>::Type,lli>::value,Modular>::type&operator*=(const Modular&rhs){lli q = static_cast<lli>(static_cast<long double>(value)*rhs.value/mod());value=normalize(value*rhs.value-q*mod());return*this;}template<typename U=T>typename enable_if<!is_integral<typename Modular<U>::Type>::value,Modular>::type&operator*=(const Modular&rhs){value=normalize(value*rhs.value);return*this;}Modular&operator/=(const Modular&other){return*this*=Modular(inverse(other.value,mod()));}friend const Type&abs(const Modular&x){return x.value;}template<typename U>friend bool operator==(const Modular<U>&lhs,const Modular<U>&rhs);template<typename U>friend bool operator<(const Modular<U>&lhs,const Modular<U>&rhs);template<typename V,typename U>friend V&operator>>(V&stream,Modular<U>&number);private:Type value;};template<typename T>bool operator==(const Modular<T>&lhs,const Modular<T>&rhs){return lhs.value==rhs.value;}template<typename T,typename U>bool operator==(const Modular<T>&lhs,U rhs){return lhs==Modular<T>(rhs);}template<typename T,typename U>bool operator==(U lhs,const Modular<T>&rhs){return Modular<T>(lhs)==rhs;}template<typename T>bool operator!=(const Modular<T>&lhs,const Modular<T>&rhs){return!(lhs==rhs);}template<typename T,typename U>bool operator!=(const Modular<T>&lhs,U rhs){return!(lhs==rhs);}template<typename T,typename U>bool operator!=(U lhs,const Modular<T>&rhs){return!(lhs==rhs);}template<typename T>bool operator<(const Modular<T>&lhs,const Modular<T>&rhs){return lhs.value<rhs.value;}template<typename T>Modular<T>operator+(const Modular<T>&lhs,const Modular<T>&rhs){return Modular<T>(lhs)+=rhs;}template<typename T,typename U>Modular<T>operator+(const Modular<T>&lhs,U rhs){return Modular<T>(lhs)+=rhs;}template<typename T,typename U>Modular<T>operator+(U lhs,const Modular<T>&rhs){ return Modular<T>(lhs)+=rhs;}template<typename T>Modular<T>operator-(const Modular<T>&lhs,const Modular<T>&rhs){return Modular<T>(lhs)-=rhs;}template<typename T,typename U>Modular<T>operator-(const Modular<T>&lhs,U rhs){return Modular<T>(lhs)-=rhs;}template<typename T,typename U>Modular<T>operator-(U lhs,const Modular<T>&rhs){return Modular<T>(lhs)-=rhs;}template<typename T>Modular<T>operator*(const Modular<T>&lhs,const Modular<T>&rhs){return Modular<T>(lhs)*=rhs;}template<typename T,typename U>Modular<T>operator*(const Modular<T>&lhs,U rhs){return Modular<T>(lhs)*=rhs;}template<typename T,typename U>Modular<T>operator*(U lhs,const Modular<T>&rhs){return Modular<T>(lhs)*=rhs;}template<typename T>Modular<T>operator/(const Modular<T>&lhs,const Modular<T>&rhs){return Modular<T>(lhs)/=rhs;}template<typename T,typename U>Modular<T>operator/(const Modular<T>&lhs,U rhs){return Modular<T>(lhs)/=rhs;}template<typename T,typename U>Modular<T>operator/(U lhs,const Modular<T>&rhs){return Modular<T>(lhs)/=rhs;}template<typename T,typename U>Modular<T>power(const Modular<T>&a,const U&b){assert(b>=0);Modular<T>x=a,res=1;U p=b;while(p>0){if(p&1)res*=x;x*=x;p>>=1;}return res;}template<typename T>bool IsZero(const Modular<T>&number){return number()==0;}template<typename T>string to_string(const Modular<T>&number){return to_string(number());}template<typename U,typename T>U&operator<<(U&stream,const Modular<T>&number){return stream<<number();}template<typename U,typename T>U&operator>>(U&stream,Modular<T>&number){typename common_type<typename Modular<T>::Type,lli>::type x;stream>>x;number.value=Modular<T>::normalize(x);return stream;}template<class T>class SumSegTree{public:template<class S>class N{public:S v,l;};vector<T>v;vector<N<T>>d;T z;virtual T f(const T&x,const T&y){return x+y;}SumSegTree(const vector<T>&w,T x=0):v(w),z(x){init(1,1,(int)w.size());}T init(int n,int s,int e){if(n>=(int)d.size())d.resize(n+1);if(s==e)return d[n].v=v[s-1];return d[n].v=f(init(n*2,s,(s+e)/2),init(n*2+1,(s+e)/2+1,e));}void add(int f,int t,int k){u(1,1,(int)v.size(),f+1,t,k);}void add(int i,int k){u(1,1,(int)v.size(),i+1,i+1,k);}void p(int n,int s,int e){if(!d[n].l)return;if(!f(1,-1))d[n].l*=e-s+1;d[n].v+=d[n].l;if(s^e){d[n*2].l+=d[n].l;d[n*2+1].l+=d[n].l;}d[n].l=0;}void u(int n,int s,int e,int i,int j,int k){p(n,s,e);if(j<s||i>e)return;if(i<=s&&e<=j){d[n].v+=(e-s+1)*k;if(s!=e){d[n*2].l+=k;d[n*2+1].l+=k;}}else{u(n*2,s,(s+e)/2,i,j,k);u(n*2+1,(s+e)/2+1,e,i,j,k);d[n].v=d[n*2].v+d[n*2+1].v;}}T query(int f,int t){return q(1,1,(int)v.size(),f+1,t);}T q(int n,int s,int e,int i,int j){p(n,s,e);if(i>e||j<s)return z;if(i<=s&&e<=j)return d[n].v;return f(q(n*2,s,(s+e)/2,i,j),q(n*2+1,(s+e)/2+1,e,i,j));}};template<class T>class MinSegTree:public SumSegTree<T>{public:virtual T f(const T&x,const T&y){return min(x,y);}MinSegTree(const vector<T>&w,T x):SumSegTree<T>(w,x){this->init(1,1,(int)w.size());}};template<class T>class MaxSegTree:public SumSegTree<T>{public:virtual T f(const T&x, const T&y){return max(x,y);}MaxSegTree(const vector<T>&w,T x):SumSegTree<T>(w,x){this->init(1,1,(int)w.size());}};
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define endl ('\n')
#ifdef DEBUG
int recur_depth=0;template<typename Ostream,typename Cont>typename enable_if<is_same<Ostream,ostream>::value,Ostream&>::type operator<<(Ostream&os,const Cont&v){os<<"[";for(auto&x:v){os<<x<<", ";}return os<<"]";}template<typename Ostream,typename ...Ts>Ostream&operator<<(Ostream&os,const pair<Ts...>&p){return os<<"{"<<p.first<<", "<<p.second<<"}";}
#define dbg(x) {++recur_depth; auto x_=x; --recur_depth; cerr<<string(recur_depth, '\t')<<"\e[91m"<<__func__<<":"<<__LINE__<<"\t"<<#x<<" = "<<x_<<"\e[39m"<<endl;}
#else
#define dbg(x)
#endif
#ifdef _CONSTANT_MD
using Mint = Modular<integral_constant<decay<decltype(__MD__)>::type,__MD__>>;
#endif
#ifndef _NO_NEED_64INT
using lli = long long int;
#define int lli
#endif
#define SETMD(md) {__MD__ = (md);}
#define MDC(x) (((x) % __MD__ + __MD__) % __MD__)
#define INV(x) (inverse<int>(x, __MD__))
#define DIV(x, y) (MDC(x * INV(y)))
int fact(int n){static vector<int>m(1,1);if((int)m.size()>n)return m[n];m.push_back(MDC(fact(n-1)*n));return m[n];}int ifact(int n){static vector<int>m(1,1);if((int)m.size()>n)return m[n];ifact(n-1);m.push_back(INV(fact(n)));return m[n];}int ncr(int n,int r){if(n<0||r<0)return 0;if(r>n)return 0;return MDC(MDC(fact(n)*ifact(r))*ifact(n-r));}int npr(int n,int r){if(n<0||r<0)return 0;if(r>n)return 0;return MDC(fact(n)*ifact(n-r));}
// == end of template == //

int N, M;
vector<int> A;

int _solve() {
    cin >> N >> M;
    A.resize(N);
    for (auto &ai : A) cin >> ai;
    return 0;
}

void _predo() {
}

#ifdef _ISTC
int32_t main(){ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);int t;cin>>t;_predo();for(int TEST=1;TEST<=t;TEST++){dbg(TEST);_solve();}return 0;}
#else
int32_t main(){ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);_solve();return 0;}
#endif
