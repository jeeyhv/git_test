//////////////////////////////////////////////////////////////
// File Name : Bidder.h                                     //
// Date : 2012/11/30                                        //
// Compiler : g++ 4.6.3                                     //
// Os : ubuntu 12.04                                        //
// Author : Hwang ji young                                  //
// Student ID : 2010720175                                  //
// ---------------------------------------------------------//
// ver : 1.0.0                                              //
// Description : 입찰 금액에 따라 어떤 회사가 먼저 할당       //
// 받을 것인지 결정하는 class                                //
// Etc..: Data Structure Assignment #4( KW Data Commercial )//
//////////////////////////////////////////////////////////////
#pragma once
#include"MaxPriorityQueue.h"
#include"file.h"

class Bidder
{
private :

	MaxPriorityQueue max;// Maxpriorityqueue의 객체 저장 
	file f;// fileclass의 객체 저장 

public:

	Bidder(void);// 생성자
	void Start();// maxpriorityqueue를 구성하는 함수 
	QueueNode* Get_company();// Maxpriorityqueue의 root를 얻어오는 함수 
	~Bidder(void);// 소멸자 
};


