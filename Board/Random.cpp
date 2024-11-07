#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<int,ll> pil;
#define fi first
#define se second
#define endl '\n'
#define mp make_pair
#define pb push_back
#define all(x) x.begin(),x.end()
#define Cl(x) memset(x,0,sizeof(x))
const bool DC=0;
const ll mod=0;
const int N=0;
ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
ll qpow(ll a,ll b,ll p=mod){ll ans=1;for(;b;b>>=1,a=a*a%p)if(b&1)ans=ans*a%p;return ans;}
void NO(){cout<<"NO\n";}
void YES(){cout<<"YES\n";}
mt19937 rnd((unsigned long long)new char);
ll rnad(){return abs((ll)rnd());}
ll Rd(ll l,ll r){return rnad()%(r-l+1)+l;}
double MOD(double a,double b){
	return a-floor(a/b)*b;
}
double rd(double l,double r){
	double tmp=Rd(1,1000000000)/1e4;
	return MOD(tmp,r-l)+l;
}
const double PI=acos(-1);

int n=9,m=28;
// t_ab: 1/2*a*((5sqrt5+1)/2-s)^(a/b)
// a: 0.5~10
// b: 0.5~8
// s: -1~1
// pij: si+1-2arctan(bi-aj)/pi
// p[tx]: (n-x+1)/(n*(n+1)/2)
// T_{a,b,k}: t_ab/g(1)*g(k)  g(x)=x+(a2/b2)/x
double a[15],b[35],s[35];
struct node{int t,user,p,sta;};
vector<node>qwq;
vector<int>ns[35];//not solved
int cnt[35][15];
double t1[35][15],P[35][15];
double p(int i,int j){return (s[i]+1)*(0.5-atan(a[j]-b[i])/PI);}
double T1(int i,int j){return 0.5*a[j]*pow((5*sqrt(5.0)+1)/2.0-s[i],a[j]/b[i]);}
double g(double a,double b,double x){return x+a*a/b/b/x;}
double tk(int i,int j,int ts){return t1[i][j]/g(a[j],b[i],1)*g(a[j],b[i],ts);}
double pk(int i,int j,int ts){return (1-exp(-b[i]*(ts-1)/a[j]))*(1-P[i][j])+P[i][j];}

void __INIT__(){ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);}
void __SOLVE__(int _case){
    std::random_device rd22{};
    std::mt19937 gen{rd22()};
 
    // 值最可能接近平均
    // 标准差影响生成的值距离平均数的分散
    std::normal_distribution<double> d{3.3,0.2};
    std::normal_distribution<double> d2{5,1.5};
    std::uniform_real_distribution<double> di(-0.2,0.2);
	a[1]=7.5;
	a[2]=2.8;
	a[3]=7.5;
	a[4]=5.2;
	a[5]=0.2;
	a[6]=7.5;
	a[7]=6.4;
	a[8]=7.5;
	a[9]=3.5;
	
	for(int i=1;i<=m;i++) b[i]=d(gen),s[i]=di(gen);
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++)ns[i].push_back(j),t1[i][j]=T1(i,j),P[i][j]=p(i,j);
		sort(all(ns[i]),[&](int x,int y){return P[i][x]>P[i][y];});
		cout<<i<<": ";
		for(int j=1;j<=n;j++)cout<<ns[i][j-1]<<" \n"[j==n];
		cout<<i<<": ";
		for(int j=1;j<=n;j++)cout<<P[i][j]<<" \n"[j==n];
		cout<<i<<": ";
		for(int j=1;j<=n;j++)cout<<t1[i][j]<<" \n"[j==n];
	}
	for(int i=1;i<=m;i++){
		cout<<"now solving: "<<i<<"\n";
		double t=0;
		while(t<=240&&ns[i].size()){
			ll l=ns[i].size(),sum=l*(l+1)/2*l*(l+1)/2,r=Rd(1,sum),x=l-1;
			auto it=ns[i].begin();
			for(int j=0;j<l;j++,it++){
				r-=(l-j)*(l-j)*(l-j);
				if(r<=0){x=j;break;}
			}
			int pr=ns[i][x];
			cout<<i<<" will solve "<<pr<<"\n";
			// go and solve pr
			double tmp=tk(i,pr,++cnt[i][x]);
			t+=tmp;
			cout<<"it used "<<tmp<<" minutes. now time: "<<t<<"\n";
			if(t>240)continue;
			tmp=pk(i,pr,cnt[i][x]);
			cout<<"Prob to solve: "<<tmp<<"\n";
			if(rd(0,1)<=tmp){
				// Accepted
				cout<<"Accepted!\n";
				qwq.push_back({(int)t,i,pr,1});
				ns[i].erase(it);
			}else qwq.push_back({(int)t,i,pr,0}),++cnt[i][pr],cout<<"Failed\n";
		}
	}
	sort(all(qwq),[&](node a,node b){return a.t<b.t;});
	cout<<n<<" "<<m<<"\n";
	for(int i=1;i<=n;i++)cout<<a[i]<<" ";
	cout<<"\n";
	for(int i=1;i<=m;i++)cout<<b[i]<<" ";
	cout<<"\n";
	for(int i=1;i<=m;i++)cout<<s[i]<<" ";
	cout<<"\n";
	cout<<"--------------------------\n";
	cout<<"114514\n0 0\n";
	for(auto i:qwq){
		cout<<i.t/60<<" "<<i.t%60<<" Bot"<<i.user<<" "<<i.p<<" "<<i.sta<<"\n";
	}
}
int main(){/*freopen(".in","r",stdin);freopen(".out","w",stdout);*/__INIT__();int T;DC?cin>>T,1:T=1;for(int _CASE=1;_CASE<=T;_CASE++)__SOLVE__(_CASE);return 0;}