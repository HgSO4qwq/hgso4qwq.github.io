#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<vector>
#include<map>
using namespace std;
#define displaybots 0
#define onlythefirstcontest 0
#define generate 1

const int MXN=110;
map<string,int> studentNumber;
map<int,string> studentName;
double oldRating[MXN],newRating[MXN];
int numberOfStudents,curNumStudents;
double curContestRank[MXN];
int isInContest[MXN],contestNumber[MXN];
double Seed[MXN],perf[MXN],kSeed[MXN];
double Prob(double RatingA,double RatingB) {return (double)1/((double)1+pow(10,(double)((RatingB-RatingA)/400)));}
struct node {string s;double oR,r;double perf;double seed;}a[MXN];
const int MXK=1010,initRating=1400;
node history[MXK][MXN];string Date[MXK];
double historyRating[MXN][MXN];
bool cmp(node a,node b) {return a.r>b.r;}
long long shhh[MXN];

double botps[12]={0,0.417,0.540,0.635,0.712,0.776,0.832,0.881,0.924,0.964,1},botn=9;
string botnm[13]={"","bot1","bot2","bot3","bot4","bot5","bot6","bot7","bot8","bot9","bot10"};

const int N=MXN;
vector<string> paimon[N];

signed main()
{
    int tototot=0;
    freopen("compete.in","r",stdin);
    cin>>numberOfStudents;
    for(int i=1;i<=numberOfStudents;i++)
    {
        double Rating;
        string thisStudentName;
        cin>>thisStudentName;
        system(("touch ./name/"+thisStudentName).c_str());
        freopen(("./name/"+thisStudentName).c_str(),"w",stdout);
        cout<<thisStudentName<<endl;
        Rating=initRating;
        studentNumber[thisStudentName]=i;
        oldRating[i]=newRating[i]=Rating;
        studentName[i]=thisStudentName;
    }
    freopen("Rating.out","w",stdout);
    cin>>Date[0]>>shhh[0];
    int T=1e6;
    if(onlythefirstcontest) T=1;
    while(cin>>curNumStudents&&T--)
    {
        memset(perf,-0x3f,sizeof perf);
        memset(isInContest,0,sizeof isInContest);
        memset(contestNumber,0,sizeof contestNumber);
        memset(curContestRank,0,sizeof curContestRank);




        tototot++;cerr<<tototot<<endl;
        cin>>Date[tototot]>>shhh[tototot];int TP=0;
        int pt=0,diffpbs=0,lt=0;cout<<"num: "<<curNumStudents<<endl;
        for(int i=1;i<=curNumStudents;i++)
        {
            string studentName;
            int Score;double Rank;
            cin>>Rank>>studentName;
            if(studentName=="ShiYunHao09") {continue;}
            if(Rank==lt) paimon[diffpbs].push_back(studentName);
            else paimon[++diffpbs].push_back(studentName);
        }
        int rL=0,rR=0;curNumStudents=0;
        for(int i=1;i<=diffpbs;i++)
        {
            rL=rR+1;
            rR=rL+paimon[i].size()-1;
            curNumStudents+=paimon[i].size();
            string studentName;
            double avrk=(rL+rR)/2;
            for(auto u:paimon[i])
            {
                studentName=u;
                double Rank=avrk;
                cout<<Rank<<' '<<studentName<<endl;
                int idOfStudent=studentNumber[studentName];
                isInContest[idOfStudent]=i;
                contestNumber[i]=idOfStudent;
                curContestRank[i]=Rank;
            }
            paimon[i].clear();
        }







        // Perf Calculation
        for(int i=1;i<=curNumStudents;i++)
        {
            int idi=contestNumber[i];
            Seed[idi]=1;
            for(int j=1;j<=curNumStudents;j++)
            {
                if(i==j) continue;
                int idj=contestNumber[j];
                Seed[idi]+=Prob(oldRating[idj],oldRating[idi]);
            }kSeed[idi]=Seed[idi];
            Seed[idi]=sqrt(Seed[idi]*curContestRank[i]);
            double l=-50,r=4000,eps=0.00001;
            while(r-l>=eps)
            {
                double mid=(l+r)/2;
                double nwSeed=1;
                for(int j=1;j<=curNumStudents;j++)
                {
                    if(i==j) continue;
                    int idj=contestNumber[j];
                    nwSeed+=Prob(oldRating[idj],mid);
                }
                if(nwSeed<curContestRank[i]) r=mid;
                else l=mid;
            }
            perf[idi]=l;// cout<<i<<' '<<Seed[idi]<<endl;
            if(l>=4500) perf[idi]=4000;
        }


        // New Rating Calculation
        for(int i=1;i<=curNumStudents;i++)
        {
            double l=-50,r=4000,eps=0.00001;
            int idi=contestNumber[i];
            while(r-l>=eps)
            {
                double mid=(l+r)/2;
                double nwSeed=1;
                for(int j=1;j<=curNumStudents;j++)
                {
                    if(i==j) continue;
                    int idj=contestNumber[j];
                    nwSeed+=Prob(oldRating[idj],mid);
                }
                if(nwSeed<Seed[idi]) r=mid;
                else l=mid;
            }cout<<i<<' '<<oldRating[idi]<<endl;
            double delt=(l-oldRating[idi])/2;
            newRating[idi]=oldRating[idi]+delt;
        }long double delt=0;
        cout<<curNumStudents<<endl;



        // Adjust Sums
        for(int i=1;i<=numberOfStudents;i++) delt+=newRating[i]-oldRating[i]; 
        for(int i=1;i<=curNumStudents;i++) 
        {
            newRating[contestNumber[i]]-=delt/curNumStudents;
            perf[contestNumber[i]]-=4*delt/curNumStudents;
        }
        long double sum=0; cout<<delt<<endl;
        for(int i=1;i<=numberOfStudents;i++)
        {
            a[i]={studentName[i],oldRating[i],newRating[i],perf[i],kSeed[i]};
            history[tototot][i]=a[i];
            oldRating[i]=newRating[i];
        }sort(a+1,a+numberOfStudents+1,cmp);
        
        
        
        // a[0].studentName[0]=numberOfStudents;
        // for(int i=1;i<=numberOfStudents;i++) 
        // {
        //     printf("%20s\t%.0lf => %.0lf\t\tChange: %.0lf\t\tPerf: %.0lf\n\t\tSeed: %.0lf"
        //         ,a[i].s.c_str(),a[i].oR,a[i].r,a[i].r-a[i].oR,a[i].perf,a[i].seed);
        // }
        // history.push_back(a);
    }
    freopen("Rating_for_iter.deprecated","w",stdout);
    for(int i=1;i<=numberOfStudents;i++) printf("%20s\t%.0lf\n",a[i].s.c_str(),a[i].r);
    freopen("Rating.board","w",stdout);
    if(displaybots) cout<<numberOfStudents<<endl;
    else cout<<numberOfStudents-10<<endl;
    for(int i=1;i<=numberOfStudents;i++) 
    {
        if((!displaybots)&&a[i].s.substr(0,3)=="bot") continue;
        printf("%s %.0lf %.0lf %.0lf %.0lf %.2lf\n"
            ,a[i].s.c_str(),double(int(a[i].oR)),double(int(a[i].r)),double((int)a[i].r-(int)a[i].oR),a[i].perf,a[i].seed);
    }
    // tototot--;
    cout<<tototot<<endl;
    cout<<numberOfStudents<<endl;
    node b[MXN];
    for(int i=1;i<=tototot;i++)
    {
        auto *b=history[i];
        for(int j=1;j<=numberOfStudents;j++) 
        {
            // cout<<b[j].r<<' ';
            if((!displaybots)&&b[j].s.substr(0,3)=="bot") continue;
            printf("%s %.0lf %.0lf %.0lf %.0lf %.2lf\n"
            ,b[j].s.c_str(),double(int(b[j].oR)),double(int(b[j].r)),double((int)b[j].r-(int)b[j].oR),b[j].perf,b[j].seed);
            historyRating[i][j]=b[j].r;
            if(b[j].perf<=-1e5) historyRating[i][j]=-1e5;
        }
    }
    
    for(int j=1;j<=numberOfStudents;j++) 
    {
        freopen(("./history/"+studentName[j]+".txt").c_str(),"w",stdout);
        // if((!displaybots)&&b[j].s.substr(0,3)=="bot") continue;
        int CCC=0;
        int lt2=0;
        for(int i=1;i<=tototot;i++)
        {
            auto *b=history[i];
            if(historyRating[i][j]<=-1e5) continue;
            if(lt2==0) {lt2=1;}
            if(lt2) CCC++;
        }
        lt2=0;
        cout<<CCC+1<<endl;
        // cout<<"1400 "<<Date[0]<<' '<<shhh[0]<<endl;
        for(int i=1;i<=tototot;i++)
        {
            auto *b=history[i];
            if(historyRating[i][j]<=-1e5) continue;
            if(lt2==0) {cout<<"1400 "<<Date[i-1]<<' '<<shhh[i-1]<<endl;lt2=1;}
            if(lt2) printf("%.0lf %s %lld\n",double(int(b[j].r)),Date[i].c_str(),shhh[i]);
        }
    }
    int lt=initRating;
    if(!generate) return 0; 
    for(int i=1;i<=numberOfStudents;i++)
    {
        if((!displaybots)&&studentName[i].substr(0,3)=="bot") continue;
        system(("mkdir "+studentName[i]).c_str());
        cout<<"Date,Rating\n";
        int lt=1400,lt2=0;
        for(int j=1;j<=tototot;j++)
        {
            if(historyRating[j][i]<=-1e5) continue;
            if(lt2==0) {cout<<Date[j-1]<<','<<lt<<endl;lt2=1;}
            cout<<Date[j]<<','<<historyRating[j][i]<<endl;
            lt=historyRating[j][i];
        }
        system(("./make "+studentName[i]).c_str());
    }
    return 0;
}
