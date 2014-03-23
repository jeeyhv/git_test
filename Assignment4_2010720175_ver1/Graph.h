//////////////////////////////////////////////////////////////
// File Name : Graph.h                                      //
// Date : 2012/11/30                                        //
// Compiler : g++ 4.6.3                                     //
// Os : ubuntu 12.04                                        //
// Author : Hwang ji young                                  //
// Student ID : 2010720175                                  //
// ---------------------------------------------------------//
// ver : 1.0.0                                              //
// Description : adjacency list                             //
// 도시들이 어떻게 연결되어 있는지 알 수 있ek                 //
// Etc..: Data Structure Assignment #4( KW Data Commercial )//
//////////////////////////////////////////////////////////////

#pragma once
#include<stdlib.h>
#include"Vertex.h"
#include"file.h"

class Graph
{
private :

	Vertex *pRoot;// graph의 제일 처음을 가르키는 포인터 
	file gf1;// file입출력을 위한 file class의 객체 
	file gf2;

public:

	Graph(void);
	void Start();// graph를 생성하는 함수 
	Vertex* Get_root(){ return pRoot; }// graph의 root를 가져 올 수 있는 함수 
	void Set_root( Vertex* pNew ){ pRoot = pNew; }// graph의 root를 고치는 함수 
	void InsertVertex( char* pNew );// vertex를 삽입하는 함수 
	void InsertEdge( Edge* pNew1, Edge* pNew2 );// edge를 삽입하는 함수 
	void DeleteVertex( char* city );// 인자로 받은 city를 CityName으로 가지고 있는 Vertex를 삭제
	void DeleteEdge( char* city );// 인자로 받은 city를 CiryName으로 가지고 있는 Edge를 삭제
	void Deallocator();
	~Graph(void);
};


