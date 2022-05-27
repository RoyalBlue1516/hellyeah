#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct {
	element data;
	struct node* link;
}node;

void error(char* message)
{
	fprintf(stderr, "%S \n", message);
}

node* insert_first(node* head, int value)
{
	node* p = (node*)malloc(sizeof(node));
	p->data = value;
	p->link = head;
	head = p;
	return head;
}

node* insert(node* head,node* pre, element value)
{
	node* p = (node*)malloc(sizeof(node));
	p->data = value;
	p->link = pre->link;
	pre->link = p;
	return head;
}

node* delete_first(node* head)
{
	node* removed;
	if (head == NULL) return NULL;
	removed = head;
	head = removed->link;
	free(removed);
	return head;
}

node* delete(node* head, node* pre)
{
	node* removed;
	removed = pre->link;
	pre->link = removed->link;
	free(removed);
	return head;
}

void print_list(node* head)
{
		printf("NULL \n");
}
int main(void)
{
	node* head = NULL;

	for (int i = 0; i < 5; i++)
	{
		head = insert_first(head, i);
	for (node* p = head; p != NULL; p = p->link)
		printf("%d -> ", p->data);
		print_list(head);
	}
	for (int i = 0; i < 5; i++)
	{
		head = delete_first(head);
		print_list(head);
	}
	return 0;
}

