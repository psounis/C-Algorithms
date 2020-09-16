/* queue.c: Kwdikas tis vivliothikis queue */
#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

/* LL_init(): arxikopoiei tin lista */
void QLL_init(QLIST_PTR *head)
{
	*head=NULL;
}

/* LL_empty(): epistrefei TRUE/FALSE
 *          analoga me to an i lista einai adeia */
int QLL_empty(QLIST_PTR head)
{
	return head == NULL;
}

/* LL_data(): epistrefei ta dedomena tou komvou
			  pou deixnei o deiktis p */
qelem QLL_data(QLIST_PTR p)
{
	return p->data;
}

/* LL_insert_start(): Eisagei to stoixeio x
			stin arxi tis listas */
int QLL_insert_start(QLIST_PTR *head, qelem x)
{
	QLIST_PTR newnode;

	newnode=(QLIST_NODE *)malloc(sizeof(QLIST_NODE));
	if (!newnode)
	{
		printf("Adynamia desmeusis mnimis");
		return FALSE;
	}
	newnode->data=x;

	newnode->next=*head;
	*head=newnode;
	return TRUE;
}

/* LL_insert_after(): Eisagei to stoixeio x
			meta to stoixeio pou deixnei o p */
int QLL_insert_after(QLIST_PTR p, qelem x)
{
	QLIST_PTR newnode;

	newnode=(QLIST_NODE *)malloc(sizeof(QLIST_NODE));
	if (!newnode)
	{
		printf("Adynamia desmeusis mnimis");
		return FALSE;
	}
	newnode->data=x;

	newnode->next=p->next;
	p->next=newnode;
	return TRUE;
}

/* LL_delete_start(): Diagrafei ton komvo poy deixnei
	i kefali tis listas */
int QLL_delete_start(QLIST_PTR *head, qelem *x)
{
	QLIST_PTR current;

	if (*head==NULL)
		return FALSE;

	current=*head;
	*x=current->data;

	(*head)=(*head)->next;
	free(current);
	return TRUE;
}

/* LL_delete_after(): Diagrafei ton epomeno tou
				komvou poy deixnei o prev */
int QLL_delete_after(QLIST_PTR prev, qelem *x)
{
	QLIST_PTR current;

	if (prev->next==NULL)
		return FALSE;

	current=prev->next;
	*x=current->data;

	prev->next=current->next;
	free(current);
	return TRUE;
}

/* LL_print(): Typwnei ta periexomena mias
				syndedemenis listas	 */

void QLL_print(QLIST_PTR head)
{
	QLIST_PTR current;

	current=head;
	while(current!=NULL)
	{
		printf("%d ",current->data);
		current=current->next;
	}
}

/* LL_destroy(): Apodesmeyei to xwro poy exei
				desmeusei i lista	 */

void QLL_destroy(QLIST_PTR *head)
{
	QLIST_PTR ptr;

	while (*head!=NULL)
	{
		ptr=*head;
		*head=(*head)->next;
		free(ptr);
	}
}

void QU_init(QUEUE *q)
{
	q->first = NULL;
	q->last = NULL;
}

int QU_empty(QUEUE q)
{
	return QLL_empty(q.first);
}

void QU_enqueue(QUEUE *q, qelem x)
{
	if (QLL_empty(q->first))
	{
		QLL_insert_start(&(q->first),x);
		q->last = q->first;
	}
	else
	{
		QLL_insert_after(q->last, x);
		q->last = q->last->next;

	}
}


int QU_dequeue(QUEUE *q, qelem *x)
{
	if (QU_empty(*q))
	{
		printf("No pop. Queue is empty!");
		return FALSE;
	}
	else
	{
		QLL_delete_start(&(q->first), x);
		if(QU_empty(*q))
			q->last=NULL;
		return TRUE;
	}
}

void QU_print(QUEUE q)
{
	QLL_print(q.first);
}

void QU_destroy(QUEUE *q)
{
	QLL_destroy(&(q->first));
}
