
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

int MAX = 14;
int thr1V = 0;
int thr2V = 0;
int count = 1;
int thr1C = 1;
int thr2C = 2;
pthread_mutex_t thr;
pthread_cond_t cond;

//Even numbers so from 2 to 14 but in two's
void *even(void *arg){
 	while(count < MAX) { // to make sure we don't pass 14
 		pthread_mutex_lock(&thr);
 		while(count % 2 != 0) 
 			pthread_cond_wait(&cond, &thr);
		if (count != MAX)
			printf("%d -> ", thr2V + thr2C);
		else
			printf("%d\n ", thr2V + thr2C);
		thr2V = thr2V + thr2C;
		count++;
		pthread_mutex_unlock(&thr);
		pthread_cond_signal(&cond);
	}
	pthread_exit(0);
}

//Prints all values from 1 to 14 a
void *all(void *arg){
	while(count < MAX) {
		pthread_mutex_lock(&thr);
		while(count % 2 != 1)
			pthread_cond_wait(&cond, &thr);
		printf("%d -> ", thr1C + thr1V);
		thr1V = thr1V + thr1C;
		count++;
		pthread_mutex_unlock(&thr);
		pthread_cond_signal(&cond);
	}
	pthread_exit(0);
}

//Main Function
int main(){
	pthread_t thread1;
	pthread_t thread2;
	pthread_mutex_init(&thr, 0);
	pthread_cond_init(&cond, 0);
	pthread_create(&thread1, 0, &even, NULL);
	pthread_create(&thread2, 0, &all, NULL);
	pthread_join(thread1, 0);
	pthread_join(thread2, 0);
	pthread_mutex_destroy(&thr);
	pthread_cond_destroy(&cond);
	return 0;
}
