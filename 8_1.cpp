/*
Non preemptive priority scheduling*/

#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cout << "Enter number of processes: ";
    cin >> n;

    int pid[n], at[n], bt[n], pr[n];
    int ct[n], tat[n], wt[n], done[n];

    for(int i=0;i<n;i++){
        pid[i] = i+1;

        cout << "Process " << pid[i] << " Arrival Time: ";
        cin >> at[i];

        cout << "Process " << pid[i] << " Burst Time: ";
        cin >> bt[i];

        cout << "Process " << pid[i] << " Priority: ";
        cin >> pr[i];

        done[i] = 0;
    }

    int time = 0, completed = 0;

    while(completed < n){

        int idx = -1;

        // choose highest priority (bigger number = higher priority)
        for(int i=0;i<n;i++){
            if(at[i] <= time && done[i] == 0){

                if(idx == -1 ||
                   pr[i] > pr[idx] ||
                   (pr[i] == pr[idx] && at[i] < at[idx]) ||
                   (pr[i] == pr[idx] && at[i] == at[idx] && pid[i] < pid[idx]))
                {
                    idx = i;
                }
            }
        }

        if(idx == -1){
            time++; // CPU idle
        }
        else{
            time += bt[idx]; // run FULL process (non-preemptive)

            ct[idx] = time;
            tat[idx] = ct[idx] - at[idx];
            wt[idx] = tat[idx] - bt[idx];

            done[idx] = 1;
            completed++;
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