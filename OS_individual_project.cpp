#include<bits/stdc++.h>
#include<time.h>

using namespace std;

int number,id=0,quantum;
struct st
{
    int id,start,finish,arrival_time,service_time,service_time2,turnaround_time,waiting_time,last_run,priority;
}job[50];

vector<int>v,v2;

void sort_by_arrival_time();
void sort_by_service_time();
void sort_by_priority();
void drawline(int,int);
void FCFS(void);
void SJF(void);
void SRTF(void);
void Priority_scheduling(void);
void Round_Robin(void);
void show_diagram();
int show_output();
void gotoxy(int x,int y)
{
    printf("%c[%d;%df",0x1B,y,x);
}
void sleep(unsigned int ms)
{
    clock_t goal=ms+clock();
    while(goal>clock());
}
void intput1(void)
{
    int x=5,y=10,i;
        gotoxy(x+3,y); cout<<"Process";
        gotoxy(x+15,y); cout<<"Arrival time";
        gotoxy(x+30,y); cout<<"Service time";
        drawline(11,45);
        x=8;y=11;
        for(i=1;i<=number;i++)
        {
            gotoxy(x,y+i); cout<<"P"<<i;
            gotoxy(x+15,y+i); cin>>job[i].arrival_time;
            gotoxy(x+30,y+i); cin>>job[i].service_time;
            job[i].id=i;
            job[i].service_time2=job[i].service_time;

        }
}
void intput2(void)
{
    int x=5,y=10,i;
        gotoxy(x+3,y); cout<<"Process";
        gotoxy(x+15,y); cout<<"Service time";
        gotoxy(x+30,y); cout<<"Priority";
        drawline(11,45);
        x=8;y=11;
        for(i=1;i<=number;i++)
        {
            gotoxy(x,y+i); cout<<"P"<<i;
            gotoxy(x+15,y+i); cin>>job[i].service_time;
            gotoxy(x+30,y+i); cin>>job[i].priority;
            job[i].id=i;
            job[i].service_time2=job[i].service_time;

        }
}
void intput3(void)
{
    int x=5,y=10,i;
        gotoxy(x+3,y); cout<<"Process";
        gotoxy(x+15,y); cout<<"Service time";
        drawline(11,30);
        x=8;y=11;
        for(i=1;i<=number;i++)
        {
            gotoxy(x,y+i); cout<<"P"<<i;
            gotoxy(x+15,y+i); cin>>job[i].service_time;
            job[i].id=i;
            job[i].service_time2=job[i].service_time;

        }
        cout<<"Enter time quantum: ";
        cin>>quantum;
}
void intput4(void)
{
    int x=5,y=10,i;
        gotoxy(x+3,y); cout<<"Process";
        gotoxy(x+15,y); cout<<"Service time";
        drawline(11,30);
        x=8;y=11;
        for(i=1;i<=number;i++)
        {
            gotoxy(x,y+i); cout<<"P"<<i;
            gotoxy(x+15,y+i); cin>>job[i].service_time;
            job[i].id=i;
            job[i].service_time2=job[i].service_time;

        }
}
void ganttchart1(int y)
{
  cout<<endl<<"     Gantt Chart:"<<endl;
  drawline(y+3,70);
  int i;
  cout<<"       ";
  for(i=1;i<=number;i++)
  {
      cout<<"| "<<job[i].start<<" | P"<<job[i].id<<" ";
  }
  cout<<"| "<<job[number].finish<<" |"<<endl;
  drawline(y+5,70);
}
void ganttchart2(int y)
{
  cout<<endl<<"     Gantt Chart:"<<endl;
  drawline(y+3,70);
  int i,cnt;
  cout<<"       ";
  cnt=0;
  for(i=0;i<v.size();i++)
  {
      if(i==0||v[i]!=v[i-1])
      {
          cout<<"| "<<cnt<<" | P"<<job[v[i]].id<<" ";
      }
      cnt++;
  }
  cout<<"| "<<cnt<<" |";
  drawline(y+5,70);
}
void ganttchart3(int y)
{
  cout<<endl<<"    Gantt Chart:"<<endl;
  drawline(y+3,85);
  int i,cnt,d;
  cout<<"    ";
  cnt=0;d=0;
  for(i=0;i<v2.size();i++)
  {
      if(i==0||v2[i]!=v2[i-1]||d>=quantum)
      {
          d=0;
          cout<<"| "<<cnt<<" | P"<<job[v2[i]].id<<" ";
      }
      d++;
      cnt++;
  }
  cout<<"| "<<cnt<<" |";
  drawline(y+5,85);
}
int main()
{

        int i,x=5,y=10,choice;
        while(1)
        {
            system("clear");
            v.clear();
            v2.clear();
            cout<<"Job Scheduling algorithm list:"<<endl;
            cout<<" 1. First Come First Served (FCFS)."<<endl;
            cout<<" 2. Shortest Job First (SJF)."<<endl;
            cout<<" 3. SRTF"<<endl;
            cout<<" 4. Priority Scheduling"<<endl;
            cout<<" 5. Round Robin Scheduling (RR)."<<endl;
            cout<<" 0. Exit."<<endl;
            cout<<"Your Choice: ";
            cin>>choice;
            if(choice==0)
                break;
            else if(choice<0||choice>5)
            {
                 cout<<" Sorry wrong choice. Please try again."<<endl;
                 sleep(1000000);
                 continue;
            }
        cout<<"Enter total number of service:";
        cin>>number;
        if(choice==1)
        {
            intput1();
            FCFS();
            system("clear");
            x=20;y=2;
            gotoxy(x,y);
            cout<<"First Come First Served (FCFS) job scheduling."<<endl;
            y=show_output();
            ganttchart1(y);
        }
        else if(choice==2)
        {
            intput4();
            SJF();
            system("clear");
            x=20;y=2;
            gotoxy(x,y);
            cout<<"Shortest Job First (SJF) job scheduling."<<endl;
            y=show_output();
            ganttchart1(y);
        }
        else if(choice==3)
        {
            intput1();
            SRTF();
            system("clear");
            x=15;y=2;
            gotoxy(x,y);
            cout<<"Shortest Remaining Time First (SRTF) job scheduling."<<endl;
            y=show_output();
            ganttchart2(y);
        }
        else if(choice==4)
        {
            intput2();
            Priority_scheduling();
            system("clear");
            x=30;y=2;
            gotoxy(x,y);
            cout<<"Priority Scheduling."<<endl;
            y=show_output();
            ganttchart1(y);
        }
        else if(choice==5)
        {
            intput3();
            Round_Robin();
            system("clear");
            x=25;y=2;
            gotoxy(x,y);
            cout<<"Round Robin job scheduling."<<endl;
            y=show_output();
            ganttchart3(y);
        }
        cout<<endl<<"Press [Enter] to continue............";
        char ch;
        getchar();
        scanf("%c",&ch);
        }

}
void drawline(int y,int len)
{
    int i,x=5;
    gotoxy(x,y);
    for(i=0;i<len;i++)
    {
        cout<<"-";
    }
    cout<<endl;
}
int show_output(void)
{

    int x=5,y=3,n;
    gotoxy(x+5,y); cout<<"Process";
    gotoxy(x+15,y); cout<<"Waiting time";
    gotoxy(x+30,y); cout<<"Turnaround time";
    gotoxy(x+50,y); cout<<"Finish time";
    drawline(4,70);
    int i;y=4;x=7;
    for(i=1;i<=number;i++)
    {
        gotoxy(x+5,y+i); cout<<"P"<<job[i].id;
        gotoxy(x+15,y+i); cout<<job[i].waiting_time;
        gotoxy(x+30,y+i); cout<<job[i].turnaround_time;
        gotoxy(x+50,y+i); cout<<job[i].finish;
    }
     drawline(y+number+1,70);
     return y+number+1;
}

