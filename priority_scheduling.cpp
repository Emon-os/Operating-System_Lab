#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;

    cout << "Enter number of processes: ";
    cin >> n;

    vector<int> pid(n), bt(n), pr(n), wt(n), tat(n);

    // Input
    for (int i = 0; i < n; i++) {
        pid[i] = i + 1;

        cout << "Enter burst time for process " << i + 1 << ": ";
        cin >> bt[i];

        cout << "Enter priority for process " << i + 1 << ": ";
        cin >> pr[i];
    }

    // Sort by priority (lower value = higher priority)
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (pr[j] < pr[i]) {
                swap(pr[i], pr[j]);
                swap(bt[i], bt[j]);
                swap(pid[i], pid[j]);
            }
        }
    }

    // Waiting Time
    wt[0] = 0;
    for (int i = 1; i < n; i++) {
        wt[i] = wt[i - 1] + bt[i - 1];
    }

    // Turnaround Time
    for (int i = 0; i < n; i++) {
        tat[i] = wt[i] + bt[i];
    }

    // Output table
    cout << "\nPID\tPriority\tBurst\tWaiting\tTurnaround\n";
    for (int i = 0; i < n; i++) {
        cout << pid[i] << "\t"
             << pr[i] << "\t\t"
             << bt[i] << "\t"
             << wt[i] << "\t"
             << tat[i] << endl;
    }

    return 0;
}
