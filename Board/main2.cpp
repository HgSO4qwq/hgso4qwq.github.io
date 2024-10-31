#include<iostream>
using namespace std;

string lgreen="#60e760";
string lred="#e87272";
string dgreen="#1daa1d";
string indigo="#6666ff";
string Gold="#eec710";
string Silver="#aaaaaa";
string Bronze="#c08e55";
string chbckc[2]={"#f8f8f8","#ffffff"};

string Delta(int x)
{
    if(x>0) return "<td style=\"text-align: center;\"><span style=\"color:green;font-size: 15px;\">"+to_string(x)+"</span></td>\n";
    if(x==0) return "<td style=\"text-align: center;\"><span style=\"color:grey;font-size: 15px;\">"+to_string(x)+"</span></td>\n";
    if(x<0) return "<td style=\"text-align: center;\"><span style=\"color:red;font-size: 15px;\">"+to_string(x)+"</span></td>\n";
}

string Ratcol(int x)
{
    // if(x<=1050) return "<td style=\"text-align: center;\"><span style=\"color:green;font-size: 15px;\">"+to_string(x)+"</span></td>";
         if(x<=1050)    return "<td style=\"text-align: center;\"><span style=\"color:#808080;font-size: 15px;\">"+to_string(x)+"</span></td>\n";
    else if(x<=1250)    return "<td style=\"text-align: center;\"><span style=\"color:#008000;font-size: 15px;\">"+to_string(x)+"</span></td>\n";
    else if(x<=1400)    return "<td style=\"text-align: center;\"><span style=\"color:#03A89E;font-size: 15px;\">"+to_string(x)+"</span></td>\n";
    else if(x<=1550)    return "<td style=\"text-align: center;\"><span style=\"color:#0000FF;font-size: 15px;\">"+to_string(x)+"</span></td>\n";
    else if(x<=1700)    return "<td style=\"text-align: center;\"><span style=\"color:#AA00AA;font-size: 15px;\">"+to_string(x)+"</span></td>\n";
    else if(x<=2000)    return "<td style=\"text-align: center;\"><span style=\"color:#FF8C00;font-size: 15px;\">"+to_string(x)+"</span></td>\n";
    else                return "<td style=\"text-align: center;\"><span style=\"color:#FF0000;font-size: 15px;\">"+to_string(x)+"</span></td>\n";
}

string bllk(string s) {return "<td style=\"text-align: center;\"><span style=\"color:black;font-size: 15px;\">"+s+"</span></td>";}

int main()
{
    freopen("Rating.board","r",stdin);
    freopen("Rating.html","w",stdout);
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
    int n;cin>>n;
    for(int i=1;i<=n;i++)
    {
        s+="<tbody><tr>";
        string nam;cin>>nam;s+=bllk(nam);
        int old,neew,Delt,perf;double seed;cin>>old>>neew>>Delt>>perf>>seed;
        s+=Ratcol(old);s+=Ratcol(neew);s+=Delta(Delt);s+=Ratcol(perf);
        s+=bllk(to_string(seed));
        s+="</tr>\n";
    }cout<<s<<endl;
    return 0;
}