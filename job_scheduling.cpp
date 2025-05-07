#include <iostream>
#include <algorithm>
using namespace std;

struct Job {
    char id;
    int deadline, profit;
};

bool compare(Job a, Job b) {
    return a.profit > b.profit;
}

int main() {
    Job jobs[] = {{'a', 2, 100}, {'b', 1, 19}, {'c', 2, 27}, {'d', 1, 25}, {'e', 3, 15}};
    int n = 5;
    int slot[10] = {0}, totalProfit = 0;

    sort(jobs, jobs + n, compare);

    for (int i = 0; i < n; i++) {
        for (int j = jobs[i].deadline - 1; j >= 0; j--) {
            if (slot[j] == 0) {
                slot[j] = 1;
                totalProfit += jobs[i].profit;
                cout << jobs[i].id << " ";
                break;
            }
        }
    }

    cout << "\nTotal Profit: " << totalProfit;
}

// This C++ code solves the **Job Scheduling Problem using a greedy approach**. Each job has a deadline and a profit. The goal is to schedule jobs to maximize total profit without missing deadlines, assuming only one job can be done at a time.

// Here's how it works:

// * First, it sorts all jobs in **descending order of profit**.
// * Then, it tries to assign each job to the **latest possible free time slot** before its deadline.
// * If a slot is available, it schedules the job and adds its profit to the total.
// * In the end, it prints the order of selected jobs and the total profit earned.

// This method ensures you always pick the most profitable jobs that can be completed on time.
