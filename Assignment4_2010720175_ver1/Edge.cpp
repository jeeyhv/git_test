#include "Edge.h"


Edge::Edge(void)
{
}

Edge :: Edge( char* pNew, int edgecost, int channel )// 인자를 받는 생성자 
{// 인자로 받은 값을 초기화 
	strcpy( CityName, pNew );
	EdgeCost = edgecost;
	NumOfChannel = channel;
	Adjacency = NULL;
}

Edge::~Edge(void)
{
}

