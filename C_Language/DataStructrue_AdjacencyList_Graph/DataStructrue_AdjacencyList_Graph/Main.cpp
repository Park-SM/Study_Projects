#include <stdio.h>
#include <stdlib.h>

typedef struct tagGraph {
	struct tagVertex *VertexList;
	int Capacity;
} Graph;

typedef struct tagVertex {
	int Data;
	int Visited;
	int Index;

	struct tagEdge *AdjacencyList;
	struct tagVertex *NextVertex;
} Vertex;

typedef struct tagEdge {
	int Weight;
	struct tagVertex *FromVertex;
	struct tagVertex *TargetVertex;
	struct tagEdge *NextEdge;
} Edge;

Graph* CreateGraph() {
	Graph* NewGraph = (Graph*)malloc(sizeof(Graph));

	NewGraph->VertexList = NULL;
	NewGraph->Capacity = 0;

	return NewGraph;
}

Vertex* CreateVertex(int nData) {
	Vertex* NewVertex = (Vertex*)malloc(sizeof(Vertex));

	NewVertex->Data = nData;
	NewVertex->Visited = 0;
	NewVertex->Index = 0;
	NewVertex->AdjacencyList = NULL;
	NewVertex->NextVertex = NULL;

	return NewVertex;
}

Edge* CreateEdge(Vertex *FromV, Vertex *TargetV, int nWeight) {
	Edge* NewEdge = (Edge*)malloc(sizeof(Edge));

	NewEdge->FromVertex = FromV;
	NewEdge->TargetVertex = TargetV;
	NewEdge->Weight = nWeight;
	NewEdge->NextEdge = NULL;

	return NewEdge;
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
	NewVertex->Index = graph->Capacity++;
}

void AddEdge(Graph *graph, Edge *NewEdge) {
	if (graph->VertexList != NULL) {
		Vertex *CurrentV = graph->VertexList;
		while (CurrentV != NULL && CurrentV != NewEdge->FromVertex) CurrentV = CurrentV->NextVertex;
		if (CurrentV != NULL) {
			if (CurrentV->AdjacencyList == NULL) {
				CurrentV->AdjacencyList = NewEdge;
			}
			else {
				Edge *CurrentE = CurrentV->AdjacencyList;
				while (CurrentE->NextEdge != NULL) CurrentE = CurrentE->NextEdge;
				CurrentE->NextEdge = NewEdge;
			}
		}
		else {
			puts(">> Error:: There is not the vertex.");
			free(NewEdge);
		}
	}
}

void PrintGraph(Graph *graph) {
	if (graph->VertexList != NULL) {
		puts(">> Notice:: [] is data value, () is weight value for the edge.\n");
		Vertex *CurrentV = graph->VertexList;
		Edge *CurrentE;
		while (CurrentV != NULL) {
			printf("> %d.Vertex's data is [%d] => ", CurrentV->Index, CurrentV->Data);
			CurrentE = CurrentV->AdjacencyList;
			while (CurrentE != NULL) {
				printf("%d.Vertex(%d) ", CurrentE->TargetVertex->Index, CurrentE->Weight);
				CurrentE = CurrentE->NextEdge;
			}
			CurrentV = CurrentV->NextVertex;
			puts("");
		}
	}
}

int main() {

	Graph *graph = CreateGraph();
	int NumOfVertex = 9;
	Vertex *GraphArray[9];

	for (int i = 0; i < NumOfVertex; i++) {
		GraphArray[i] = CreateVertex(i);
		AddVertex(graph, GraphArray[i]);
	}

	AddEdge(graph, CreateEdge(GraphArray[0], GraphArray[1], 0));
	AddEdge(graph, CreateEdge(GraphArray[0], GraphArray[2], 0));
	AddEdge(graph, CreateEdge(GraphArray[1], GraphArray[2], 0));
	AddEdge(graph, CreateEdge(GraphArray[1], GraphArray[3], 0));
	AddEdge(graph, CreateEdge(GraphArray[2], GraphArray[4], 0));
	AddEdge(graph, CreateEdge(GraphArray[3], GraphArray[6], 0));
	AddEdge(graph, CreateEdge(GraphArray[4], GraphArray[5], 0));
	AddEdge(graph, CreateEdge(GraphArray[4], GraphArray[6], 0));
	AddEdge(graph, CreateEdge(GraphArray[4], GraphArray[7], 0));
	AddEdge(graph, CreateEdge(GraphArray[6], GraphArray[8], 0));

	PrintGraph(graph);

	system("PAUSE");
	return 0;
}