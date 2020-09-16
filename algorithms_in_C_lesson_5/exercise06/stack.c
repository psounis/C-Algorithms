/* stoiva.c: Kwdikas tis vivliothikis stoiva */
#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

/* LL_init(): arxikopoiei tin lista */
void SLL_init(SLIST_PTR *head)
{
	*head=NULL;
}

/* LL_empty(): epistrefei TRUE/FALSE
 *          analoga me to an i lista einai adeia */
int SLL_empty(SLIST_PTR head)
{
	return head == NULL;
}

/* LL_data(): epistrefei ta dedomena tou komvou
			  pou deixnei o deiktis p */
selem SLL_data(SLIST_PTR p)
{
	return p->data;
}

/* LL_insert_start(): Eisagei to stoixeio x
			stin arxi tis listas */
int SLL_insert_start(SLIST_PTR *head, selem x)
{
	SLIST_PTR newnode;

	newnode=(SLIST_NODE *)malloc(sizeof(SLIST_NODE));
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
int SLL_insert_after(SLIST_PTR p, selem x)
{
	SLIST_PTR newnode;

	newnode=(SLIST_NODE *)malloc(sizeof(SLIST_NODE));
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
int SLL_delete_start(SLIST_PTR *head, selem *x)
{
	SLIST_PTR current;

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
int SLL_delete_after(SLIST_PTR prev, selem *x)
{
	SLIST_PTR current;

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

void SLL_print(SLIST_PTR head)
{
	SLIST_PTR current;

	current=head;
	while(current!=NULL)
	{
		printf("%d ",current->data);
		current=current->next;
	}
}

/* LL_destroy(): Apodesmeyei to xwro poy exei
				desmeusei i lista	 */

void SLL_destroy(SLIST_PTR *head)
{
	SLIST_PTR ptr;

	while (*head!=NULL)
	{
		ptr=*head;
		*head=(*head)->next;
		free(ptr);
	}
}

void ST_init(STACK *s)
{
	SLL_init(s);
}

int ST_empty(STACK s)
{
	return SLL_empty(s);
}

void ST_push(STACK *s, selem x)
{
	SLL_insert_start(s,x);
}

int ST_pop(STACK *s, selem *x)
{
	return SLL_delete_start(s, x);
}

void ST_print(STACK s)
{
	SLL_print(s);
}

void ST_destroy(STACK *s)
{
	SLL_destroy(s);
}
