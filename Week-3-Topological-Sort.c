#include <stdio.h>
#define MAX 10

void topologicalSort(int n,int graph[MAX][MAX]){
    int in_degree[MAX]={0};
    int queue[MAX],front=0,rear=-1;

    //InDegree of Each Vertex
    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            if (graph[i][j]==1){
                in_degree[j]++;
            }
        }
    }

    //Enqueue Vertices w InDegree 0
    for(int i=0;i<n;i++){
        if(in_degree[i]==0){
            queue[++rear]=i;
        }
    }

    printf("Topological Sort Order: ");
    while(front<=rear){
        int u=queue[front++];
        printf("%d ",u);

        //Reduce InDegree for Adjacent Vertices
        for (int j=0;j<n;j++){
            if (graph[u][j]==1) {
                in_degree[j]--;
                if(in_degree[j]==0){
                    queue[++rear]=j;
                }
            }
        }
    }
    printf("\n");
}

void main() {
    int n, graph[MAX][MAX];

    printf("Enter the Number of Vertices: ");
    scanf("%d",&n);

    printf("Enter the Adjacency Matrix:\n");
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&graph[i][j]);
        }
    }

    topologicalSort(n,graph);
}
