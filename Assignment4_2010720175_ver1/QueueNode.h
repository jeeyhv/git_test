//////////////////////////////////////////////////////////////
// File Name : Queue.h                                      //
// Date : 2012/11/30                                        //
// Compiler : g++ 4.6.3                                     //
// Os : ubuntu 12.04                                        //
// Author : Hwang ji young                                  //
// Student ID : 2010720175                                  //
// ---------------------------------------------------------//
// ver : 1.0.0                                              //
// Description : Max, Min prioiry Queue의 노드 class         //
// Max, Minpriority queue에 필요한 정보를 담고있는 노드        //
// 도시 이름과 edgecost 등의 정보가 담겨있다.                  //
// Etc..: Data Structure Assignment #4( KW Data Commercial )//
//////////////////////////////////////////////////////////////

#pragma once

#include<iostream>
#include<stdlib.h>
#include<string.h>

using namespace std;

class QueueNode
{
private :

	char CityName[30];// 도시이름을 저장 할 변수 
	int cost;// edgecost를 저장 할 변수 
	int shortest;// shortest값을 저장 할 변수 
	char vertex[10];// 이 edge가 연결 된 vertex의 이름을 저장 할 변수 
	QueueNode* left;// left child를 가르킬 변수 
	QueueNode* right;// right child를 가르킬 변수 

public:

	QueueNode(void);// 생성자 
	QueueNode( char* city, int ncost );// 인자를 받는 생성자 
	// private변수를 가져올 수 있는 get함수 
	char* Get_vertex(){ return vertex; }
	void Set_vertex( char* pNew ){ strcpy( vertex, pNew ); }
	char* Get_city(){ return CityName; }
	int Get_cost(){ return cost; }
	QueueNode* Get_left(){ return left ; }
	QueueNode* Get_right(){ return right; }
	int Get_short(){ return shortest; }
	// private변수의 정보를 수정 할 수 있는 set함수 
	void Set_cost( int nNew ){ cost = nNew; }
	void Set_left( QueueNode* pNew ){ left = pNew; }
	void Set_right( QueueNode* pNew ){ right = pNew; }
	void Set_shortest( int nNew ){ shortest = nNew; }
	~QueueNode(void);
};

