#pragma once
#include"QueueNode.h"


class MinPriorityQueue
{
private :

	QueueNode* root;
public:

	MinPriorityQueue(void);
	QueueNode* Get_root(){ return root; };
	void Insert( QueueNode* pNew );
	void Set_root(){ root = NULL; }
	QueueNode* Meld( QueueNode* a, QueueNode* b );
	void clear( QueueNode* p );
	QueueNode* Pop();// root를 가져오는 함수 
	QueueNode* DeleteRoot();// root를 지우는 함수 
	~MinPriorityQueue(void);
};


