#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;

    cout << "Enter number of processes: ";
    cin >> n;

    cout << "Enter number of resources: ";
    cin >> m;

    vector<vector<int>> alloc(n, vector<int>(m));
    vector<vector<int>> maxm(n, vector<int>(m));
    vector<vector<int>> need(n, vector<int>(m));
    vector<int> avail(m);
    vector<int> finish(n, 0);
    vector<int> safe;

    // Allocation matrix
    cout << "\nEnter Allocation Matrix:\n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> alloc[i][j];

    // Maximum matrix
    cout << "\nEnter Maximum Matrix:\n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> maxm[i][j];

    // Available resources (DIRECT INPUT)
    cout << "\nEnter Available Resources:\n";
    for (int j = 0; j < m; j++)
        cin >> avail[j];

    // Need matrix
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            need[i][j] = maxm[i][j] - alloc[i][j];

    // Safety algorithm
    while (safe.size() < n) {
        bool found = false;

        for (int i = 0; i < n; i++) {
            if (!finish[i]) {
                bool canRun = true;

                for (int j = 0; j < m; j++) {
                    if (need[i][j] > avail[j]) {
                        canRun = false;
                        break;
                    }
                }

                if (canRun) {
                    for (int j = 0; j < m; j++)
                        avail[j] += alloc[i][j];

                    safe.push_back(i);
                    finish[i] = 1;
                    found = true;
                }
            }
        }

        if (!found) {
            cout << "\nSystem is NOT in SAFE state\n";
            return 0;
        }
    }

    cout << "\nSystem is in SAFE state\nSafe sequence: ";

    for (int i = 0; i < n; i++) {
        cout << "P" << safe[i];
        if (i != n - 1) cout << " -> ";
    }

    cout << endl;
    return 0;
}