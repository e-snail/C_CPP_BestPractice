#include <stdlib.h>
#include <stdio.h>
#include <iostream.h>

using namespace std;

//Binary tree structure
typedef BiTree {
	int data;
	BiTree *ltree;
	BiTree *rtree;
}BiTree;

//Binary Tree deepth
int BinaryTreeDeepth(BTLink *link)
{
	int deepthL = 0, deepthR = 0;
	if (link == NULL)
		return 0;
	else{
		if (link->ltree)
			deepthL = 1 + BinaryTreeDeepth(link->ltree);
		if (link->rtree)
			deepthR = 1 + BinaryTreeDeepth(link->rtree);
		
		return (deepthL > deepthR ? deepthL:deepthR);
	}
}

//Single linkage structure
typedef SingleLinckage {
	int data;
	SingleLinckage *next;
}SingleLinckage;

//Single linkage reverse
//单链表逆置 非递归
void LinkageReverse(SingleLinckage *&link)
{
	if (link == NULL || link->next == NULL)
		return; 
	SingleLinckage *p, *q, *r;
	p = link;
	q = link->next;
	while (q) {
		r = q->next;
		q->next = p;
		p = q;
		q = r;
	}
	link->next = NULL;
	link = p;
}

//Single linkage reverse
//单链表逆置 递归
SingleLinckage *LinkageReverse(SingleLinckage *old, SingleLinckage *newlink=NULL)
{
	if (old == NULL)
		return NULL;
	SingleLinckage *next = old->next;; 
	old->next = newlink;
	newlink = old;
	
	return (next == NULL) ? newlinke:LinkageReverse(next, newlink);
}

int main(int argc, char **argv)
{
	return 0;
}
