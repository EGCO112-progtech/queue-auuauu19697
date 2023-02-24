

typedef struct {
  NodePtr headPtr, tailPtr;
  int size;
} Queue;

void enqueue_struct(Queue *q, int order, int qty) {
  Node *new_node = (Node *)malloc(sizeof(Node));
  if (new_node) {
    /*Finish enqueue */
    new_node->order_number = order;
    new_node->qty = qty;
    new_node->nextPtr = NULL;
    
    if(q->headPtr == NULL) q->headPtr = new_node;
    else q->tailPtr->nextPtr = new_node;
    q->tailPtr = new_node;
    q->size++;
  }
}

int dequeue_struct(Queue *q) {
  NodePtr t = q->headPtr;
  if (t) {
    int order = t->order_number;
    int qty = t->qty;
    int price,cash = 0;
    if(q->size > 0){
      switch(order){
      case 1:
        printf("Ramen\n");
        price = qty*80;
        break;
      case 2:
        printf("Somtum\n");
        price = qty*60;
        break;
      case 3:
        printf("MOMO\n");
        price = qty*600;
        break;
      default:
        printf("NO FOOD\n");
        price = 0;
        break;
      }
      
    }

    q->headPtr = t->nextPtr;
    if(q->headPtr == NULL) q->tailPtr = NULL;
    q->size--;
    /*Finish dequeue */
    
    printf("You have to pay %d\n",price);
    while(cash < price){
      printf("Cash: ");
      scanf("%d",&cash);
    }
    
    free(t);
    return cash - price;
  }
  printf("Empty queue ");
  return 0;
}

void dequeue_All(Queue *q){
  printf("dequeue all...\n");
  while(q->size != 0){
    NodePtr t = q->headPtr;
    if(t){
      q->headPtr = t->nextPtr;
      if(q->headPtr == NULL) q->tailPtr = NULL;
      q->size--;
    }
  }
  if(q->size == 0) printf("All dequeued\n");
}
