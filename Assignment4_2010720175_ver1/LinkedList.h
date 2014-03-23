//////////////////////////////////////////////////////////////
// File Name : LinkedList.h                                 //
// Date : 2012/11/30                                        //
// Compiler : g++ 4.6.3                                     //
// Os : ubuntu 12.04                                        //
// Author : Hwang ji young                                  //
// Student ID : 2010720175                                  //
// ---------------------------------------------------------//
// ver : 1.0.0                                              //
// Description : LinkedList class                          //
// 어떤 회사가 얼마의 비용으로 입찰하여 어떤 경로의 edge를    //
// 할당 받았는지, 아니면 실패했는지를 저장한 class            //
// 결과를 출력 할 때 사용한다.                               //
// Etc..: Data Structure Assignment #4( KW Data Commercial )//
//////////////////////////////////////////////////////////////
#pragma once
#include"Node.h"

class LinkedList
{
private:

	Node* pHead;// linkedlist의 head를 가르키는 변수 
	Node* pTail;// linkedlist의 맨 마지막을 가르키는 변수 
	

public:
	LinkedList(void);
	Node* Get_head(){ return pHead; }// linked list의 head를 가져오는 함수 
	~LinkedList(void);// 소멸자 
	void Deallocator();
	void Insert( Node* pNew );// linkedlist에 삽입 해주는 함수 

};


