#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int content;
	struct node *next;
}tnode;



void append(tnode	*list)
{
	tnode *c = NULL;

	int value = 10;
	c = malloc(sizeof(tnode));

	c->content = value;
	c->next = NULL;

	list->next = c;
}

void iter(tnode	*list)
{
	while (list->next != NULL)
	{
		list = list->next;
	}
}

void addback(tnode	*list, int value)
{
	while (list->next != NULL)
	{
		list = list->next;
	}
	tnode *c = NULL;

	c = malloc(sizeof(tnode));

	c->content = value;
	c->next = NULL;

	list->next = c;
}

void printlist(tnode	*list)
{
	while (list->next != NULL)
	{
		list = list->next;
		printf("[%i]\n", list->content);
	}
}

void iterfree(tnode	*list)
{
	tnode *list2;

	while (list->next != NULL)
	{
		list2 = list;
		list = list->next;
	}
	list2->next = NULL;
	free(list);
}

int main()
{

	tnode	head;
	head.next = NULL;
	int arr[] = {0,1,2,3,4,5,6,7,8,9};

	int i = 0;
	while (i < 10)
	{
		addback(&head, arr[i]);
		i++;
	}
	printlist(&head);
	i = 0;
	while (i < 10)
	{
		iterfree(&head);
		i++;
	}
	return 0;
}
