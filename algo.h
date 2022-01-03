 #ifndef ALGO_H  /* Include guard */
#define  ALGO_H
typedef struct GraphEdges{//Linked list of edges
    int weight;
    struct GraphNodes *destNode;
    struct GraphEdges *next; //linked list of edges
}edges;
typedef struct GraphNodes{//Points to the next linked list of edges.
    int id;
    edges *edge;//Eeach node will have data about the edges attached to it
    struct GraphNodes* next;
    edges *headEdge;//The head edge of the edge linked list
    int tempID;
}nodes;
int T(char*);
int S(char*,int,int,int);
void A(char *graph);
void enqueue(int data,int p);
void dequeue(int[]);
void B(char *graph);
void D(char *graph);
void deleteGraph();
void addEdge(nodes* node,int dest,int weight);
void addNode(nodes**,int);
nodes* getNode(int,int) ;
edges* getEdge(nodes* node,int dest,int funcTYPE);
int myPow(int num,int hez);
int convert(char * num);
int Dijkstra(int src, int dest);
void deleteEdges(edges** head);
void deleteNode(nodes **head, int id);
void deleteEdgesD(edges** head,int id);
void deleteNodeD(int);
int nodeCount();
void print(nodes*);
#endif