//////////////////////////////////////////////////////////////
// File Name : file. h                                      //
// Date : 2012/11/30                                        //
// Compiler : g++ 4.6.3                                     //
// Os : ubuntu 12.04                                        //
// Author : Hwang ji young                                  //
// Student ID : 2010720175                                  //
// ---------------------------------------------------------//
// ver : 1.0.0                                              //
// Description : file 입출력에 관한 class                    //
// file open, close하는 함수                                //
// Etc..: Data Structure Assignment #4( KW Data Commercial )//
//////////////////////////////////////////////////////////////

#pragma once
#include<iostream>
#include<fstream>

using namespace std;

class file
{
private :
	ifstream infile;// file을 읽어오기위한 ifstream객체
	ofstream outfile;// file을 쓰기위한 ofstream객체 

public:
	
	file(void);// 생성자 
	~file(void);// 소멸자 
	void fileopen( char* name );// 읽어오기위한 fileopen
	void fileclose( char* name );// 읽어오기위한 fileclose
	void outfileopen( char* name );// 쓰기위한 fileopen
	void outfileclose( char* name );// 쓰기위한 fileclose
	ifstream& Get_infile();// ifstream객체를 받는 변수
	ofstream& Get_outfile();// ofstream객체를 받는 변수 
};


