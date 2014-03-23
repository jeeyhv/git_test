#include "Node.h"


Node::Node(void)// 생성자 
{
	fail = 0;// fail을 0으로 초기화 
	bid = 0;// bid를 0으로 초기화 
	pNext = NULL;// 다음 노드를 가르키는 포인터를 NULL로 초기화 
}

// 인자를 받는 생성자 
Node :: Node( int nfail, Vertex** nTV, char* com, int nbid )
{
	fail = nfail;//인자로 받은 값을 private변수에 초기화 
	strcpy( company, com );// 인자로 받은 회사이름을 초기화 
	bid = nbid;// 회사의 입찰 금액을 초기화 
	pNext = NULL;// 다음 노드를 가르키는 포인터를 초기화
	// for문을 돌면서 인자로 받아온 Edge* nTV를 초기화 
	// Graph의 Vertex를 인자로 받아왔기 때문에 그대로 하면안되고
	// 동적할당을 해서 값을 복사해야함 
	if( nTV == NULL )// 간선을 할당받지 못한 경우 
	{
		for( int i = 0; i < 6 ; i++ )
			TV[i] = NULL;
	}
	else
	{
		for( int i = 0; i < 6 ; i++ )
		{
			Vertex* pNew = new Vertex( nTV[i] -> Get_city() );// Vertex를 동적할당 
			pNew -> Set_edgecost( nTV[i] -> Get_edgecost() );// 동적 할당한 Vertex에 인자로 받아온 nTV안의 정보를 복사 
			TV[i] = pNew;// 동적 할당한 노드를 Node의 private변수 TV에 초기화 
		}
	}
	
}

Node::~Node(void)
{
}



