//////////////////////////////////////////////////////////////
// File Name : Node.h                                       //
// Date : 2012/11/09                                        //
// Compiler : g++ 4.6.3                                     //
// Os : ubuntu 12.04                                        //
// Author : Hwang ji young                                  //
// Student ID : 2010720175                                  //
// ---------------------------------------------------------//
// ver : 1.0.0                                              //
// Description : LinkedList의 Node class                    //
// 회사 별로 할당에 성공 했는지, 실패했는지 정보가 담겨있고,   //
// 성공 했다면, 할당 한 간선 정보와 회사이름, 회사입찰금액의 정//
// 보가 들어있다.                                           //
// Etc..: Data Structure Assignment #3( KW Data Commercial )//
//////////////////////////////////////////////////////////////

#pragma once
#include<iostream>
#include<string.h>
#include"Vertex.h"

using namespace std;

class Node
{
private :

	int fail;// 할당에 실패했는지 성공했는지를 알 수 있는 flag, 1이면 실패, 0이면 성공 
	int bid;// 회사가 제시한 입찰 금액을 저장하는 변수 
	char company[30];// 회사 이름을 저장 할 변수 
	Vertex* TV[6];// 할당 받은 edge정보를 저장하는 배열
	Node* pNext;// 다음 노드를 가르키는 포인터 

public:
	Node(void);// 생성자 
	Node( int nfail, Vertex** nTV, char* com, int nbid );// 인자를 받는 생성자 
	~Node(void);// 소멸자 
	// private변수의 정보를 받는 함수 
	int Get_fail(){ return fail;  }
	int Get_bid(){ return bid; }
	char* Get_com(){ return company; }
	Vertex** Get_tv(){ return TV; }
	Node* Get_next(){ return pNext; }
	// private변수의 정보를 고치는 함수 
	void Set_next( Node* pNew ){ pNext = pNew; }
	void Set_com( char* pNew ){ strcpy( company, pNew ); }
	void Set_fail( int nNew ){ fail = nNew; }
	void Set_bid( int nNew ){ bid = nNew; }
};


