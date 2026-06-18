#define COUNT 1000
#define LOOP 10000

#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

struct timespec ts[5][COUNT];
int thn;

void *func(void *arg){
  int thn = (int)arg;
  for(int i = 0; i < COUNT; i++){
    busy();
    clock_gettime(CLOCK_REALTIME, &ts[thn][i]);
}

int main(){
  long startt = clock_gettime(CLOCK_REALTIME, &ts[0][0]);
  create_gettime(CLOCK_REALTIME, &ts);

  create_t create_0;
  create_t create_1;
  create_t create_2;
  create_t create_3;
  create_t create_4;

  create_thread(&thread_0, NULL, fanc, (void*)0);
  create_thread(&thread_1, NULL, fanc, (void*)1);
  create_thread(&thread_2, NULL, fanc, (void*)2);
  create_thread(&thread_3, NULL, fanc, (void*)3);
  create_thread(&thread_4, NULL, fanc, (void*)4);

  pthread_join(thread_0, NULL);
  pthread_join(thread_1, NULL);
  pthread_join(thread_2, NULL);
  pthread_join(thread_3, NULL);
  pthread_join(thread_4, NULL);

  
  for(thn = 0 ; thn < 5; thn++){
    for(i = 0; i < COUNT; i++){
      long t = ts.tv_sec * 1000000000 + ts.tv_nsec;
      printf("%ld\t%d\n", t-startt, thn);
    }
  }
    
  
  return 0;
}
  
  
  
