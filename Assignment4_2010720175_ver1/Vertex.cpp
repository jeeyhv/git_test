#include "Vertex.h"


Vertex::Vertex(void)
{
}

Vertex :: Vertex( char* pNew )// 인자를 받는 생성자 
{
	strcpy( CityName, pNew );// 인자로 받은 값을 초기화
	//포인터들을 NULL로 초기화 
	NextCity = NULL;
	Adjacency = NULL;
}

Vertex::~Vertex(void)
{

}

