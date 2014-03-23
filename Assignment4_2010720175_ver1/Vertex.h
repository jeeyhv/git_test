//////////////////////////////////////////////////////////////
// File Name : Vertex.h                                     //
// Date : 2012/11/30                                        //
// Compiler : g++ 4.6.3                                     //
// Os : ubuntu 12.04                                        //
// Author : Hwang ji young                                  //
// Student ID : 2010720175                                  //
// ---------------------------------------------------------//
// ver : 1.0.0                                              //
// Description : Graph의 Vertex Node                        //
// 도시 이름과 edgecost 등의 정보가 담겨있다.                //
// Etc..: Data Structure Assignment #4( KW Data Commercial )//
//////////////////////////////////////////////////////////////

#pragma once
#include"Edge.h"

class Vertex
{
private :
	
	char CityName[10];// 도시 이름을 저장 할 변수 
	Vertex* NextCity;// 다음 vertex를 가르킬 포인터 
	Edge* Adjacency;// 다음 edge를 가르킬 포인터 
	int edgecost;// edge의 cost를 저장 할 변수( 나중에 출력 할 때 사용 하기 위한 것 )

public:

	Vertex(void);
	Vertex( char* pNew );// 인자를 받는 생성자 
	// private 변수를 받을 수 있는 get함수 
	char* Get_city(){ return CityName; }
	Vertex* Get_next(){ return NextCity; }
	Edge* Get_adj(){ return Adjacency; }
	int Get_edgecost(){ return edgecost; }
	// private 변수를 고칠 수 있는 set함수 
	void Set_city( char* pNew ){ strcpy( CityName, pNew );}
	void Set_next( Vertex* pNew ){ NextCity = pNew; }
	void Set_edge( Edge* pNew ){ Adjacency = pNew; }
	void Set_edgecost( int cost ){ edgecost = cost; }
	~Vertex(void);
};


