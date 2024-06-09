#include <stdio.h>

int last_deadline(int *deadlines, int n_jobs){
    int lastDATE=deadlines[0];

    for(int i=1;i<n_jobs;i++)
        if(lastDATE<deadlines[i])
            lastDATE=deadlines[i];
    
    return lastDATE;
}

void profit_wise_sorted(int *jobID, int *profits, int *deadlines, int n_jobs){
    for(int i=0;i<n_jobs;i++)
        for(int j=0;j<n_jobs-1;j++)
            if(profits[j]<profits[j+1]){
                int tempProfit=profits[j], tempDeadline=deadlines[j], tempJobID=jobID[j];
                jobID[j]=jobID[j+1];profits[j]=profits[j+1]; deadlines[j]=deadlines[j+1];
                jobID[j+1]=tempJobID; profits[j+1]=tempProfit; deadlines[j+1]=tempDeadline;
            }
            else if (profits[j]==profits[j+1] && deadlines[j]>deadlines[j+1])
            {
                int tempProfit=profits[j], tempDeadline=deadlines[j], tempJobID=jobID[j];
                jobID[j]=jobID[j+1]; profits[j]=profits[j+1]; deadlines[j]=deadlines[j+1];
                jobID[j+1]=tempJobID; profits[j+1]=tempProfit; deadlines[j+1]=tempDeadline;
            }
            
}

void job_sequence(int *jobID, int *profits, int *deadlines, int n_jobs, int *result) {
    // Sort the jobs by their profit
    profit_wise_sorted(jobID, profits, deadlines, n_jobs);
    // Get the last deadline to know the maximum number of jobs we can schedule
    int numJobs = last_deadline(deadlines, n_jobs);
    // result[] : Array to store the result (sequence of jobs) and to keep track of free time slots
    for (int i = 0; i < numJobs; i++) {
        result[i] = -1; // initialize all slots as free
    }

    // Iterate through all given jobs
    for (int i = 0; i < n_jobs; i++) {
        // Finding a free slot for this job starting from the last possible slot
        for (int j = deadlines[i] - 1; j >= 0; j--) {
            if (j < numJobs && result[j] == -1) {
                result[j] = jobID[i]; // Assign this job to slot
                break;
            }
        }
    }
}

int main(){
    int n_jobs;
    printf("Enter the number of jobs: ");
    scanf("%d", &n_jobs);

    int *jobID= (int *)malloc(n_jobs * sizeof(int));
    int *profits= (int *)malloc(n_jobs * sizeof(int));
    int *deadlines= (int *)malloc(n_jobs * sizeof(int));
    printf("Enter the job profits and deadlines...\n");
    for(int i=0;i<n_jobs;i++){
        jobID[i]=i;
        printf("Job %d profit: ",i+1);
        scanf("%d",&profits[i]);
        printf("Job %d deadline: ",i+1);
        scanf("%d",&deadlines[i]);
    }

    int numJobs=last_deadline(deadlines, n_jobs) , tProfit=0;
    int *jobSeq = (int *)malloc(numJobs * sizeof(int));

    job_sequence(jobID, profits, deadlines, n_jobs, jobSeq);

    printf("The job sequence: ");
    for (int i = 0; i < numJobs; i++)
        if (jobSeq[i] != -1) 
            printf("Job %d ", jobSeq[i]+1,tProfit+=profits[i]);
    printf("\nThe maximum possible profit : %d",tProfit);
    // Free allocated memory
    free(jobID);
    free(profits);
    free(deadlines);
    free(jobSeq);

    return 0;

}



// int job_sequence(int *jobID, int *profits, int *deadlines, int n_jobs){
//     //starting off with getting the jobs sorted by their profit
//     profit_wise_sorted(jobID, profits,deadlines,n_jobs);
//     //getting the last deadline, calculates the max possibly do-able number of jobs
//     int numJobs=last_deadline(deadlines, n_jobs);
//     //int *jobs= (int)malloc(numJobs * sizeof(int));
//     int *jobs[numJobs]={0};
    
//     for(int i=0;i<n_jobs;i++)
//         for(int j=0;j<numJobs;j++)
//             if(jobs[j]==0 && deadline[i]<=j){
//                 jobs[j]=jobID[i];
//                 continue;
//             }
//             else if (jobs[j]!=0 && profits[i]>profits[slot[j]])
//             {
//                 jobs[j]=jobID[i];
//                 continue;
//             }
            

//     return jobs;
// }
