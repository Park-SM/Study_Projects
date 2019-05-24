#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct tagVertex {
	int Data;
	int Visited;
	int index;

	struct tagEdge *AdjacencyList;
	struct tagVertex *NextVertex;
} Vertex;

typedef struct tagEdge {
	int Weight;
	struct tagEdge *NextEdge;
	struct tagVertex *FromVertex;
	struct tagVertex *TargetVertex;
} Edge;

typedef struct tagGraph {
	struct tagVertex *VertexList;
	int Capacity;
} Graph;

Vertex* CreateVertex(int nData) {
	Vertex *NewVertex = (Vertex*)malloc(sizeof(Vertex));
	NewVertex->Data = nData;
	NewVertex->Visited = 0;
	NewVertex->index = -1;
	NewVertex->AdjacencyList = NULL;
	NewVertex->NextVertex = NULL;
	return NewVertex;
}

Edge* CreateEdge(Vertex *FromV, Vertex *TargetV, int nWeight) {
	Edge *NewEdge = (Edge*)malloc(sizeof(Edge));
	NewEdge->FromVertex = FromV;
	NewEdge->TargetVertex = TargetV;
	NewEdge->Weight = nWeight;
	NewEdge->NextEdge = NULL;
	return NewEdge;
}

Graph* CreateGraph() {
	Graph *NewGraph = (Graph*)malloc(sizeof(Graph));
	NewGraph->VertexList = NULL;
	NewGraph->Capacity = 0;
	return NewGraph;
}

void AddVertex(Graph *graph, Vertex *NewVertex) {
	if (graph->VertexList == NULL) {
		graph->VertexList = NewVertex;
	}
	else {
		Vertex *Current = graph->VertexList;
		while (Current->NextVertex != NULL) Current = Current->NextVertex;
		Current->NextVertex = NewVertex;
	}
	NewVertex->index = graph->Capacity++;
}

void AddEdge(Graph *graph, Edge *NewEdge) {
	Vertex *CurrentV = graph->VertexList;
	while (CurrentV != NULL && CurrentV != NewEdge->FromVertex) CurrentV = CurrentV->NextVertex;
	if (CurrentV != NULL) {
		if (CurrentV->AdjacencyList == NULL)
			CurrentV->AdjacencyList = NewEdge;
		else {
			Edge *CurrentE = CurrentV->AdjacencyList;
			while (CurrentE->NextEdge != NULL) CurrentE = CurrentE->NextEdge;
			CurrentE->NextEdge = NewEdge;
		}
	}
}

void PrintGraph(Graph *graph) {
	if (graph->VertexList != NULL) {
		Vertex *CurrentV = graph->VertexList;

		while (CurrentV != NULL) {
			printf("Vertex[%d]: ", CurrentV->index);
			Edge *CurrentE = CurrentV->AdjacencyList;
			while (CurrentE != NULL) {
				printf("%d[%d] ", CurrentE->TargetVertex->Data, CurrentE->Weight);
				CurrentE = CurrentE->NextEdge;
			}
			CurrentV = CurrentV->NextVertex;
			puts("");
		}
	}
}

int main() {

	int uData = 0;
	printf("Graph Capacity: ");
	scanf("%d", &uData);

	Graph *graph = CreateGraph();
	Vertex **VertexArray = (Vertex**)calloc(uData, sizeof(Vertex));

	puts("");
	for (int i = 0; i < uData; i++) {
		VertexArray[i] = CreateVertex(i + 10);
		AddVertex(graph, VertexArray[i]);
	}

	AddEdge(graph, CreateEdge(VertexArray[0], VertexArray[1], 0));
	AddEdge(graph, CreateEdge(VertexArray[0], VertexArray[2], 0));
	AddEdge(graph, CreateEdge(VertexArray[1], VertexArray[2], 0));
	AddEdge(graph, CreateEdge(VertexArray[1], VertexArray[3], 0));
	AddEdge(graph, CreateEdge(VertexArray[2], VertexArray[3], 0));
	AddEdge(graph, CreateEdge(VertexArray[3], VertexArray[4], 0));
	AddEdge(graph, CreateEdge(VertexArray[4], VertexArray[5], 0));
	AddEdge(graph, CreateEdge(VertexArray[4], VertexArray[6], 0));
	AddEdge(graph, CreateEdge(VertexArray[5], VertexArray[6], 0));

	PrintGraph(graph);
	printf("\nGraph Capacity: %d..\n", graph->Capacity);

	system("PAUSE");
	return 0;
}