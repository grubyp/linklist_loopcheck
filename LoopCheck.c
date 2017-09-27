#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

typedef struct Node
{
	struct Node *next;
}node;

int loopCheck(node *);
void createLinkedList(node *);

int main()
{
	node *head=(node *)malloc(sizeof(node));
	createLinkedList(head);
	
	if(loopCheck(head))
	{
		printf("存在循环");
	}
	else
	{
		printf("不存在循环");
	}

	getch();
	return 0;
}

void createLinkedList(node *head)
{
	node *n=(node *)malloc(sizeof(node));
	node *current=n;
	node *walk;
	head->next=n;
	int i=2,j,x;
	int num=8;
	while(num--)
	{
		printf("节点%d连接新节点（0）或旧节点？\n",i);
		scanf("%d",&x);
		if(x==0)
		{
			node *nn=(node *)malloc(sizeof(node));
			nn->next=NULL;
			current->next=nn;
			current=current->next;
			i++;
		}
		else if(x>0&&x<i)
		{
			walk=head;
			for(j=1;j<x;j++){
				walk=walk->next;
			}
			current->next=walk;
			break;
		}
	}
}

int loopCheck(node *head)
{
	node *p1,*p2;
	p1=head;
	p2=head->next->next;
	if(p1==p2)
	{
		return 1;
	}
	while(1)
	{
		p1=p1->next;
		p2=p2->next;
		if(p1==NULL||p2==NULL) return 0;
		p2=p2->next;
		if(p1==NULL||p2==NULL) return 0;
		if(p1==p2) return 1;
	}
}
