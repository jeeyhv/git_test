OBJS = main.cpp file.h file.cpp Node.h Node.cpp LinkedList.h LinkedList.cpp Bidder.h Bidder.cpp MaxPriorityQueue.cpp MaxPriorityQueue.h Edge.h Edge.cpp QueueNode.h QueueNode.cpp Vertex.h Vertex.cpp Graph.h Graph.cpp MinPriorityQueue.cpp MinPriorityQueue.h ConnectionPlanner.cpp ConnectionPlanner.h SpanningTree.h SpanningTree.cpp
EXEC = run

CC = g++

all:$(OBJS)
	$(CC) -o $(EXEC) $(OBJS)

clean:
	$(RM) -rf *.cpp~ *.h~ *.out~ *~ $(EXEC) 

