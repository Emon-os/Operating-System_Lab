/*
Question 4 — FCFS Scheduling
Write a program to implement First Come First Serve (FCFS) CPU scheduling algorithm
and calculate:
    Waiting Time
    Turnaround Time
    Average Waiting Time
    Average Turnaround Time
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cout << "Enter number of processes: ";
    cin >> n;

    int pid[n], at[n], bt[n], ct[n], tat[n], wt[n];

    for (int i = 0; i < n; i++)
    {
        pid[i] = i + 1;

        cout << "Process: " << pid[i] << " Arrival time: ";
        cin >> at[i];

        cout << "Process: " << pid[i] << " Burst time: ";
        cin >> bt[i];
    }

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i+1 ; j < n; j++)
        {
            if (at[i] > at[j])
            {
                swap(at[i], at[j]);
                swap(bt[i], bt[j]);
                swap(pid[i], pid[j]);
            }
        }
    }

    ct[0] = at[0] + bt[0];

    for (int i = 1; i < n; i++)
    {
        if (ct[i - 1] < at[i])
        {
            ct[i] = at[i] + bt[i];
        }
        else
        {
            ct[i] = ct[i - 1] + bt[i];
        }
    }

    float totalTAT = 0, totalWt = 0;

    for (int i = 0; i < n; i++)
    {
        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];

        totalTAT += tat[i];
        totalWt += wt[i];
    }

    cout << "\nPID\tAT\tBT\tCT\tTAT\tWT\n";
    for (int i = 0; i < n; i++)
    {
        cout << pid[i] << '\t' << at[i] << "\t" << bt[i] << "\t" << ct[i] << "\t" << tat[i] << "\t" << wt[i] << "\n";
    }

    cout << "\nAverage TAT = " << totalTAT / n;
    cout << "\nAverage WT = " << totalWt / n;

    return 0;
}