#include<iostream>
#include<ctime>
#include<string>
using namespace std;

typedef long long ll;
const int N=100010,C=Llim;
string Date[N];double R[N];
ll T[N];
struct Pt {double x,y;}P[N];
struct node2 {int L,R;string c,c2,rnknm;}lim[N];

void init(string nam) {cout<<"                var "<<nam<<" = c.getContext(\"2d\");\n";}
void colb(string nam,string col,Pt ul,Pt dr)
{
    cout<<"                "<<nam<<".beginPath();\n";
    cout<<"                "<<nam<<".fillStyle=\""<<col<<"\";\n";
    cout<<"                "<<nam<<".fillRect("<<ul.x<<","<<ul.y<<","<<dr.x-ul.x<<","<<dr.y-ul.y<<");\n";
}

void drcir(Pt P)
{
    cout<<"                pnt1_1.beginPath();pnt1_1.fillStyle = \"#FFE900\";pnt1_1.arc("<<P.x<<","<<P.y<<",4.2,0,360,0);pnt1_1.fill();\n"<<endl;
    cout<<"                pnt1_2.beginPath();pnt1_2.fillStyle = \"#ffffff\";pnt1_2.arc("<<P.x<<","<<P.y<<",2.6,0,360,0);pnt1_2.fill();\n"<<endl;
}

void txt(string nam,double yp,string tt)
{
    cout<<"                "<<nam<<".textBaseline = \"middle\";\n";
    cout<<"                "<<nam<<".font = \"10px Cascadia Code\";\n";
    cout<<"                "<<nam<<".fillStyle=\"#000000ff\";\n";
    cout<<"                "<<nam<<".fillText("<<tt<<",0,"<<yp<<");\n"<<endl;
}

void drln(string nam,Pt a,Pt b)
{
    cout<<"                "<<nam<<".beginPath();\n";
    cout<<"                "<<nam<<".strokeStyle=\"#FFE900\";\n";
    cout<<"                "<<nam<<".moveTo("<<a.x<<","<<a.y<<");\n";
    cout<<"                "<<nam<<".lineTo("<<b.x<<","<<b.y<<");\n";
    cout<<"                "<<nam<<".lineWidth=1.4;\n";
    cout<<"                "<<nam<<".stroke();\n";
}

double wid=1200,heig=550;

int main(int argc,char *argv[])
{
    // argv[1]: Name
    string Name=argv[1];
    cout<<("./"+Name+"/index.html").c_str()<<endl;
    freopen(("./history/"+Name+".txt").c_str(),"r",stdin);
    freopen(("./"+Name+"/index.html").c_str(),"w",stdout);
    int n;cin>>n;
    for(int i=1;i<=n;i++) cin>>R[i]>>Date[i]>>T[i];
    double l1=1e18,r1=0;
    for(int i=1;i<=n;i++) r1=max(r1,R[i]),l1=min(l1,R[i]);
    double lllll=l1,rrrrr=r1;
    if(r1<1422) r1=1422;
    if(l1>1378) l1=1378;
    double x11=35,x12=heig-35;
    // swap(x11,x12);
    double k1=(r1-l1)/(x11-x12);
    double r2=T[n],l2=T[1];
    double x21=60,x22=wid-25;
    swap(x21,x22);
    double k2=(r2-l2)/(x21-x22);
    for(int i=1;i<=n;i++)
    {
        P[i]={(T[i]-r2+k2*x21)/k2,(R[i]-r1+k1*x11)/k1};
        cerr<<'('<<T[i]<<','<<R[i]<<")->("<<P[i].x<<','<<P[i].y<<')'<<endl;
    }
    int Llim=0;
    lim[++Llim]={   1, 850,"#80808085","#808080","Retard"};
    lim[++Llim]={ 850,1100,"#80400085","#804000","Newbie"};
    lim[++Llim]={1100,1300,"#00800085","#008000","Pupil"};
    lim[++Llim]={1300,1400,"#03A89E85","#03A89E","Specialist"};
    lim[++Llim]={1400,1550,"#0000FF85","#0000FF","Expert"};
    lim[++Llim]={1550,1750,"#AA00AA85","#AA00AA","Candidate Mastar"};
    lim[++Llim]={1750,1950,"#FF8C0085","#FF8C00","Mastar"};
    lim[++Llim]={1950,2550,"#FF000085","#FF0000","Superman"};
    pair<string,string> YouSIR,YouMAXSIR;
    for(int i=1;i<=Llim;i++) if(lim[i].L<=R[n]&&R[n]<=lim[i].R) YouSIR={lim[i].c2,lim[i].rnknm};
    for(int i=1;i<=Llim;i++) if(lim[i].L<=rrrrr&&rrrrr<=lim[i].R) YouMAXSIR={lim[i].c2,lim[i].rnknm};






cout<<R"aaa(
<head>
    <link rel="stylesheet" type="text/css" href="./../styles2.css">
    <link rel="icon" type="image/x-icon" href="./../favicon.png">
    <title>Toilet Scuffle Rating</title>
</head>
<body>
)aaa"<<endl;
cout<<"    <div class=\"header\">\n";
printf("        <div class=\"nag\" style=\"width: %.0lfpx;margin: auto;\">\n",wid-50);printf("\n");
printf("            <span style=\"font-size:10px;color: %s;\">%s</span>",YouSIR.first.c_str(),YouSIR.second.c_str());printf("\n");
printf("            <p style=\"font-family: 'Noto Mono';font-size:35px;margin-top: 0em;margin-bottom:0em;color: %s; \"><b>%s</b></p>\n",YouSIR.first.c_str(),Name.c_str());printf("\n");
printf("            <p style=\"font-size:22px\">  Rating: <b style=\"color: %s\">%.0lf</b></p>\n",YouSIR.first.c_str(),R[n]);printf("\n");
printf("            <p >  Max: <b style=\"color: %s\">%s, %.0lf</b></p>\n",YouMAXSIR.first.c_str(),YouMAXSIR.second.c_str(),rrrrr);printf("\n");
printf("        </div>");printf("\n");
printf("        <div class=\"grph\" style=\"width: %.0lfpx;margin: auto;\">\n",wid);
printf("            <canvas id=\"graph\" width=\"%.0lf\" height=\"%.0lf\"> </canvas>",wid,heig+20);printf("\n");
printf("            <script>");printf("\n");
printf("                var c = document.getElementById(\"graph\");");printf("\n");
printf("                var pnt1_1 = c.getContext(\"2d\");");printf("\n");
printf("                var pnt1_2 = c.getContext(\"2d\");");printf("\n");





    for(int i=1;i<=n;i++) cerr<<R[i]<<' '<<Date[i]<<endl;
    init("ptr1");init("lln1");init("fnt1");cout<<endl;
    cerr<<k1<<endl;
    for(int i=1;i<=Llim;i++)
    {
        double L=(lim[i].L-r1+k1*x11)/k1;
        // k1*lim[i].L-k1*x11+r1;
        double R=(lim[i].R-r1+k1*x11)/k1;
        swap(L,R);
        // cerr<<"sss "<<L<<' '<<R<<endl;
        if(R<0) continue;
        if(L>heig) continue;
        if(R<=heig) txt("fnt1",R,to_string(lim[i].L));
        L=max(L,0.0),R=min(R,heig);
        colb("ptr1",lim[i].c,{25,L},{wid,R});
    }
    for(int i=1;i<=n;i++)
    {
        drcir(P[i]);
        if(i==1) continue;
        drln("lln1",P[i-1],P[i]);
    }

    cout<<R"aaa(


            </script> 
        </div>
    </div>
</body>
    )aaa";
    return 0;
}
