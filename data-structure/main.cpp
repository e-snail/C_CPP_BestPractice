#include <stdlib.h>
#include <stdio.h>
#include <iostream.h>

using namespace std;

/******************************************************
 * 二叉树算法 http://lijinshui.bokee.com/6649878.html
******************************************************/
//Binary tree structure
typedef BiTree {
	int data;
	BiTree *ltree;
	BiTree *rtree;
}BiTree;

//Binary Tree deepth
//二叉树深度 递归算法
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

//判断某二叉树是否为平衡二叉树
bool isBalance(BTLink *link)
{
	if (!link)
		return true;
	int ret = BinaryTreeDeepth(link->ltree) - BinaryTreeDeepth(link->rtree);
	if ((ret > 1) || (ret < -1))
		return false;
	else return isBalance(link->ltree) && isBalance(link->rtree);
}

/******************************************************
 * 单向链表的倒置
******************************************************/
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
