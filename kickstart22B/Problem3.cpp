#include <bits/stdc++.h>
   using namespace std;
    
   #define ll long long
   #define ld long double
   #define ar array

   using namespace std;
    
    
   #define vt vector
   #define pb push_back
   #define all(c) (c).begin(), (c).end()
   #define sz(x) (int)(x).size()
    
   #define F_OR(i, a, b, s) for (int i=(a); (s)>0?i<(b):i>(b); i+=(s))
   #define F_OR1(e) F_OR(i, 0, e, 1)
   #define F_OR2(i, e) F_OR(i, 0, e, 1)
   #define F_OR3(i, b, e) F_OR(i, b, e, 1)
   #define F_OR4(i, b, e, s) F_OR(i, b, e, s)
   #define GET5(a, b, c, d, e, ...) e
   #define F_ORC(...) GET5(__VA_ARGS__, F_OR4, F_OR3, F_OR2, F_OR1)
   #define FOR(...) F_ORC(__VA_ARGS__)(__VA_ARGS__)
   #define EACH(x, a) for (auto& x: a)
    
   template<class T> bool umin(T& a, const T& b) {
       return b<a?a=b, 1:0;
   }
   template<class T> bool umax(T& a, const T& b) {
       return a<b?a=b, 1:0;
   }
    
   ll FIRSTTRUE(function<bool(ll)> f, ll lb, ll rb) {
       while(lb<rb) {
           ll mb=(lb+rb)/2;
           f(mb)?rb=mb:lb=mb+1;
       }
       return lb;
   }
   ll LASTTRUE(function<bool(ll)> f, ll lb, ll rb) {
       while(lb<rb) {
           ll mb=(lb+rb+1)/2;
           f(mb)?lb=mb:rb=mb-1;
       }
       return lb;
   }
    
   template<class A> void read(vt<A>& v);
   template<class A, size_t S> void read(ar<A, S>& a);
   template<class T> void read(T& x) {
       cin >> x;
   }
   void read(double& d) {
       string t;
       read(t);
       d=stod(t);
   }
   void read(long double& d) {
       string t;
       read(t);
       d=stold(t);
   }
   template<class H, class... T> void read(H& h, T&... t) {
       read(h);
       read(t...);
   }
   template<class A> void read(vt<A>& x) {
       EACH(a, x)
           read(a);
   }
   template<class A, size_t S> void read(array<A, S>& x) {
       EACH(a, x)
           read(a);
   }
    
   string to_string(char c) {
       return string(1, c);
   }
   string to_string(bool b) {
       return b?"true":"false";
   }
   string to_string(const char* s) {
       return string(s);
   }
   string to_string(string s) {
       return s;
   }
   string to_string(vt<bool> v) {
       string res;
       FOR(sz(v))
           res+=char('0'+v[i]);
       return res;
   }
    
   template<size_t S> string to_string(bitset<S> b) {
     string res;
       FOR(S)
           res+=char('0'+b[i]);
       return res;
   }
   template<class T> string to_string(T v) {
       bool f=1;
       string res;
       EACH(x, v) {
           if(!f)
               res+=' ';
           f=0;
           res+=to_string(x);
       }
       return res;
   }
    
   template<class A> void write(A x) {
       cout << to_string(x);
   }
   template<class H, class... T> void write(const H& h, const T&... t) {
       write(h);
       write(t...);
   }
   void print() {
       write("\n");
   }
   template<class H, class... T> void print(const H& h, const T&... t) {
       write(h);
       if(sizeof...(t))
           write(' ');
       print(t...);
   }
    
   void DBG() {
       cerr << "]" << endl;
   }
   template<class H, class... T> void DBG(H h, T... t) {
       cerr << to_string(h);
       if(sizeof...(t))
           cerr << ", ";
       DBG(t...);
   }
   #ifdef _DEBUG
   #define dbg(...) cerr << "LINE(" << __LINE__ << ") -> [" << #__VA_ARGS__ << "]: [", DBG(__VA_ARGS__)
   #else
   #define dbg(...) 0
   #endif
    
   template<class T> void offset(ll o, T& x) {
       x+=o;
   }
   template<class T> void offset(ll o, vt<T>& x) {
       EACH(a, x)
           offset(o, a);
   }
   template<class T, size_t S> void offset(ll o, ar<T, S>& x) {
       EACH(a, x)
           offset(o, a);
   }

   template<class T, class U> void vti(vt<T> &v, U x, size_t n) {
       v=vt<T>(n, x);
   }
   template<class T, class U> void vti(vt<T> &v, U x, size_t n, size_t m...) {
       v=vt<T>(n);
       EACH(a, v)
           vti(a, x, m);
   }
    
   const int d4i[4]={-1, 0, 1, 0}, d4j[4]={0, 1, 0, -1};
   const int d8i[8]={-1, -1, 0, 1, 1, 1, 0, -1}, d8j[8]={0, 1, 1, 1, 0, -1, -1, -1};
int n,d;
const int N=405;
int dp[N][N][2];
int go(vector<int> &a, int l, int r, int x){
    if(l>=r) return 0;
    if(dp[l][r][x]!=-1) return dp[l][r][x];
    int &ans = dp[l][r][x];
    ans=1e15;
    if(!x){
        int p1=go(a,l+1,r,0);
        int p2=go(a,l+1,r,1);
        ans=min(ans, p1+ min(abs(a[l]-a[l+1]), d-abs(a[l]-a[l+1])));
        ans=min(ans, p2+min(abs(a[l]-a[r]), d-abs(a[l]-a[r])));
    }
    else{
        int p1=go(a,l,r-1, 0);
        int p2=go(a,l,r-1, 1);
        ans=min(ans, p1+min(abs(a[r]-a[l]), d-abs(a[r]-a[l])));
        ans=min(ans, p2+min(abs(a[r]-a[r-1]), d-abs(a[r]-a[r-1])));
    }
    return ans;
}
void solve() {
       read(n,d);
       vt<int> a(n);
        read(a);
       memset(dp, -1, sizeof(dp));
        int ans= go(a,0,n-1,0) + min(a[0],d-a[0]);
        ans=min(ans, go(a,0,n-1,1)+min(a[n-1],d-a[n-1]));
    
    cout<<ans<<endl;
       
   }

    
   int main() {
       ios::sync_with_stdio(0);
       cin.tie(0);
    
       int t=1;
       read(t);
       FOR(t) {
           write("Case #", i+1, ": ");
           solve();
       }
   }
