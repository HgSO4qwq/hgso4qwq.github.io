#include <iostream>
#include <sstream>
#include <iomanip>
using namespace std;

string lgreen="#60e760";
string lred="#e87272";
string dgreen="#1daa1d";
string indigo="#6666ff";
string Gold="#eec710";
string Silver="#aaaaaa";
string Bronze="#c08e55";
string chbckc[2]={"#f8f8f8","#ffffff"};

std::string wyswd(double value) {
    std::ostringstream streamObj;
    // Set Fixed -Point Notation
    streamObj << std::fixed;
    // Set precision to 2 digits
    streamObj << std::setprecision(2);
    //Add double to stream
    streamObj << value;
    // Get string from output string stream
    return streamObj.str();
}

string Delta(int x)
{
    if(x>0) return "<td style=\"text-align: center;\"><span style=\"color:green;font-size: 15px;\">+"+to_string(x)+"</span></td>\n";
    if(x==0) return "<td style=\"text-align: center;\"><span style=\"color:grey;font-size: 15px;\">"+to_string(x)+"</span></td>\n";
    if(x<0) return "<td style=\"text-align: center;\"><span style=\"color:red;font-size: 15px;\">"+to_string(x)+"</span></td>\n";
}

string Ratcol(int x)
{
    if(x>3500) return "<td style=\"text-align: center;\"><span style=\"color:#FF0000;font-size: 15px;\"> inf </span></td>\n";
    if(x<=-1e5) return "<td style=\"text-align: center;\"><span style=\"color:#000000;font-size: 15px;\"> -- </span></td>\n";
    if(x<=-50) return "<td style=\"text-align: center;\"><span style=\"color:#808080;font-size: 15px;\">"+to_string(-50)+"</span></td>\n";
    // if(x<=1050) return "<td style=\"text-align: center;\"><span style=\"color:green;font-size: 15px;\">"+to_string(x)+"</span></td>";
         if(x<= 900)    return "<td style=\"text-align: center;\"><span style=\"color:#808080;font-size: 15px;\">"+to_string(x)+"</span></td>\n";
    else if(x<=1100)    return "<td style=\"text-align: center;\"><span style=\"color:#804000;font-size: 15px;\">"+to_string(x)+"</span></td>\n";
    else if(x<=1300)    return "<td style=\"text-align: center;\"><span style=\"color:#008000;font-size: 15px;\">"+to_string(x)+"</span></td>\n";
    else if(x<=1450)    return "<td style=\"text-align: center;\"><span style=\"color:#03A89E;font-size: 15px;\">"+to_string(x)+"</span></td>\n";
    else if(x<=1600)    return "<td style=\"text-align: center;\"><span style=\"color:#0000FF;font-size: 15px;\">"+to_string(x)+"</span></td>\n";
    else if(x<=1800)    return "<td style=\"text-align: center;\"><span style=\"color:#AA00AA;font-size: 15px;\">"+to_string(x)+"</span></td>\n";
    else if(x<=2000)    return "<td style=\"text-align: center;\"><span style=\"color:#FF8C00;font-size: 15px;\">"+to_string(x)+"</span></td>\n";
    else                return "<td style=\"text-align: center;\"><span style=\"color:#FF0000;font-size: 15px;\">"+to_string(x)+"</span></td>\n";
}

string bllk(string s) {return "<td style=\"text-align: center;\"><span style=\"color:black;font-size: 15px;\">"+s+"</span></td>\n";}
string bllk2(string s) {return "<td style=\"text-align: center;\"><span style=\"color:black;font-size: 15px;\"><a href=\"/"+s+"\">"+s+"</a></span></td>\n";}

int main()
{
    freopen("Rating.board","r",stdin);
    freopen("index.html","w",stdout);
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
        string nam;cin>>nam;s+=bllk2(nam);
        int old,neew,Delt,perf;double seed;cin>>old>>neew>>Delt>>perf>>seed;
        s+=Ratcol(old);s+=Ratcol(neew);s+=Delta(Delt);s+=Ratcol(perf);
        s+=bllk((perf<=-1e5?" -- ":wyswd(seed)));
        s+="</tr>\n";
    }cout<<s<<endl;
    return 0;
}