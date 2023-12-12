# Priority-Scheduling-Algorithm

Algorithm for non-pre-emptive Priority Scheduling.
1.	Initialize the current_time to 0 and completed_processes to 0.
2.	Create a boolean array process_executed[] to keep track of whether a process has been executed or not.
3.	For each process i, initialize its remaining_burst_time to burst_time, and process_executed[i] to false.
4.	While there are incomplete processes (completed_processes < n), do the following:
a. Find the process with the highest priority that has arrived (arrival_time <= current_time) and has not been executed yet (process_executed[i] == false).
b. If no such process is found, increment the current_time and continue to the next iteration.
c. Execute the selected process until its completion (remaining_burst_time becomes 0).
d. Mark the process as executed (process_executed[i] = true).
e. Calculate its turnaround_time as current_time - arrival_time.
f. Calculate its waiting_time as turnaround_time - burst_time.
g. Increment completed_processes.
5.	Calculate the average waiting_time (awt) and average turnaround_time (att) for all processes.
6.	Display the details of each process, including its burst_time, arrival_time, priority, waiting_time, and turnaround_time.
7.	Display the average waiting_time (awt) and average turnaround_time (att) for all processes.



Algorithm for pre-emptive Priority Scheduling 
1.	Initialize the current_time to 0 and completed_processes to 0.
2.	Create a boolean array process_executed[] to keep track of whether a process has been executed or not.
3.	For each process i, initialize its remaining_burst_time to burst_time, and process_executed[i] to false.
4.	While there are incomplete processes (completed_processes < n), do the following:
a.	Find the process with the highest priority that has arrived (arrival_time <= current_time) and still has some remaining burst time (remaining_burst_time > 0).
b.	If no such process is found, increment the current_time and continue to the next iteration.
c.	Execute the process for one unit of time (decrement its remaining_burst_time).
d.	If the process has not been executed yet, set its response_time to the current_time - arrival_time, and mark it as executed (process_executed[i] = true).
e.	If the process's remaining_burst_time becomes 0, it has completed its execution:
f.	Increment the current_time.
5.	Calculate the average waiting_time (awt), average turnaround_time (att), and average response_time (art) for all processes.
6.	Display the details of each process, including its burst_time, arrival_time, priority, waiting_time, turnaround_time, and response_time.
7.	Display the average waiting_time (awt), average turnaround_time (att), and average response_time (art) for all processes.

