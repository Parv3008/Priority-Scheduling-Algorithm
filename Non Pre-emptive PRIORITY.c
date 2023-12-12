//) Write a C/C++ program to calculate AWT, ATT & ART for CPU Scheduling with non-pre-emptive Priority Scheduling Algorithm.
#include <stdio.h>

struct process {

    char name[10];
    int burst_time;
    int arrival_time;
    int priority;
    int waiting_time;
    int turnaround_time;
    int response_time;

};

void swap(struct process *xp, struct process *yp) {

    struct process temp = *xp;
    *xp = *yp;
    *yp = temp;
}

// Function to perform selection sort based on priority

void sort_by_priority(struct process p[], int n) {

    int i, j, min_idx;

    for (i = 0; i < n - 1; i++) {
        min_idx = i;
        for (j = i + 1; j < n; j++) {
            if (p[j].priority < p[min_idx].priority)
                min_idx = j;
        }
        if (min_idx != i)
            swap(&p[i], &p[min_idx]);
    }
}

void calculate_times(struct process p[], int n) {

    int i;
    p[0].waiting_time = 0;
    p[0].response_time = 0;

    for (i = 1; i < n; i++) {
        p[i].waiting_time = p[i - 1].waiting_time + p[i - 1].burst_time;
        p[i].response_time = p[i].waiting_time - p[i].arrival_time;

        if (p[i].response_time < 0)
            p[i].response_time = 0;
    }

    for (i = 0; i < n; i++) {
        p[i].turnaround_time = p[i].burst_time + p[i].waiting_time;
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

    sort_by_priority(p, n);
    calculate_times(p, n);
    display_times(p, n);
    return 0;
}

