/* stack.h : Dilwseis stoivas */

#define TRUE 1
#define FALSE 0

typedef int selem;   /* typos dedomenwn listas */

struct snode{			    /* Typos komvou listas */
   selem data; 			    /* dedomena */
   struct snode *next;      /* epomenos */
};

typedef struct snode SLIST_NODE; /* Sinwnimo tou komvou listas */
typedef struct snode *SLIST_PTR; /* Sinwnimo tou deikti komvou */

typedef SLIST_PTR STACK;

void SLL_init(SLIST_PTR *head);
int SLL_empty(SLIST_PTR head);
selem SLL_data(SLIST_PTR p);
int SLL_insert_start(SLIST_PTR *head, selem x);
int SLL_insert_after(SLIST_PTR p, selem x);
int SLL_delete_start(SLIST_PTR *head, selem *x);
int SLL_delete_after(SLIST_PTR prev, selem *x);
void SLL_print(SLIST_PTR head);
void SLL_destroy(SLIST_PTR *head);

void ST_init(STACK *s);
int ST_empty(STACK s);
void ST_push(STACK *s, selem x);
int ST_pop(STACK *s, selem *x);
void ST_print(STACK s);
void ST_destroy(STACK *s);

