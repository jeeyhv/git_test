#include "ConnectionPlanner.h"
#define EDGE 26

ConnectionPlanner::ConnectionPlanner(void)
{

}


ConnectionPlanner::~ConnectionPlanner(void)
{
	g1.Deallocator();// 동적 할당 한 graph를 지우는 함수 호출
	L.Deallocator();// 동적할당한 링크드리스트를 지우는 함수 호출
}

void ConnectionPlanner :: Start()
{
	b1.Start();// bidder에서 maxpriorityheap 생성
	g1.Start();// graph생성
	f.outfileopen( "mp3.out" );// file open

	QueueNode* com;
	while( (com = b1.Get_company())!= NULL )// 할당 받을 회사가 있을 때 까지 반복
	{
		Vertex* TV[6] = {0,};// 할당 받은 edge들을 저장 할 배열을 선언하고 모두 NULL로 초기화 해준다.
		if( !NetworkAllocation( TV ) )// 간선 할당에 성공 한 경우 
		{
			Node* pNew = new Node( 0, TV, com -> Get_city(), com -> Get_cost() );// Node를 동적 할당
			L.Insert( pNew );//동적 할당한 Node를 링크드 리스트에 삽입 해 준다 
		}
		else// 간선 할당에 실패 한 경우 
		{
			Node* pNew = new Node( 1, NULL, com -> Get_city(), com -> Get_cost()  );// Node를 동적할당 
			L.Insert( pNew );// 동적할당한 Node를 링크드리스트에 삽입
		}
		delete com;// Max에서 받아온 QueueNode를 삭제, 동적 할당한 노드이기 때문에 
	}
	Print();// 결과 출력 


	f.outfileclose( "mp3.out" );// fileclose


}

////////////////////////////////////////////////////////
//회사 별로 edge를 할당 해 주는 함수                    //
//인자로 받은 배열에 할당 한 edge를 저장한다            //
//할당에 실패 한 경우, 1을 return, 성공한경우 0 return  //
///////////////////////////////////////////////////////

