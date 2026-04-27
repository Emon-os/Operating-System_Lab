#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, m;

    cout << "Enter number of processes: ";
    cin >> n;

    cout << "Enter number of resource types: ";
    cin >> m;

    vector<vector<int>> alloc(n, vector<int>(m));
    vector<vector<int>> request(n, vector<int>(m));
    vector<int> avail(m);

    // Input Allocation Matrix
    cout << "Enter Allocation Matrix:\n";
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> alloc[i][j];
        }
    }

    // Input Request Matrix
    cout << "Enter Request Matrix:\n";
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> request[i][j];
        }
    }

    // Input Available Resources
    cout << "Enter Available Resources:\n";
    for(int j = 0; j < m; j++){
        cin >> avail[j];
    }

    vector<int> work = avail;
    vector<bool> finish(n, false);

    // Step 1: Mark processes with no allocation as finished
    for(int i = 0; i < n; i++){
        bool zero = true;
        for(int j = 0; j < m; j++){
            if(alloc[i][j] != 0){
                zero = false;
                break;
            }
        }
        if(zero) finish[i] = true;
    }

    // Step 2: Deadlock Detection
    bool found = true;

    while(found){
        found = false;

        for(int i = 0; i < n; i++){
            if(!finish[i]){
                bool canRun = true;

                // Check if request <= work
                for(int j = 0; j < m; j++){
                    if(request[i][j] > work[j]){
                        canRun = false;
                        break;
                    }
                }

                // If yes, process finishes
                if(canRun){
                    for(int j = 0; j < m; j++){
                        work[j] += alloc[i][j];
                    }
                    finish[i] = true;
                    found = true;
                }
            }
        }
    }

    // Step 3: Result
    bool deadlock = false;

    cout << "\nDeadlock Result:\n";
    for(int i = 0; i < n; i++){
        if(!finish[i]){
            cout << "Process P" << i << " is in Deadlock\n";
            deadlock = true;
        }
    }

    if(!deadlock){
        cout << "No Deadlock. All processes completed.\n";
    }

    return 0;
}