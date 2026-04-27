#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, tq;
    cout << "Enter number of processes: ";
    cin >> n;

    int at[n], bt[n], rt[n], ct[n], tat[n], wt[n];

    for(int i=0;i<n;i++){
        cout << "Process" << i+1 << " Arriaval Time: ";
        cin >> at[i];
        cout << "Process" << i+1 << " Burst Time: ";
        cin >> bt[i];
        rt[i] = bt[i];
    }

    cout << "Enter Time Quantum: ";
    cin >> tq;

    queue<int> q;
    bool visited[n] = {0};

    int time = 0, completed = 0;

    // push first arriving process
    for(int i=0;i<n;i++){
        if(at[i] == 0){
            q.push(i);
            visited[i] = true;
        }
    }

    cout << "\nGantt Chart:\n";

    while(completed < n){

        if(q.empty()){
            time++;
            for(int i=0;i<n;i++){
                if(at[i] <= time && !visited[i]){
                    q.push(i);
                    visited[i] = true;
                }
            }
            continue;
        }

        int i = q.front();
        q.pop();

        cout << "| P" << i+1 << " ";

        if(rt[i] > tq){
            time += tq;
            rt[i] -= tq;
        }
        else{
            time += rt[i];
            rt[i] = 0;

            ct[i] = time;
            tat[i] = ct[i] - at[i];
            wt[i] = tat[i] - bt[i];

            completed++;
        }

        // add newly arrived processes
        for(int j=0;j<n;j++){
            if(at[j] <= time && !visited[j]){
                q.push(j);
                visited[j] = true;
            }
        }

        // if not finished, push back
        if(rt[i] > 0){
            q.push(i);
        }
    }

    cout << "|\n";

    float totalTAT = 0, totalWT = 0;

    cout << "\nPID\tAT\tBT\tCT\tTAT\tWT\n";
    for(int i=0;i<n;i++){
        cout << i+1 << "\t"
             << at[i] << "\t"
             << bt[i] << "\t"
             << ct[i] << "\t"
             << tat[i] << "\t"
             << wt[i] << "\n";

        totalTAT += tat[i];
        totalWT += wt[i];
    }

    cout << "\nAverage TAT = " << totalTAT/n;
    cout << "\nAverage WT = " << totalWT/n;

    return 0;
}