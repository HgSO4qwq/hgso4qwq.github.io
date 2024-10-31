#include<bits/stdc++.h>
using namespace std;

const int MXN=1050,MXProbC=15;
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
int rnad(){return abs((int)rnd());}
int rd(int l,int r){return rnad()%(r-l+1)+l;}

string getFile(string path){
	ifstream fin(path.c_str());
	string tmp;
	fin>>tmp;
	fin.close();
	return tmp;
}
void setFile(string path,string ths){
	ofstream fout(path.c_str());
	fout<<ths;
	fout.close();
}

map<string,string> team;
set<string> teams;
map<string,int> id;
string names[MXN];
int fbh,fbm,pcnt;
int scnt[MXN][MXProbC],lstt[MXN][MXProbC];
int SubC[MXN][MXProbC],fstAC[MXProbC];
int idkSub[MXN][MXProbC];
int ac[MXN],pena[MXN];

void addperson(){
	ifstream fin("team.txt");
	int k;fin>>k;
	for(int i=1;i<=k;i++) 
	{
		string a,b;fin>>a>>b;
		// cerr<<a<<' '<<b<<endl;
		team[a]=b;
	}
	//add more
	for(auto [p,t]:team)teams.insert(t);
	for(auto i:teams)names[id[i]=++pcnt]=i;
	fin.close();
    // fclose();
}

struct th{int a,b,c;};

string gt(string t,string col="black",string bgcol="#ffffff",string fontsize="15px")
{
	return "<td style=\"text-align: center;background-color:"+bgcol+
		";\"><span style=\"color:"+col+";font-size: "+fontsize+";\">"+t+"</span></td>\n";
}
string t2s(int t){
	int h=t/60,m=t%60;
	string s="";
	s+=(char)(h/10+'0');
	s+=(char)(h%10+'0');
	s+=":";
	s+=(char)(m/10+'0');
	s+=(char)(m%10+'0');
	return s;
}

string lgreen="#60e760";
string lred="#e87272";
string dgreen="#1daa1d";
string indigo="#6666ff";
string Gold="#eec710";
string Silver="#aaaaaa";
string Bronze="#c08e55";
string chbckc[2]={"#f8f8f8","#ffffff"};

void updBoard()
{
	string s="<head>\n    <link rel=\"stylesheet\" type=\"text/css\" href=\"styles.css\">\n</head>\n\n";
	s+="<body>\n";
	s+="<table  style=\"border-collapse: collapse;\" align=\"center\">\n";
	s+="<caption><h2> Toilet Scuffle Rating </h2></caption>\n";
	s+="<thead><tr>\n";
	s+="<th colspan=\"1\">User</th>\n";
	s+="<th colspan=\"1\">Old Rating</th>\n";
	s+="<th colspan=\"1\">New Rating</th>\n";
	s+="<th colspan=\"1\">Δ</th>\n";
	s+="<th colspan=\"1\">Perf.</th>\n";
	s+="<th colspan=\"1\">Expr.</th>\n";
	s+="</tr></thead>\n";
	s+="<tbody>\n";
	vector<th>v;
	for(int i=1;i<=pcnt;i++)v.push_back({ac[i],pena[i],i});
	sort(all(v),[&](th a,th b){return a.a==b.a?a.b==b.b?a.c<b.c:a.b<b.b:a.a>b.a;});
	int rk=0;
	// scnt: Submission Count
	// lstt: Time
	// ac: Number of ACs
	for(int p=1;p<=9;p++)
	{
		int mn=1e9,mnid=0;
		for(int i=1;i<=pcnt;i++)
		{
			if(lstt[i][p]!=-1&&SubC[i][p]<mn) 
			{
				mn=SubC[i][p];
				mnid=i;
			}
		}
		fstAC[p]=mnid;
	}
	for(auto _:v){
		int i=_.c;++rk;
		string fstCol=chbckc[rk%2];
		if(rk<=1) fstCol=Gold;
		else if(rk<=3) fstCol=Silver;
		else if(rk<=6) fstCol=Bronze;
		s+="<tr>\n";
		s+=gt(to_string(rk),"black",fstCol);
		s+=gt(names[i],"black",chbckc[rk%2]);
        // s+=gt(to_string(i),"black",chbckc[rk%2]);
		for(int p=1;p<=9;p++)
		{
			int l=lstt[i][p],c=scnt[i][p];
			if(~l) 
			{
				s+=gt("+"+(c?to_string(c):"")+"<br> <span style=\"font-size: 11px;\">"+
					t2s(l)+"</span>","black",(fstAC[p]==i?dgreen:lgreen),"15.5px");
			}
			else if(idkSub[i][p]) s+=gt(to_string(c)+"<br> <span style=\"font-size: 11px;\">"+to_string(idkSub[i][p])+" tries </span>","black",indigo,"15.5px");
			else if(c) s+=gt(to_string(c),"black",lred,"15.5px");
			else s+=gt(" . <br> <span style=\"font-size: 11px;\">  .  </span>",chbckc[rk%2],chbckc[rk%2],"15.5px");
		}
		s+=gt(to_string(ac[i]),"black",chbckc[rk%2]);
		s+=gt(to_string(pena[i]),"black",chbckc[rk%2]);
		s+="</tr>\n";
	}
	s+="</tbody>\n</table>\n";
	s+="</body>\n";
	setFile("BOARD/Board.html",s);
}

void __INIT__(){}
void __SOLVE__(int _case){
	addperson();
	// fin.close();
	// cout<<pcnt<<endl;
	freopen("Input.txt","r",stdin);
	memset(lstt,-1,sizeof(lstt));
	updBoard();
	int Tsk;cin>>Tsk;
	int sth,stm;
	cin>>sth>>stm>>fbh>>fbm;
	stm+=sth*60;fbm+=fbh*60;fbm-=stm;
	int h,m;string name,pb;bool sta;
    for(int __=1;__<=Tsk;__++)
	{
		// 1 = ac, 0 = wa
		if( !(cin>>h>>m>>name>>pb>>sta) ) break;
		// cout<<h<<' '<<m<<' '<<name<<' '<<pb<<' '<<sta<<endl;
		m+=h*60;m-=stm;
		string t=team[name];
		int p=0,i=id[t];
		if(pb=="A"||pb=="1")p=1;
		if(pb=="B"||pb=="2")p=2;
		if(pb=="C"||pb=="3")p=3;
		if(pb=="D"||pb=="4")p=4;
		if(pb=="E"||pb=="5")p=5;
		if(pb=="F"||pb=="6")p=6;
		if(pb=="G"||pb=="7")p=7;
		if(pb=="H"||pb=="8")p=8;
		if(pb=="I"||pb=="9")p=9;
		if(m>=fbm) idkSub[i][p]++;
		else if(~lstt[i][p]) continue;
		else if(!sta) --scnt[i][p];
		else 
		{
			scnt[i][p]=-scnt[i][p],lstt[i][p]=m,++ac[i];
			pena[i]+=lstt[i][p]+20*scnt[i][p];
			SubC[i][p]=__;
		}
		updBoard();
	}
}

// scnt: Submission Count
// lstt: Time
// ac: Number of ACs

int main()
{
    // freopen("Input.txt","r",stdin);
    // freopen(".out","w",stdout);
    __INIT__();
    int T;DC?cin>>T,1:T=1;
    for(int _CASE=1;_CASE<=T;_CASE++) __SOLVE__(_CASE);
    return 0;
}