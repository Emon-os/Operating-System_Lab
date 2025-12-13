#include <iostream>
using namespace std;

int main() {
    int n, tq;

    cout << "Enter number of processes: ";
    cin >> n;

    cout << "Enter time quantum: ";
    cin >> tq;

    int bt[n], rt[n], wt[n], tat[n], pid[n];

    for (int i = 0; i < n; i++) {
        pid[i] = i + 1;
        cout << "Enter burst time for process " << i + 1 << ": ";
        cin >> bt[i];
        rt[i] = bt[i];
        wt[i] = 0;
    }

    int time = 0;

    while (true) {
        bool done = true;

        for (int i = 0; i < n; i++) {
            if (rt[i] > 0) {
                done = false;

                if (rt[i] > tq) {
                    time += tq;
                    rt[i] -= tq;
                } else {
                    time += rt[i];
                    wt[i] = time - bt[i];
                    rt[i] = 0;
                }
            }
        }

        if (done)
            break;
    }

    for (int i = 0; i < n; i++) {
        tat[i] = bt[i] + wt[i];
    }

    cout << "\nPID\tBT\tWT\tTAT\n";
    for (int i = 0; i < n; i++) {
        cout << pid[i] << "\t" << bt[i] << "\t" << wt[i] << "\t" << tat[i] << endl;
    }

    return 0;
}
