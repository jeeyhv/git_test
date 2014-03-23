#include "QueueNode.h"


QueueNode::QueueNode(void)
{

}

QueueNode :: QueueNode( char* city, int ncost )// 인자를 받는 생성자 
{
	// 인자로 받은 값들을 초기화 
	strcpy( CityName, city );
	cost = ncost;
	shortest = 1;
	left = NULL;
	right = NULL;

}

QueueNode::~QueueNode(void)
{
}

