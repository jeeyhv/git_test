#include "Graph.h"


Graph::Graph(void)
{
	pRoot = NULL;
}


Graph::~Graph(void)
{
	
}

void Graph :: Deallocator()
{
	Vertex* pVer = pRoot;
	Vertex* pTar;
	Edge* pTar2;
	Edge* pEdg;

	while( pVer )// pVer가 NULL이 아닐 때 까지 
	{
		pEdg = pVer -> Get_adj();
		while( pEdg )// pEdg가 NULL이 아닐 때 까지 
		{
			pTar2 = pEdg;
			pEdg = pEdg -> Get_Adj();
			delete pTar2;// 동적할당한 노드 삭제 
		}
		pTar = pVer;
		pVer = pVer -> Get_next();
		delete pTar;// 동적할당한 노드 삭제 
		
	}
}

void Graph :: InsertVertex( char* pNew )
{
	Vertex *pCur = pRoot;
	Vertex *pCur2 ;

	if( pRoot == NULL )
	{
		Vertex* New = new Vertex( pNew );
		pRoot = New;
		return;
	}

	while( pCur )
	{
		if( !strcmp( pCur -> Get_city(), pNew ) )
		{
			Vertex* New = new Vertex( pNew );
			return;
		}

		pCur2 = pCur;
		pCur = pCur -> Get_next();
		
	}
	Vertex* New = new Vertex( pNew );

	pCur2 -> Set_next( New );
}

void Graph :: InsertEdge( Edge* pNew1, Edge* pNew2 )
{

	Vertex* pCur1 = pRoot;
	Edge* pCur2;

	while( pCur1 )
	{

		if( !strcmp( pCur1 -> Get_city() , pNew1 -> Get_city() ) )
		{
			pNew2 -> Set_adj( pCur1 -> Get_adj() );
			pCur1 -> Set_edge( pNew2 );
		}

		if( !strcmp( pCur1 -> Get_city(), pNew2 -> Get_city() ) )
		{
			pNew1 -> Set_adj( pCur1 -> Get_adj() );
			pCur1 -> Set_edge( pNew1 );
		}

		pCur1 = pCur1 -> Get_next();

	}


}

void Graph :: Start()
{
	gf1.fileopen( "mp3.cities" );
	gf2.fileopen( "mp3.con" );

	char city1[10], city2[10];
	char szCost[10];
	char szChannel[10];
	char szBuffer[1024];
	char* token;
	int cost;
	int channel;

	while( !gf1.Get_infile().eof() )
	{
		gf1.Get_infile() >> city1;
		InsertVertex( city1 );
	}

	while( !gf2.Get_infile().eof() )
	{
		
		gf2.Get_infile().getline( szBuffer, 1024 );
		token = strtok( szBuffer, "\t" );
		strcpy( city1, token );
		token = strtok( '\0', "\t" );
		strcpy( city2 , token );
		token = strtok( '\0', "\t" );
		cost = atoi( token );
		token = strtok( '\0', "\t" );
		channel = atoi( token );
		Edge* pNew1 = new Edge( city1, cost, channel );
		Edge* pNew2 = new Edge( city2, cost, channel );

		InsertEdge( pNew1, pNew2 );
	}


}
