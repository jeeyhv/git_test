//////////////////////////////////////////////////////////////
// File Name : Edge. h                                      //
// Date : 2012/11/30                                        //
// Compiler : g++ 4.6.3                                     //
// Os : ubuntu 12.04                                        //
// Author : Hwang ji young                                  //
// Student ID : 2010720175                                  //
// ---------------------------------------------------------//
// ver : 1.0.0                                              //
// Description : Graph의 Edge class                         //
// 도시이름, Edgecost, channel의 갯수등의 정보를 갖고있다.    //
// Etc..: Data Structure Assignment #4( KW Data Commercial )//
//////////////////////////////////////////////////////////////

#pragma once
#include<iostream>
#include<string.h>
#include<stdlib.h>

using namespace std;

class Edge
{
private : 
	char CityName[10];// 도시이름 저장 
	int EdgeCost;// edgecost저장 
	int NumOfChannel;// channel의 갯수를 저장 
	Edge* Adjacency;// 다음 edge를 가르키는 포인터 

public:

	Edge(void);
	// get함수 
	Edge( char* pNew, int edgecost, int channel );
	char* Get_city(){ return CityName; }
	int Get_cost(){ return EdgeCost; }
	int Get_channel(){ return NumOfChannel; }
	Edge* Get_Adj(){ return Adjacency; }
	// set함수 
	void Set_city( char* pNew ){ strcpy( CityName, pNew ); }
	void Set_edge( int nNew ){ EdgeCost = nNew; }
	void Set_channel( int nNew ){ NumOfChannel = nNew; }
	void Set_adj( Edge* pNew ){ Adjacency = pNew; }
	void dec_channel(){ NumOfChannel -= 1; }
	~Edge(void);
};


