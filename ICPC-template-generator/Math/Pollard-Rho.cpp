//@得到n的一个随机因子,包括自身和1@
//@复杂度$O(n^{1/4})$@
//@要保证randint的随机范围大于等于测试数字@
ll mul_mod(ll a,ll b,ll c){return (__int128)a*b%c;}
int mul_mod(int a,int b,int c){return (ll)a*(ll)b%c;}
auto randint=bind(uniform_int_distribution<ll>(1e9,1e18),mt19937(rand()));
template<typename T> T pollard_rho(T n,T c=randint()) {
  T i=1,k=2,x=randint()%(n-1)+1,y=x,d;
  while(1){
    i++;
    x=(mul_mod(x,x,n)+c)%n;
    d=__gcd(n,y-x);
    if(d>1&&d<n)return d;
    if(y==x)return n;
    if(i==k){
      k<<=1;
      y=x;
    }
  }
}
//@分解因子,map中即为素因子从小到大,first为因子,second为次幂@
//@分解1000个1e18的数字约为600ms,10000个1e9的数字约为200ms@
map<ll,int> factor;
template<typename T>void get_factor(T n,T c=randint()) {
  if(n==1) return;
  if(miller_rabin(n)) {
    factor[n]++;
    return;
  }
  T p=n;
  while(p>=n) p=pollard_rho(p,c--);
  get_factor(p,c);
  get_factor(n/p,c);
}
