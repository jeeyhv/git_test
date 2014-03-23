#include "Bidder.h"


Bidder::Bidder(void)
{
}


Bidder::~Bidder(void)
{

}

void Bidder :: Start()// 회사들의 입찰값 순으로 MaxPrioirtyQueue를 구성하는 함수 
{
	char company[30];
	int cost;
	char szBuffer[256];
	char* token;
	
	f.fileopen( "mp3.bid" );
	
	while( !f.Get_infile().eof() )// file이 끝날 때 까지 
	{// 값을 읽어와서 strtok을 이용하여 값을 자른다
		f.Get_infile().getline( szBuffer, 256 );
		if( !strcmp( szBuffer, "" ))//파일을다읽어온경우 반복문을나간다
			break;
		token = strtok( szBuffer, "\t" );
		strcpy( company, token );
		token = strtok( '\0', "\t" );
		cost = atoi( token );

		QueueNode* pNew = new QueueNode( company, cost );// queue노드를 동적할당 

		max.Insert( pNew );// queue에 삽입 
		memset( szBuffer, 256, sizeof( szBuffer ) );
	}
}

QueueNode* Bidder :: Get_company()
{
	return max.Pop();// maxqueue의 root를 pop하여 return 
}
