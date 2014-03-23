//////////////////////////////////////////////////////////////
// File Name : Connection. h                                //
// Date : 2012/11/30                                        //
// Compiler : g++ 4.6.3                                     //
// Os : ubuntu 12.04                                        //
// Author : Hwang ji young                                  //
// Student ID : 2010720175                                  //
// ---------------------------------------------------------//
// ver : 1.0.0                                              //
// Description : 전체 프로그램을 관리하는 class              //
// class들의 정보와 간선을 할당하는 함수                     //
// Etc..: Data Structure Assignment #4( KW Data Commercial )//
//////////////////////////////////////////////////////////////

#pragma once
#include"Graph.h"
#include"MinPriorityQueue.h"
#include"file.h"
#include"Bidder.h"
#include"MinPriorityQueue.h"
#include"LinkedList.h"

class ConnectionPlanner
{
private :
	file f;// file 객체
	Bidder b1;// bidder 객체
	Graph g1;// graph객체 
	LinkedList L;// LinkedList의 객체선언 


public:

	ConnectionPlanner(void);// 생성자 
	~ConnectionPlanner(void);// 소멸자 
	void Start();// start함수 
	int NetworkAllocation( Vertex** TV );// 간선을 할당하는 함수 
	void SetEdgeofGraph( char* pNew, char* vertex, int cost );// graph의 channel의 갯수를 수정하는 함수 
	void Print();// 출력하는 함수 
};