int ConnectionPlanner :: NetworkAllocation( Vertex** TV )
{
	MinPriorityQueue q1;// MinPrioirtyQueue를 선언
	QueueNode* temp;
	Edge* pCur ;
	Vertex* root = g1.Get_root();// root에 graph의 root를 초기화 해준다 

	for( int i = 1; i < 6 ; i++ )// 연결 할 edge의 총 갯수가 6개 이기 때문에, 6번 반복
	{
		if( TV[0] == NULL )// TV배열에 아무것도 없는 경우 
		{
			if( !(pCur = root -> Get_adj()) )// root에 edge가 없는 경우
			{
				root = root -> Get_next();// root를 고친후
				i = 0;
				continue;// 반복문처음으로 돌아간다
			}
			if( root == NULL )// 연결 할 수있는 edge가 모두 없는 경우 
				return 1;// return 1

			TV[0] = root;// TV의 첫번째 index에 root를 초기화 한다 
			while( pCur )// root의 edge가 있을때 까지 반복
			{
				QueueNode* pNew = new QueueNode( pCur -> Get_city(), pCur -> Get_cost() );// Queue노드를 동적할당 하고 edge정보를 저장 
				pNew -> Set_vertex( root -> Get_city() );
				q1.Insert( pNew );// MinPriorityQueue에 삽입한다
				pCur = pCur -> Get_Adj();// 다음 edge로 이동
			}
			// Queue에 root의 값이 이미 연결 된 edge인지 검사한다 
			for( int j = 0; j < 6 && TV[j] != NULL ; j++ )
			{
				if( !strcmp( TV[j] -> Get_city(), q1.Get_root() -> Get_city() )) // TV집합 안에 이미 있는 값이라면
				{
					delete q1.Pop();// queue의 root를 pop시킨후 삭제 
					j = 0;
					continue;
				}
			}
			if( !q1.Get_root() )// 연결 할 수 있는 edge들이 없는 경우
				return 1;

			temp = q1.Pop();// root의 값을 pop한후 return된 root를 temp에 초기화 

			Vertex* pCur2 = g1.Get_root();
			while( pCur2 )// graph를 돌면서 temp와 같은 이름을 같는 Vertex를 찾는다 
			{
				if( !strcmp( pCur2 -> Get_city(), temp -> Get_city() ) )// 찾은 경우 
				{
					TV[i] = pCur2;// TV집합에 찾은 Vertex를 초기화 
					TV[i] -> Set_edgecost( temp -> Get_cost() );// temp안에 있는 가격 정보를 Vertex에 저장 
					break;
				}
				pCur2 = pCur2 -> Get_next();// vertex이동
			}
			if( TV[i] == NULL )// TV[i]에 저장 된 값이 없는 경우, 위에서 알맞은 Vertex를 찾기 못한 경우 
			{
				delete temp;
				return 1;// return 1
			}
			SetEdgeofGraph( temp -> Get_city(),  temp -> Get_vertex(), temp -> Get_cost() );// graph의 edge를 수정
			q1.clear( q1.Get_root() );// queue를 모두지운다
			q1.Set_root();// queue의 root를 NULL로 초기화 해준다
			delete temp;// temp를 지워준다 

		}
		else// TV집합안에 값이 있는 경우 
		{
			int flag = 0; 
			for( int j = 0; TV[j] != NULL; j++ )// TV집합을 돌면서, 이미 있는 값과 연결된 edge들을 queue에 넣어 준다 
			{
				pCur = TV[j] -> Get_adj();
				while( pCur )
				{
					for( int a = 0; a < 6&& TV[a] != NULL; a++ )// TV[a]번째에 값이 있고, 6보다 작은 경우 
					{
						if( !strcmp( TV[a] -> Get_city(), pCur -> Get_city() ) )// TV에 속한 vertex의 edge가 이미 TV집합안에 있는 경우 
						{
							flag = 1;// flag를 1로 set한다
							break;// 반복문을 나간다 
						}
					}
					if( flag == 0 )// flag가 0인경우, 연결 할 edge가 TV집합 안에 없는 경우 
					{
						QueueNode* pNew = new QueueNode( pCur -> Get_city(), pCur -> Get_cost() );// QueueNode를 동적할당 
						pNew -> Set_vertex( TV[j] -> Get_city() );// Queue에 정보를 저장
						q1.Insert( pNew );// queue노드를 queue에 삽입
					}
					flag = 0;// flag 를 다시 0으로 set한다
					pCur = pCur -> Get_Adj();// edge을 이동
				}


			}
			if( q1.Get_root() == NULL )// 연결 될 수 있는 edge가 없는 경우 
				return 1;

			// queue의 root의 값이 이미 연결 된 edge인지 검사 
			for( int k = 0; k < 6 && TV[k] != NULL ; k++ )
			{
				if( !strcmp( TV[k] -> Get_city(), q1.Get_root() -> Get_city() )) // TV집합 안에 이미 있는 값이라면
				{
					delete q1.Pop();// Queue의 root를 pop한다 
					k = 0;// k를 0으로 초기화하고
					continue;// 반복문의 처음으로 돌아간다 
				}
			}
			if( !q1.Get_root() )//연결 할 수 있는 edge들이 없는 경우
				return 1;

			temp = q1.Pop();// temp에 queue의 root를 저장 
			Vertex* pCur2 = g1.Get_root();// pCur2에 그래프의 root를 초기화
			
			// graph를 돌면서 temp와 같은 이름의 Vertex를 찾아서 TV에 초기화 해준다 
			while( pCur2 )
			{
				if( !strcmp( pCur2 -> Get_city(), temp -> Get_city() ) )// 찾은경우
				{
					TV[i] = pCur2;// TV에 초기화
					TV[i] -> Set_edgecost( temp -> Get_cost() );// cost를 저장한다
					break;// 반복문을 빠져나온다
				}
				pCur2 = pCur2 -> Get_next();// 다음 Vertex로 이동
			}

			if( TV[i] == NULL )// temp와 같은 이름의 Vertex를 찾지 못한 경우 
			{
				delete temp;// temp삭제
				return 1;// 1을 return
			}

			q1.clear( q1.Get_root() );// queue를 모두지운다
			q1.Set_root();// queue의root를NULL로 초기화 
			SetEdgeofGraph( temp -> Get_city(), temp -> Get_vertex(), temp -> Get_cost() );// graph의 edge를 수정
			delete temp;// temp삭제
		}


	}
	return 0;

}

