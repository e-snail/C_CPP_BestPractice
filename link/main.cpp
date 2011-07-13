#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

typedef struct node1 {
	int d;
	struct node1 *next;
};

typedef struct node1 sNode;

sNode* constructSNodes(int i)
{
	sNode *head = (sNode*)malloc(sizeof(sNode));
	head->d = 11;
	head->next = NULL;

	sNode *tmpNode = head;

	while (i > 0)
	{
		//sNode *s = new sNode;
		sNode *s= (sNode*)malloc(sizeof(sNode));
		s->d = i;
		s->next = NULL;
		if (tmpNode)
			tmpNode->next = s;
		tmpNode = s;
		i--;
	}

	return head;
}

sNode* reverseSNodes(sNode* head)
{
	//非递归方式
	/*
	sNode *p, *q, *r;
	p = head;	
	q = head->next;
	r = q->next;

	p->next = NULL;

	while (q->next)
	{
		q->next = p;
		p = q;
		q = r;
		r = r->next;
	}
	q->next = p;

	return q;
	*/

	//递归方式
	/*
	if((!head)||(!head->next)){   
		return head;     
	}                                          //recursion exit
	sNode *h = reverseSNodes(head->next);
	head->next->next=head;                  //inverse

	return h;
	*/
	if (!head->next)
		return head;
}

//我认为比较可靠的方法
//也方便阅读
sNode *head = NULL;
void reverseNodesList(sNode *root)
{
	sNode *pre, *cur, *next;
	pre = (sNode*)0;
	cur = root;
	next = cur->next;

	while (next) {
		cur->next = pre;
		pre= cur;
		cur = next;
		next = cur->next;
	}
	cur->next = pre;
	head = cur;
}

int main( int argc, char **argv)
{

	sNode *head = constructSNodes(10);

	head = reverseSNodes(head);

	do{
		cout <<head->d <<" ";
		head = head->next;
	}while(head);

	cout <<endl;

	return 0;
}
