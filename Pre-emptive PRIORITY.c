//Write a C/C++ program to calculate AWT, ATT & ART for CPU Scheduling with pre-emptive Priority Scheduling Algorithm.
#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

struct process {
    char name[10];
    int burst_time;
    int arrival_time;
    int priority;
    int remaining_burst_time;
    int waiting_time;
    int turnaround_time;
    int response_time;
};

int find_highest_priority(struct process p[], int n, int current_time) {
    int highest_priority = INT_MAX;
    int highest_priority_idx = -1;

    for (int i = 0; i < n; i++) {
        if (p[i].arrival_time <= current_time && p[i].remaining_burst_time > 0 && p[i].priority < highest_priority) {
            highest_priority = p[i].priority;
            highest_priority_idx = i;
        }
    }
    return highest_priority_idx;
}

void calculate_times(struct process p[], int n) {
    int current_time = 0;
    int completed_processes = 0;
    bool process_executed[n];

    for (int i = 0; i < n; i++) {
        p[i].remaining_burst_time = p[i].burst_time;
        process_executed[i] = false;
    }

    while (completed_processes < n) {
        int highest_priority_idx = find_highest_priority(p, n, current_time);

        if (highest_priority_idx == -1) {
            current_time++;
            continue;
        }
        p[highest_priority_idx].remaining_burst_time--;

        if (!process_executed[highest_priority_idx]) {
            p[highest_priority_idx].response_time = current_time - p[highest_priority_idx].arrival_time;
            process_executed[highest_priority_idx] = true;
        }

        if (p[highest_priority_idx].remaining_burst_time == 0) {
            completed_processes++;
            p[highest_priority_idx].turnaround_time = current_time + 1 - p[highest_priority_idx].arrival_time;
            p[highest_priority_idx].waiting_time = p[highest_priority_idx].turnaround_time - p[highest_priority_idx].burst_time;
        }
        current_time++;
    }
}

void display_times(struct process p[], int n) {
    int i;
    float awt = 0, att = 0, art = 0;

    printf("Process\tBurst Time\tArrival Time\tPriority\tWaiting Time\tTurnaround Time\tResponse Time\n");

    for (i = 0; i < n; i++) {
        printf("%s\t%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", p[i].name, p[i].burst_time, p[i].arrival_time,
               p[i].priority, p[i].waiting_time, p[i].turnaround_time, p[i].response_time);

        awt += p[i].waiting_time;
        att += p[i].turnaround_time;
        art += p[i].response_time;
    }

    awt /= n;
    att /= n;
    art /= n;

    printf("\nAverage Waiting Time: %.2f\n", awt);
    printf("Average Turnaround Time: %.2f\n", att);
    printf("Average Response Time: %.2f\n", art);
}

int main() {
    int n, i;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    struct process p[n];

    for (i = 0; i < n; i++) {
        printf("\nEnter the details of process %d:\n", i + 1);
        printf("Name: ");
        scanf("%s", p[i].name);
        printf("Burst Time: ");
        scanf("%d", &p[i].burst_time);
        printf("Arrival Time: ");
        scanf("%d", &p[i].arrival_time);
        printf("Priority: ");
        scanf("%d", &p[i].priority);
    }

    calculate_times(p, n);
    display_times(p, n);
    return 0;
}