//////////////////////////////////////////////////////////////////////////////
// 할당 받은 Edge의 갯수를 줄여주는 함수, edge의 갯수가 0이면 해당 edge를      //
// 삭제 해준다                                                               //
//////////////////////////////////////////////////////////////////////////////
void ConnectionPlanner :: SetEdgeofGraph( char* pNew, char* vertex, int cost )
{
	Vertex* pCur1 = g1.Get_root();
	Edge* pCur2;
	Edge* pTar;

	while( pCur1 )// graph를 돌면서 인자로 받아온 vertex와 이름이 같은 Vertex에 연결된 pNew edge를 찾아서 edge의 갯수를 하나줄이고, edge의 갯수가 0인경우 삭제 
	{
		pCur2 = pCur1 -> Get_adj();
		while( pCur2 )
		{
			// edge의 cost가 같고, 이름과 연결된 vertex가 같은 경우 
			if( !strcmp( pCur2 -> Get_city(), pNew ) && pCur2 -> Get_cost() == cost ||  !strcmp( pCur2 -> Get_city(), vertex ) && pCur2 -> Get_cost() == cost )
			{
				pCur2 -> dec_channel();// edge의 갯수를 하나 줄인다 
				if( pCur2 -> Get_channel() == 0 )// edge의 갯수가 0인경우 
				{
					// 해당 edge를 삭제/
					if( pCur1 -> Get_adj() == pCur2 )// Vertex바로 다음에 연결 된 edge인 경우 
					{
						pCur1 -> Set_edge( pCur2 -> Get_Adj() );
						delete pCur2;
					}
					else// 아닌경우 
					{
						pTar -> Set_adj( pCur2 -> Get_Adj() );
						delete pCur2;
					}
				}
				break;
			}
			pTar = pCur2;
			pCur2 = pCur2 -> Get_Adj();
		}
		pCur1 = pCur1 -> Get_next();
	}

	return;

}

void ConnectionPlanner :: Print()// 결과 출력 함수 
{

	Node* pCur = L.Get_head();
	int lease = 0;
	int total = 0;
	int cost = 0;
	int i;
	
	// edge할당에 성공 한 Node들만 출력 
	while( pCur )
	{
		if( !( pCur -> Get_fail() ) )
		{
			f.Get_outfile() << pCur -> Get_com() << " holds the following connetion plan: " << endl;
			f.Get_outfile() << "MST: ";
			
			f.Get_outfile() << pCur -> Get_tv()[0] -> Get_city() ;
			
			for( i = 1; i < 6; i++ )
			{
				f.Get_outfile() << "-" <<  pCur -> Get_tv()[i] -> Get_city(); 	
				total += pCur -> Get_tv()[i] -> Get_edgecost();
			}
			f.Get_outfile() << endl;
			f.Get_outfile() << "Total connection cost : " <<  total << endl << endl;
		}
		
		cost += total;
		total = 0;
		lease += pCur -> Get_bid();
		pCur = pCur -> Get_next();
		
	}

	pCur = L.Get_head();
	f.Get_outfile() << "<< Link rental fail Company List >> " << endl << endl;


	//edge할당에 실패한 경우만 출력 
	while( pCur )
	{
		if( pCur -> Get_fail() )
		{
			f.Get_outfile() << pCur -> Get_com() << endl;
		}
		pCur = pCur -> Get_next();
	}
	f.Get_outfile() << endl;

	f.Get_outfile() << "Total amount of lease for this year : " << lease << endl;
	f.Get_outfile() << "Total amount of connetion cost for this year : " << cost << endl;

}
