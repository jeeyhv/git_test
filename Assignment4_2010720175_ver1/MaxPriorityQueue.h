//////////////////////////////////////////////////////////////
// File Name : MaxPriorityQueue.h                           //
// Date : 2012/11/30                                        //
// Compiler : g++ 4.6.3                                     //
// Os : ubuntu 12.04                                        //
// Author : Hwang ji young                                  //
// Student ID : 2010720175                                  //
// ---------------------------------------------------------//
// ver : 1.0.0                                              //
// Description : Max prioiry Queue의 class                  //
// Max, Minpriority queue에 필요한 정보를 담고있는 노드      //
// Queue의 노드를 가르키는 포인터와 삽입, pop함수 포함        //
// Etc..: Data Structure Assignment #4( KW Data Commercial )//
//////////////////////////////////////////////////////////////

#pragma once
#include"QueueNode.h"

class MaxPriorityQueue
{
private :

	QueueNode* root;// Queue의 root를 가르키는 포인터 

public:

	MaxPriorityQueue(void);// 생성자 
	void Insert( QueueNode* pNew );// queue에 삽입하는 함수 
	QueueNode* Meld( QueueNode* a, QueueNode* b );// 두 개의 tree를 합치는 함수 
	void clear( QueueNode* p );// queue를 모두 지워주는 함수 
	QueueNode* Pop();// root를 pop시켜서 return해주는 함수 
	~MaxPriorityQueue(void);// 소멸자 
};


