/*
Question 8 — Priority Scheduling
Write a program to implement:
Preemptive priority scheduling
Calculate:
    Completion Time
    Waiting Time
    Turnaround Time
*/
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cout << "Enter number of processes: ";
    cin >> n;

    int pid[n], at[n], bt[n], rt[n], pr[n];
    int ct[n], tat[n], wt[n];

    for(int i=0;i<n;i++){
        pid[i] = i+1;

        cout << "Process " << pid[i] << " Arrival Time: ";
        cin >> at[i];

        cout << "Process " << pid[i] << " Burst Time: ";
        cin >> bt[i];

        cout << "Process " << pid[i] << " Priority: ";
        cin >> pr[i];

        rt[i] = bt[i];
    }

    int time = 0, completed = 0;

    while(completed < n){

        int idx = -1;

        for(int i=0;i<n;i++){
            if(at[i] <= time && rt[i] > 0){

                if(idx == -1 ||
                   pr[i] > pr[idx] ||                     // higher priority
                   (pr[i] == pr[idx] && at[i] < at[idx]) ||  // earlier arrival
                   (pr[i] == pr[idx] && at[i] == at[idx] && pid[i] < pid[idx]))
                {
                    idx = i;
                }
            }
        }

        if(idx == -1){
            time++;
        }
        else{
            rt[idx]--;
            time++;

            if(rt[idx] == 0){
                completed++;
                ct[idx] = time;
                tat[idx] = ct[idx] - at[idx];
                wt[idx] = tat[idx] - bt[idx];
            }
        }
    }

    cout << "\nPID\tAT\tBT\tPR\tCT\tTAT\tWT\n";

    for(int i=0;i<n;i++){
        cout << pid[i] << "\t"
             << at[i] << "\t"
             << bt[i] << "\t"
             << pr[i] << "\t"
             << ct[i] << "\t"
             << tat[i] << "\t"
             << wt[i] << "\n";
    }

    return 0;
}