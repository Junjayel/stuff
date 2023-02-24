// CPU Scheduling Algorithm: Optimal Round Robin (ORR)

// Determining Time Quantum using Manhattan distance -> Difference between the highest burst 
// time and the lowest burst time. 

// Author: Ong Jun Leng 2103283
#include <stdio.h>
#include <limits.h>

int main() {
    int i = 0, j = 0, numProcesses = 0, timeSlice = 0, maxBurstTime = 0, temp = 0;
    int burstTime[10], backupBurstTime[10], waitTime[10], turnAroundTime[10],
      responseTime[10];

    float avgWaitTime = 0.0, avgTurnAroundTime = 0.0, avgResponseTime = 0.0;

    int max_burst = 0, min_burst = INT_MAX;

    printf("\t CPU Scheduling Method: Round Robin \n");
    printf("\n\t Enter the no of processes: ");
    scanf("%d", & numProcesses);

    for (i = 0; i < numProcesses; i++) {
      printf("\n\t Enter Burst Time for process %d: ", i + 1);
      scanf("%d", &burstTime[i]);
      backupBurstTime[i] = burstTime[i];

      // get the highest and lowest burst times among all processes
      if (burstTime[i] > max_burst) max_burst = burstTime[i];
      if (burstTime[i] < min_burst) min_burst = burstTime[i];
    }

    // set the timeslice to be used
    timeSlice = max_burst - min_burst;

    // RR process
    maxBurstTime = burstTime[0];
    for (i = 1; i < numProcesses; i++) {
      if (maxBurstTime < burstTime[i])
        maxBurstTime = burstTime[i];
    }
    for (j = 0; j < (maxBurstTime / timeSlice) + 1; j++) {
      for (i = 0; i < numProcesses; i++) {
        if (burstTime[i] != 0) {
            if (burstTime[i] == backupBurstTime[i])
                responseTime[i] = temp;
          if (burstTime[i] <= timeSlice) {
              for (int l = 0; l < numProcesses; l++){
                if (l != i && burstTime[l] != 0)
                    waitTime[l] += burstTime[i];
                }
            turnAroundTime[i] = temp + burstTime[i];
            temp = temp + burstTime[i];
            burstTime[i] = 0;
          } else {
              for (int l = 0; l < numProcesses; l++){
                if (l != i && burstTime[l] != 0)
                    waitTime[l] += timeSlice;
            }
            burstTime[i] = burstTime[i] - timeSlice;
            temp = temp + timeSlice;
          }
        }
      }
    }
    /*Calculate the ‘waiting time’, ‘turn-around-time’ and
    'response time' for each process. */
    
      printf("\n\t PROCESS\t BURST TIME\t WAITING TIME\t TURNAROUND TIME\t RESPONSE TIME\n");
    for (i = 0; i < numProcesses; i++)
      printf("\t P%d \t\t %d \t\t %d\t\t\t %d \t\t\t\t %d \n",
        i + 1, backupBurstTime[i], waitTime[i], turnAroundTime[i], responseTime[i]);
        
    /*Calculate and print the ‘average waiting time’,
    ‘average turn-around-time’, and 'average response time' */
    
    for (int i=0; i<numProcesses; i++){
        avgWaitTime += waitTime[i];
        avgTurnAroundTime += turnAroundTime[i];
        avgResponseTime += responseTime[i];
    }
    printf("\n\t The Average Waiting time: %.2f\n", avgWaitTime / numProcesses);
    printf("\n\t The Average Turnaround time: %.2f\n", avgTurnAroundTime / numProcesses);
    printf("\n\t The Average Response time: %.2f\n", avgResponseTime / numProcesses);
    
    return 0;
}