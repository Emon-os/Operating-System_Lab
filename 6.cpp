#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cout << "Enter number of processes: ";
    cin >> n;

    int pid[n], at[n], bt[n], rt[n], ct[n], tat[n], wt[n];

    for(int i=0;i<n;i++){
        pid[i] = i+1;
        cout << "Process " << pid[i] << " Arrival Time: ";
        cin >> at[i];
        cout << "Process " << pid[i] << " Burst Time: ";
        cin >> bt[i];
        rt[i] = bt[i]; // remaining time
    }

    int time = 0, completed = 0;

    while(completed < n){
        int idx = -1;
        int minRT = 9999;

        // Find process with smallest remaining time
        for(int i=0;i<n;i++){
            if(at[i] <= time && rt[i] > 0){
                if(rt[i] < minRT){
                    minRT = rt[i];
                    idx = i;
                }
            }
        }

        if(idx == -1){
            time++; // CPU idle
        }
        else{
            rt[idx]--; // execute for 1 unit
            time++;

            // If process completes
            if(rt[idx] == 0){
                completed++;
                ct[idx] = time;
                tat[idx] = ct[idx] - at[idx];
                wt[idx] = tat[idx] - bt[idx];
            }
        }
    }

    float totalTAT = 0, totalWT = 0;

    cout << "\nPID\tAT\tBT\tCT\tTAT\tWT\n";
    for(int i=0;i<n;i++){
        cout << pid[i] << "\t"
             << at[i] << "\t"
             << bt[i] << "\t"
             << ct[i] << "\t"
             << tat[i] << "\t"
             << wt[i] << "\n";

        totalTAT += tat[i];
        totalWT += wt[i];
    }

    cout << "\nAverage TAT = " << totalTAT / n;
    cout << "\nAverage WT = " << totalWT / n;

    return 0;
}