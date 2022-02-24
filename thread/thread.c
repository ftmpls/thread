#include<stdio.h>
#include<string.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>
pthread_t tid[3];

void* func(void* arg)
{
    double i = 0;
    pthread_t id = pthread_self();
    if (pthread_equal(id, tid[0]))
    {

        printf("\n First thread processing\n");
        double sum = 0;
        int count = 0;
        FILE* f = fopen("input1.txt", "r");

        float num;
        while (fscanf(f, " %f", &num) == 1) {
            sum = sum + num;
            printf("Thread%d reads %d. The value is %.6f. The sum is : %.6f\n",
                1, count, num, sum);
        }

        fclose(f);

    }
    else if (pthread_equal(id, tid[1]))
    {
        printf("\n Second thread processing\n");
        double sum = 0;
        int count = 0;
        FILE* f = fopen("input2.txt", "r");

        float num;
        while (fscanf(f, " %f", &num) == 1) {
            sum = sum + num;
            printf("Thread%d reads %d. The value is %.6f. The sum is : %.6f\n",
                2, count, num, sum);
        }

        fclose(f);
    }
    else if(pthread_equal(id, tid[2])){
        printf("\n Thirth thread processing\n");
        double sum = 0;
        int count = 0;
        FILE* f = fopen("input3.txt", "r");

        float num;
        while (fscanf(f, " %f", &num) == 1) {
            sum = sum + num;
            printf("Thread%d reads %d. The value is %.6f. The sum is : %.6f\n",
                3, count, num, sum);
        }

        fclose(f);
    }

    //for (i = 0; i < (0xFFFFFFFF); i++);

    //return NULL;
}

int main(void)
{
    int i = 0;
    int err;

    while (i < 3)
    {
        err = pthread_create(&(tid[i]), NULL, &func, NULL);
        if (err != 0)
            printf("\ncan't create thread :[%s]", strerror(err));
        else
            printf("\n Thread created successfully\n");

        i++;
    }


    return 0;
}