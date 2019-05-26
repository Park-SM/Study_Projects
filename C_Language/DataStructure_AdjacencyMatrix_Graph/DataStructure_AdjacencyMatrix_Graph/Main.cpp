#include <stdio.h>
#include <stdlib.h>

typedef struct tagGraph {
	int *VertexArray;
	int *AdjacencyMatrix;
	int NumOfVertex;
} Graph;

Graph* CreateGraph(int uNumOfVertex) {
	Graph *NewGraph = (Graph*)malloc(sizeof(Graph));

	NewGraph->VertexArray = (int*)calloc(uNumOfVertex, sizeof(int));
	NewGraph->AdjacencyMatrix = (int*)calloc(uNumOfVertex, sizeof(int) * uNumOfVertex);
	NewGraph->NumOfVertex = uNumOfVertex;

	return NewGraph;
}

void InputVertexData(Graph *graph, int VertexIndex, int nData) {
	if (VertexIndex >= 0 && VertexIndex < graph->NumOfVertex) graph->VertexArray[VertexIndex] = nData;
	else puts(">> Error:: Invalid Index.");
}

void AddEdge_directed(Graph *graph, int FromV, int TargetV) {
	if (graph != NULL) *(graph->AdjacencyMatrix + (FromV * graph->NumOfVertex) + TargetV) = 1;
	else puts(">> Error:: Failed to add Edge.");
}

void AddEdge_undirected(Graph *graph, int FromV, int TargetV) {
	if (graph != NULL) {
		*(graph->AdjacencyMatrix + (FromV * graph->NumOfVertex) + TargetV) = 1;
		*(graph->AdjacencyMatrix + (TargetV * graph->NumOfVertex) + FromV) = 1;
	} else puts(">> Error:: Failed to add Edge.");
}

void PrintGraph(Graph *graph) {
	if (graph != NULL) {
		printf("    ");
		for (int Row = 0; Row < graph->NumOfVertex; Row++) printf(" %2d ", graph->VertexArray[Row]); printf("\n    ");
		for (int Row = 0; Row < graph->NumOfVertex; Row++) printf(" ==="); puts("");

		for (int Col = 0; Col < graph->NumOfVertex; Col++) {
			printf("%2d||", graph->VertexArray[Col]);
			for (int Row = 0; Row < graph->NumOfVertex; Row++) {
				printf(" %2d ", *(graph->AdjacencyMatrix + (Col * graph->NumOfVertex) + Row));
			}
			puts("");
		}
	} else puts(">> Error:: Failed to add Edge.");
}

int main() {
	Graph *graph = CreateGraph(9);

	for (int i = 0; i < 9; i++) InputVertexData(graph, i, i);

	AddEdge_undirected(graph, 0, 1);
	AddEdge_undirected(graph, 0, 2);
	AddEdge_undirected(graph, 1, 2);
	AddEdge_undirected(graph, 1, 3);
	AddEdge_undirected(graph, 2, 4);
	AddEdge_undirected(graph, 3, 6);
	AddEdge_undirected(graph, 4, 5);
	AddEdge_undirected(graph, 4, 6);
	AddEdge_undirected(graph, 4, 7);
	AddEdge_undirected(graph, 6, 8);

	PrintGraph(graph);

	system("PAUSE");
	return 0;
}