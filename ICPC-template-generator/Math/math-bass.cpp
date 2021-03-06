ll p=1e9+7;
ll gcd(ll a,ll b) {return b?gcd(b,a%b):a;}
ll lcm(ll a,ll b) {return a*gcd(a,b)/b;}
ll exgcd(ll a,ll b,ll &x,ll &y) {
	if(b==0) return (x=1,y=0,a);
	if(a==0) return (x=0,y=1,b);
	ll r=exgcd(b,a%b,y,x);
	y-=(a/b)*x;
	return r;
}
ll lcm_mod(ll a,ll b,ll c=p) {
	return (a/gcd(a,b)*b)%c;
}
ll pow_mod(ll a,ll b,ll c=p,ll ans=1) {
	while(b) {
		if(b&1) ans=(a*ans)%c;
		a=(a*a)%c,b>>=1;
	}
	return ans;
}
//@long double 1e9以下表现良好,不会出现误差@
ll mul_mod_2(ll a,ll b,ll m){
 ll c=a*b-(ll)((long double)a*b/m+0.5)*m;
 return c<0?c+m:c;
}
//@不丢失精度的快速乘@
ll mul_mod(ll a,ll b,ll c){return (__int128)a*b%c;}
ll pow_mul_mod(ll a,ll b,ll c=p,ll ans=1){
	while(b){
		if(b&1)res=mul_mod(res,a,c);
		a=mul_mod(a,a,c),b>>=1;
	}
	return res;
}
ll inv_gcd(ll a,ll c=p){
	a%=c;
	if(a<0)a+=c;
	ll b=c,u=0,v=1;
	while(a) {
		ll t=b/a;b-=t*a;
		swap(a,b);
		u-=t*v;
		swap(u,v);
	}
	if(u<0)u+=c;
	return u;
}
