#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum msgtag {
	NoTag = 0, Important, Work, Personal, ToDo, Later
} msgtag;

typedef struct MsgDetails
{
	char id[100];
	msgtag tag;
	int year;
	int month;
	int day;
} MsgDetails;

typedef struct Node
{
	MsgDetails *item;
	struct Node* next;
} Node;

Node* addNode(MsgDetails *ptr, Node* head) {

	Node* newHead = malloc(sizeof(*newHead));
	MsgDetails *msgd = malloc(sizeof(*msgd)); 
	memcpy(msgd, ptr, sizeof(*msgd));

	newHead->item = msgd;
	newHead->next = head;

	return newHead;
}

void printAll(const Node* head) {
	
	const Node* current = head;

	while (current) {
		printf("%d,%d,%d,%d,%s\n", current->item->tag, current->item->year, current->item->month, current->item->day, current->item->id);
		current = current->next;
	}
}


int main() {

	Node* head = NULL;
	MsgDetails details;
	MsgDetails *ptr = &details;

	details.tag = Work;
	details.year = 2020;
	details.month = 1;
	details.day = 20;
	strcpy(details.id, "Alex");

	head = addNode(ptr, head);

	details.tag = Personal;
	details.year = 2021;
	details.month = 5;
	details.day = 5;
	strcpy(details.id, "Sveta");

	head = addNode(ptr, head);

	printAll(head);
}
