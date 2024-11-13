#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<vector>
#include<map>
using namespace std;

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

int main()
{
    int tototot=0;
    // freopen("contestant.in","r",stdin);
    // FILE *inF=fopen("contestant.in","r");
    freopen("compete.in","r",stdin);
    // fscanf(inF,"%d",&numberOfStudents);
    cin>>numberOfStudents;
    for(int i=1;i<=numberOfStudents;i++)
    {
        double Rating;
        string thisStudentName;
        // thisStudentName.resize(50);
        // fscanf(inF,"%s",&thisStudentName[0]);
        cin>>thisStudentName;
        // system("cd name");
        system(("touch ./name/"+thisStudentName).c_str());
        // system("cd ..");
        freopen(("./name/"+thisStudentName).c_str(),"w",stdout);
        cout<<thisStudentName<<endl;
        // cin>>Rating;
        // string sss="";
        // for(int _=0;_<=50;_++) 
        // {
        //     sss+=thisStudentName[_];
        //     if(thisStudentName[_]=='\0') break;
        // }
        // cout<<sss<<endl;
        Rating=initRating;
        studentNumber[thisStudentName]=i;
        oldRating[i]=newRating[i]=Rating;
        studentName[i]=thisStudentName;
    }// fclose(inF); 
    freopen("Rating.out","w",stdout);
    // freopen("compete.in","r",stdin);
    // (cin>>curNumStudents);
    // cout<<curNumStudents<<endl;
    int T=1000;cin>>Date[0];
    while((cin>>curNumStudents)&&T--)
    {
        memset(perf,-0x3f,sizeof perf);
        memset(isInContest,0,sizeof isInContest);
        memset(contestNumber,0,sizeof contestNumber);
        memset(curContestRank,0,sizeof curContestRank);
        tototot++;
        cin>>Date[tototot];int TP=0;
        for(int i=1;i<=curNumStudents;i++)
        {
            string studentName;
            int Score;double Rank;
            cin>>Rank>>studentName;Score=100-Rank;
            if(studentName=="ShiYunHao09") {TP++;continue;}
            cout<<Rank<<' '<<studentName<<endl;Rank-=TP;
            int idOfStudent=studentNumber[studentName];
            isInContest[idOfStudent]=i-TP;
            contestNumber[i-TP]=idOfStudent;
            curContestRank[i-TP]=Rank;
        }curNumStudents-=TP;

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
        }sort(a+1,a+numberOfStudents+1,cmp);// a[0].studentName[0]=numberOfStudents;
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
    cout<<numberOfStudents<<endl;
    for(int i=1;i<=numberOfStudents;i++) 
    {
        printf("%s %.0lf %.0lf %.0lf %.0lf %.2lf\n"
            ,a[i].s.c_str(),double(int(a[i].oR)),double(int(a[i].r)),double((int)a[i].r-(int)a[i].oR),a[i].perf,a[i].seed);
    }
    cout<<tototot<<endl;
    node b[MXN];
    for(int i=1;i<=tototot;i++)
    {
        // b=history[i];
        auto *b=history[i];
        for(int j=1;j<=numberOfStudents;j++) 
        {
            printf("%s %.0lf %.0lf %.0lf %.0lf %.2lf\n"
                ,b[j].s.c_str(),double(int(b[j].oR)),double(int(b[j].r)),double((int)b[j].r-(int)b[j].oR),b[j].perf,b[j].seed);
            historyRating[i][j]=b[j].r;
            if(b[j].perf<=-1e5) historyRating[i][j]=-1e5;
        }
    }int lt=initRating;
    for(int i=1;i<=numberOfStudents;i++)
    {
        system(("mkdir "+studentName[i]).c_str());
        freopen(("./graph_csv/"+studentName[i]+".csv").c_str(),"w",stdout);
        cout<<"Date,Rating\n";
        int lt=1400,lt2=0;
        for(int j=1;j<=tototot;j++)
        {
            if(historyRating[j][i]<=-1e5) continue;
            if(lt2==0) {cout<<Date[j-1]<<','<<lt<<endl;lt2=1;}
            cout<<Date[j]<<','<<historyRating[j][i]<<endl;
            lt=historyRating[j][i];
        }
        system(("python3 generator.py < ./name/"+studentName[i]).c_str());
    }
    return 0;
}