void FCFS(void)
{
    int i,j,cpu_free_at;
    sort_by_arrival_time();
    cpu_free_at=0;
    for(i=1;i<=number;i++)
    {
        if(cpu_free_at<=job[i].arrival_time)
        {
            job[i].waiting_time=0;
            job[i].start=job[i].arrival_time;
            job[i].finish=job[i].start+job[i].service_time;
            cpu_free_at=job[i].finish;
            job[i].turnaround_time=job[i].service_time;
        }
        else
        {
            job[i].waiting_time=cpu_free_at-job[i].arrival_time;
            job[i].start=cpu_free_at;
            job[i].finish=job[i].start+job[i].service_time;
            cpu_free_at=job[i].finish;
            job[i].turnaround_time=job[i].waiting_time+job[i].service_time;
        }
    }

}

void SJF(void)
{
    int i,j,cpu_free_at;
    sort_by_service_time();
    cpu_free_at=0;
    for(i=1;i<=number;i++)
    {
            job[i].waiting_time=cpu_free_at;
            job[i].start=cpu_free_at;
            job[i].finish=job[i].start+job[i].service_time;
            cpu_free_at=job[i].finish;
            job[i].turnaround_time=job[i].waiting_time+job[i].service_time;
    }
}

void SRTF(void)
{
    int i,j;
    for(i=1;i<=number;i++)
        job[i].last_run=-1;
    for(i=0;i<=1000;i++)
    {
        int idx=-1;
        for(j=1;j<=number;j++)
        {
            if(job[j].arrival_time<=i&&job[j].service_time>0)
            {
                idx=j;
                break;
            }

        }
        if(idx!=-1)
        {
            for(j=1;j<=number;j++)
            {
                if(job[j].arrival_time<=i&&job[j].service_time>0&&job[j].service_time<job[idx].service_time)
                {
                    idx=j;
                }
            }
            if(job[idx].last_run==-1)
            {
                job[idx].waiting_time=i-job[idx].arrival_time;
                job[idx].last_run=i;
                job[idx].service_time--;
                if(job[idx].service_time==0)
                    job[idx].finish=i+1;
            }
            else
            {
                job[idx].waiting_time+=i-job[idx].last_run-1;
                job[idx].last_run=i;
                job[idx].service_time--;
                if(job[idx].service_time==0)
                    job[idx].finish=i+1;
            }
            v.push_back(idx);
        }
    }
    for(i=1;i<=number;i++)
    {
        job[i].turnaround_time=job[i].waiting_time+job[i].service_time2;
    }
}

