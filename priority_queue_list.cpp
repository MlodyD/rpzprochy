#include <stdio.h>
#include <stdlib.h>
#include "priority_queue_list.h" /*
typedef struct pqueue pqueue;
struct pqueue {
	int k;
	void *data;
	pqueue *next;
	pqueue *prev;
};*/

void qlist(pqueue* head, void (*print_data)(void*))
{
	pqueue* p;

	for (p = head; p != NULL; p = p->next)
	{
		printf("%d: ", p->k);
		print_data(p->data);
		printf("\n");
	}
}

void qinsert(pqueue** phead, void* data, int k)
{
	
	if ((*phead) == NULL) // pusta kolejka
	{
		pqueue* wsk = (pqueue*)malloc(sizeof(pqueue));
		wsk->data = data;
		wsk->prev = NULL;
		wsk->next = NULL;
	}
	else if ((*phead)->next == NULL) // nastepny element to null
	{
		pqueue* wsk = (pqueue*)malloc(sizeof(pqueue));
		wsk->data = data;
		(*phead)->next = wsk;
		wsk->next = NULL;
	}
	else if ((*phead)->k < k)
	{ // nie pusta kolejka ale nie jest to ostatni element
		pqueue* wsk = (pqueue*)malloc(sizeof(pqueue));
		wsk->data = data;
		wsk->next = (*phead)->next;
		wsk->prev = (*phead);
		(*phead)->next = wsk;
	}
	else {
		qinsert((*phead)->next, data, k);
	}
		
}

void qremove(pqueue** phead, int k)
{
	if (k == (*phead)->k) // znalezlismy co szukalismy
	{
		if ((*phead)->next != NULL)
		{										   // istnieje nastepny element
			(*phead)->next->prev = (*phead)->prev; // nastepnemu dajemy ze poprzedni jest poprzednim usuwanego
		}
		if ((*phead)->prev != NULL) // istnieje wczesniejszy element
		{
			(*phead)->prev->next = (*phead)->next; // poprzedniemu zapisujemy ze nastepny jest nastepnym
		}
		free(phead);
	}
	else {
		qremove(pqueue * *phead, int k)
	}
}
