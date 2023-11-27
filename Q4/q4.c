#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <time.h>
#include <string.h>

#define BUF_SIZE 512

char ex_1[BUF_SIZE] = "How many times do I have to say?";
char ex_2[BUF_SIZE] = "Would you mind sending me the program draft you mentioned?";
char ex_3[BUF_SIZE] = "I'm afraid we need to delay our meeting.";

int main(){
	time_t start_time, end_time;
	char a[20];
	char buffer[BUF_SIZE];
	char buf_1[BUF_SIZE];
	char buf_2[BUF_SIZE];
	char buf_3[BUF_SIZE];
	
	int wrong_count=0;
	int n;
	int filedes;
	int fd;
	int sum=0;
	double total=0;
	
	printf("\n   [ a typing practice program ] \n");
	printf("      start -> (Enter) \n");
	fgets(a, sizeof(a), stdin);
	start_time = time(NULL);
	
	fprintf(stderr, "\n%s\n", ex_1);
	fgets(buf_1, sizeof(buf_1), stdin);
	
	fprintf(stderr, "\n%s\n", ex_2);
	fgets(buf_2, sizeof(buf_2), stdin);
	
	fprintf(stderr, "\n%s\n", ex_3);
	fgets(buf_3, sizeof(buf_3), stdin);
	end_time=time(NULL);
	
	total = difftime(end_time, start_time);
	
	sum = strlen(buf_1) + strlen(buf_2) + strlen(buf_3);
	sum /= total/60;
	
	for(int i=0; i<strlen(ex_1); i++){
		if(buf_1[i] != ex_1[i]){
			wrong_count++;
		}
	}
	for(int i=0; i<strlen(ex_2); i++){
		if(buf_1[i] != ex_2[i]){
			wrong_count++;
		}
	}
	for(int i=0; i<strlen(ex_3); i++){
		if(buf_1[i] != ex_3[i]){
			wrong_count++;
		}
	}
	
	printf("wrong count: %d\n", wrong_count);
	printf("typing sum: %d\n", sum);
	printf("total time: %f\n", total);
	
	exit(0);

}
