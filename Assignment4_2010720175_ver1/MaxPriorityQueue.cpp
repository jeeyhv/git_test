#include "MaxPriorityQueue.h"


MaxPriorityQueue::MaxPriorityQueue(void)
{
	root = NULL;
}


MaxPriorityQueue::~MaxPriorityQueue(void)
{
}

QueueNode* MaxPriorityQueue :: Meld( QueueNode* a, QueueNode* b )
{
	QueueNode* temp;

	if( a == NULL )
	{
			a = b;
			return a;
	}

	if( a -> Get_cost()  < b -> Get_cost() )// a가 b보다 작을 때
	{// a와 b를 swap
		temp = a;
		a = b;
		b = temp;
	}

	if( !a -> Get_right() )// 오른쪽 child가 비어있는 경우
		a -> Set_right( b );// 오른쪽 child에 b를 삽입
	else// 오른쪽 child가 있는 경우
	{
		temp = Meld( a -> Get_right() , b );
		a -> Set_right( temp ); // 오른쪽 child가 NULL일 때 까지 재귀호출
	}



	if( !a -> Get_left() )// left child가 비어있는 경우
	{// 오른쪽 child를 leftchild로 옮겨준다 
		a -> Set_left( a -> Get_right());
		a -> Set_right( NULL );
	}
	else if( a -> Get_right() )// 오른쪽 child가 있을 때
	{
		if( a -> Get_left() ->  Get_short() <  a -> Get_right() -> Get_short()  )// a의 오른쪽chlid와 왼쪽 child의 shotest비교
		{// 오른쪽의 shortest가 더 크면 left subtree와 right subtree를 swap
			temp = a -> Get_right();
			a -> Set_right(  a -> Get_left() ) ;
			a -> Set_left( temp ) ;
		}
	}

	// shortest update
	if( a -> Get_left() && a -> Get_right() )// a가 양쪽 child를 모두 다 가지고 있는 경우 
	{
		a -> Set_shortest( a -> Get_right() -> Get_short() + 1 );
	}
	else // 그렇지 않은 경우
		a -> Set_shortest( 1 ); 


	return a;
}

void MaxPriorityQueue :: Insert( QueueNode* pNew )
{
	QueueNode *a = root ;
	QueueNode * b = pNew;
	QueueNode *temp;

	if( root == NULL )// tree가 비어있는 경우
		root = b;
	else
	{
		root = Meld( a, b );
	}
}

void MaxPriorityQueue :: clear( QueueNode *p )
{
	
	QueueNode *left;// LeftistTreeNode포인터 변수 선언
	QueueNode *right;

	if (p)// 인자로 들어온 p가 NULL이 아닐 때
	{
		left = p -> Get_left();// p의 left child를 left에 초기화
		right = p -> Get_right();// p의 right child를 right에 초기화 

		delete p;// p를 지운다

		if (left) clear(left);// left subtree를 지운다
		if (right) clear(right);// right subtree를 지운다
	} 
}

QueueNode* MaxPriorityQueue :: Pop()
{
	QueueNode* temp = root;

	if( root == NULL )// root가 NULL인 경우 
		return NULL;
	else if( root -> Get_left() == NULL )// root의 leftchild가 없는 경우 
		root = NULL;
	else if( root -> Get_right() == NULL )// root의 rightchild가 없는 경우 
		root = root -> Get_left();
	else // 양쪽 모두 child가 있는 경우 
		root = Meld( root -> Get_left(), root -> Get_right() );

	return temp;
}