void Priority_scheduling(void)
{
    int i,j,cpu_free_at;
    sort_by_priority();
    cpu_free_at=0;
    for(i=1;i<=number;i++)
    {
        if(cpu_free_at<=job[i].arrival_time)
        {
            job[i].waiting_time=0;
            job[i].start=job[i].arrival_time;
            job[i].finish=job[i].start+job[i].service_time;
            cpu_free_at=job[i].finish;
            job[i].turnaround_time=job[i].service_time;
        }
        else
        {
            job[i].waiting_time=cpu_free_at-job[i].arrival_time;
            job[i].start=cpu_free_at;
            job[i].finish=job[i].start+job[i].service_time;
            cpu_free_at=job[i].finish;
            job[i].turnaround_time=job[i].waiting_time+job[i].service_time;
        }
    }

}

void Round_Robin(void)
{
    deque<int>Q;
    int i,cnt;
    for(i=1;i<=number;i++)
    {
        Q.push_back(i);
        job[i].last_run=-1;
        job[i].waiting_time=0;
    }
    cnt=0;
    while(!Q.empty())
    {
        i=Q.front();
        Q.pop_front();
        if(job[i].last_run==-1)
        {
            job[i].waiting_time=cnt;
        }
        else
        {
            job[i].waiting_time+=cnt-job[i].last_run;
        }
        if(job[i].service_time>quantum)
        {
            job[i].service_time-=quantum;
            job[i].last_run=quantum+cnt;
            Q.push_back(i);
            cnt+=quantum;
            for(int j=0;j<quantum;j++)
                v2.push_back(i);
        }
        else
        {
            job[i].finish=cnt+job[i].service_time;
            cnt+=job[i].service_time;
            for(int j=0;j<job[i].service_time;j++)
                v2.push_back(i);
        }
    }
    for(i=1;i<=number;i++)
    {
        job[i].turnaround_time=job[i].waiting_time+job[i].service_time2;
    }
}

void sort_by_arrival_time(void)
{
    int i,j;
    st temp;
    for(i=1;i<=number;i++)
    {
        for(j=i+1;j<=number;j++)
        {
            if(job[i].arrival_time>job[j].arrival_time)
            {
                temp=job[i];
                job[i]=job[j];
                job[j]=temp;
            }
            else if(job[i].arrival_time==job[j].arrival_time)
            {
                if(job[i].id>job[j].id)
                {
                    temp=job[i];
                    job[i]=job[j];
                    job[j]=temp;
                }
            }
        }
    }
}

void sort_by_service_time(void)
{
    int i,j;
    st temp;
    for(i=1;i<=number;i++)
    {
        for(j=i+1;j<=number;j++)
        {
            if(job[i].service_time>job[j].service_time)
            {
                temp=job[i];
                job[i]=job[j];
                job[j]=temp;
            }
            else if(job[i].service_time==job[j].service_time)
            {
                if(job[i].arrival_time<job[j].arrival_time)
                {
                    temp=job[i];
                    job[i]=job[j];
                    job[j]=temp;
                }
            }
        }
    }
}
void sort_by_priority(void)
{
    int i,j;
    st temp;
    for(i=1;i<=number;i++)
    {
        for(j=i+1;j<=number;j++)
        {
            if(job[i].priority>job[j].priority)
            {
                temp=job[i];
                job[i]=job[j];
                job[j]=temp;
            }
            else if(job[i].priority==job[j].priority)
            {
                if(job[i].id>job[j].id)
                {
                    temp=job[i];
                    job[i]=job[j];
                    job[j]=temp;
                }
            }
        }
    }
}
