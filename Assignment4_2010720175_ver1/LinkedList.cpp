#include "LinkedList.h"


LinkedList::LinkedList(void)
{// 생성자
	pHead = NULL;// pHead를 NULL로 초기화
	pTail = NULL;// pTail을 NULL로 초기화
}


LinkedList::~LinkedList(void)
{// 소멸자 
	
}

void LinkedList :: Deallocator()
{// 동적 할당한 노드를 해제하는 함수 
	Node* pCur = pHead;
	Node* pTar;

	// 리스트를 돌면서 할당을 해제한다 
	while( pCur )
	{
		pTar = pCur;
		pCur = pCur -> Get_next();
		// 해당 노드안의 TV변수안에도 동적할당된 Vertex들이 저장 되어있기 때문에 그 배열안의 Vertex도 삭제해준다 
		for( int i = 0; i < 6 && pTar -> Get_tv()[i] != NULL; i ++ )// 배열이 NULL이 아닌 경우 
		{
			delete pTar -> Get_tv()[i];// 삭제
		}
		delete pTar;
	}
}

void LinkedList :: Insert( Node* pNew )// 링크드리스트 삽입함수 
{
	if( pHead == NULL )// head가 NULL인 경우 
	{//인자로 받은 노드를 head와 tail에 초기화 
		pHead = pNew;
		pTail = pNew;
		return;
	}
	// head가 이미 있는 경우 
	pTail -> Set_next( pNew );// tail의 다음노드에 인자로받은 노드를 초기화 
	pTail = pTail -> Get_next();// tail을 tail의 다음노드에 연결 

}
