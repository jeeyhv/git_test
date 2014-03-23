#include "file.h"


file::file(void)
{
}


file::~file(void)
{
}
// fileopen
void file :: fileopen( char* name )
{
	infile.open( name );
}
//file닫기
void file :: fileclose( char* name )
{
	infile.close();
}
// 출력 file열기
void file :: outfileopen( char* name )
{
	outfile.open( name, ios_base :: app );
}
//출력 file닫기
void file :: outfileclose( char* name )
{
	outfile.close();
}
// 읽어 올 file의 객체를 return 
ifstream& file :: Get_infile()
{
	return infile;
}

// 출력 할 file의 객체를 return
ofstream& file :: Get_outfile()
{
	return outfile;
}

