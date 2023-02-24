
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Node.h"
#include "Queue.h"

/*
int main(int argc, char **argv) {
  NodePtr headPtr = NULL;
  NodePtr tailPtr = NULL;
  // For struct Queue
    Queue  q;
     q. headPtr=NULL;
     q.tailPtr=NULL;
     q.size=0;
  
  
  int i, x;

  for (i = 1; i < argc; i++) {
    if (strcmp(argv[i], "x") == 0) {
      x = dequeue_struct(&q);
      printf("dequeing %d\n", x);
    } else {
      enqueue_struct(&q, atoi(argv[i]));
    }
  }
  return 0;
}
*/

int main(int argc, char **argv){
  Queue q;
  q.headPtr = NULL;
  q.tailPtr = NULL;
  q.size = 0;

  int cnt=0;
  for(int i=1; i<argc; i++){
    if(strcmp(argv[i], "x")==0){
      int change = dequeue_struct(&q);
      if(change == 0) printf("Thank you\n");
      else printf("Change is %d\n",change);
    }
    else cnt++;

    if(cnt == 2){
      enqueue_struct(&q, atoi(argv[i-1]), atoi(argv[i]));
      cnt = 0;
    }
  }
  if(q.size!=0){
    if(q.size == 1) printf("There is %d people left in queue\n",q.size);
    else printf("There are %d people left in queue\n",q.size);
  }
  dequeue_All(&q);
}