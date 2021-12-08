//sjf algorithm(for arrival time t = 0)
#include <iostream>
#include <algorithm>
using namespace std;

//Process Class
class Process{
    public:
        int pid; //process id
        int bt;  //burst time
        int wt;  //waiting time   
        int tat; //turn around time
        bool operator<(Process b); //for sorting burst time
};

bool Process::operator<(Process b){
    return (this->bt<b.bt);
}

//sjf() finds wt,tat,avg_wt,avg_tat using SJF algorithm
void sjf(Process p[],int n){
    sort(p,p+n);
    int avg_wt,avg_tat;
    avg_wt = 0;
    avg_tat = p[0].bt; //process at 0 index have least bt
    p[0].wt = 0;    //first executed process's wt is 0
    p[0].tat = p[0].bt;
    
    for(int i=1; i<n; i++){
        p[i].wt = p[i-1].bt + p[i-1].wt;
        p[i].tat = p[i].wt + p[i].bt;
        avg_wt+=p[i].wt;
        avg_tat+=p[i].tat;
    }
    
    avg_wt/=n;
    avg_tat/=n;

    cout<<"\nProcess\t\tburst time\twaiting time\tturnaround time\n";
    for(int i=0; i<n; i++){
        cout<<"P"<<p[i].pid<<"\t\t"<<p[i].bt<<"\t\t"<<p[i].wt<<"\t\t"<<p[i].tat<<"\n";
    }
    
    cout<<"\n\nAverage Waiting Time:  "<<avg_wt<<"\n";
    cout<<"Average Turn around Time:  "<<avg_tat<<"\n";
}

//main function
int main(){
    int n,avg_wt,avg_tat;
    cout<<"\nEnter number of Process: ";
    cin>>n;
    Process p[n];

    cout<<"\nEnter Burst time for each Process:\n";
    for(int i=0; i<n; i++){
        p[i].pid = (i+1);
        cout<<"Process P"<<(i+1)<<" : ";
        cin>>p[i].bt;
    }
    
    sjf(p,n);
    return 0;
}