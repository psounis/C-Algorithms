/* queue.h : Dilwseis ouras */

#define TRUE 1
#define FALSE 0

typedef int qelem;         /* typos dedomenwn listas */

struct qnode{			   /* Typos komvou listas */
   qelem data; 			   /* dedomena */
   struct qnode *next;      /* epomenos */
};

typedef struct qnode QLIST_NODE; /* Sinwnimo tou komvou listas */
typedef struct qnode *QLIST_PTR; /* Sinwnimo tou deikti komvou */

struct queue{
	QLIST_PTR first;
	QLIST_PTR last;
};

typedef struct queue QUEUE;

void QLL_init(QLIST_PTR *head);
int QLL_empty(QLIST_PTR head);
qelem QLL_data(QLIST_PTR p);
int QLL_insert_start(QLIST_PTR *head, qelem x);
int QLL_insert_after(QLIST_PTR p, qelem x);
int QLL_delete_start(QLIST_PTR *head, qelem *x);
int QLL_delete_after(QLIST_PTR prev, qelem *x);
void QLL_print(QLIST_PTR head);
void QLL_destroy(QLIST_PTR *head);

void QU_init(QUEUE *q);
int QU_empty(QUEUE q);
void QU_enqueue(QUEUE *q, qelem x);
int QU_dequeue(QUEUE *q, qelem *x);
void QU_print(QUEUE q);
void QU_destroy(QUEUE *q);

