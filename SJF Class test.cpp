#include <iostream>
using namespace std;

int main() {
    const int MAXP = 100;
    int p[MAXP][4],n,totalWT = 0, totalTAT = 0;
    float avgWT = 0, avgTAT = 0;

    cout << "Processes Number: ";
    cin >> n;

    cout << "Enter Burst Time:\n";
    for (int i = 0; i < n; i++) {
        cout << "Process " << i + 1 << ": ";
        cin >> p[i][1]; //
        p[i][0] = i + 1; //
    }

    for (int i = 0; i < n; i++) {
        int min = i;
        for (int j = i + 1; j < n; j++) {
            if (p[j][1] < p[min][1]) {
                min = j;
            }
        }
        swap(p[i][1], p[min][1]);
        swap(p[i][0], p[min][0]);
    }


    p[0][2] = 0;
    for (int i = 1; i < n; i++) {
        p[i][2] = p[i - 1][2] + p[i - 1][1];
        totalWT += p[i][2];
    }

    avgWT = (float)totalWT / n;


    cout << "PID\tBT\tWT\tTAT\n";
    for (int i = 0; i < n; i++) {
        p[i][3] = p[i][1] + p[i][2];
        totalTAT += p[i][3];
        cout << "P" << p[i][0] << "\t" << p[i][1] << "\t" << p[i][2] << "\t" << p[i][3] << endl;
    }

    avgTAT = (float)totalTAT / n;

    cout << "Avg WT = " << avgWT << endl;
    cout << "Avg TAT = " << avgTAT << endl;

    return 0;
}


