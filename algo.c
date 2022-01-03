#include "algo.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
nodes* headNode = NULL;
nodes* currentNode = NULL;
#define SIZE  9999
#define N 999
int Q[N];
int Pr[N];
int aCounter=0,f=-1,r=-1,pqSize=0;
int T(char * graph){
char * num;
num = (char*) malloc(strlen(graph));
num[0]='\0';
/////printf("NEW NUM = %s\n",num);
char temp[2];
int cities[6]={0};
int i=0,cVal=0,convertNum=0,k=0,check=0,index=0,tDistance=0, minDistance=0,best=INT_MAX;
while(graph[i]!='\0'){
    cVal=graph[i];
    if(cVal>=48&&cVal<=57){
       temp[0]=graph[i];
       strcat(num,temp);
       if(strlen(graph)-1==i){
          //printf("NEW NUM = %s",num);
          convertNum=convert(num);
          cities[index]=convertNum;
       }
    }else if(strlen(num)!=0){
    if(!k){
      k=convert(num);
      //printf("k= %d \n",k);
    }else{
      cities[index]=convert(num);
      index++;
    }
      free(num);
      num = (char*)malloc(strlen(graph));
      num[0]='\0';
    }
    i++;
}check=k;
free(num);

for(int a=0;a<k;a++){
   for(int b=0;b<k;b++){
       check-=1;
       if (cities[b]!=cities[a])
     {
         minDistance=S("shalom",cities[a],cities[b],1);
         if (minDistance!=-1&&minDistance)
         {
         tDistance+=minDistance;
        // printf("a= %d b= %d \n",cities[a],cities[b]);
                //printf("minDistance= %d\n",minDistance);
                //printf("tDistance= %d\n",tDistance);
         if (check==1)
         {
            // printf("HOLYSHIT\n");
           if (best>tDistance)
           {
               best=tDistance;
           }tDistance=0;
         }
         }else { tDistance=0;check=k; continue;}
         for(int c=0;c<k&&check-1;c++){
             check-=1;
              if (cities[c]!=cities[a]&&cities[c]!=cities[b])
            {
                minDistance=S("shalom",cities[b],cities[c],1);
                if (minDistance!=-1&&minDistance)
                {
                tDistance+=minDistance;
                //printf("a= %d b= %d, c= %d \n",cities[a],cities[b],cities[c]);
                //printf("minDistance= %d\n",minDistance);
                //printf("tDistance= %d\n",tDistance);
                if (check==1)
                {
                // printf("HOLYSHIT\n");
                  if (best>tDistance)
                  {
                    best=tDistance;
                    }
                    tDistance=0;
                    break;
                     }
                     }else { tDistance=0;check=k-1;continue;}
             // printf("a= %d b = %d, c = %d\n",cities[a],cities[b],cities[c]);
                for(int d=0;d<k&&check-1;d++){
                    check-=1;
              if (cities[d]!=cities[a]&&cities[d]!=cities[b]&&cities[d]!=cities[c])
                  {
                      minDistance=S("shalom",cities[c],cities[d],1);
                if (minDistance!=-1&&minDistance)
                {
                tDistance+=minDistance;
                if (check==1)
                {
                 //printf("HOLYSHIT\n");
                  if (best>tDistance)
                  {
                    best=tDistance;
                    //printf("a= %d b= %d, c= %d d= %d\n",cities[a],cities[b],cities[c],cities[d]);
                    //printf("minDistance= %d\n",minDistance);
                   // printf("tDistance= %d\n",tDistance);
                   // printf("best= %d\n", best);
                    break;
                    }tDistance=0;
                     }
                     }else { tDistance=0;check=k-2;continue;}
                       for(int e=0;e<k&&check-1;e++){
                           check-=1;
                        if (cities[e]!=cities[a]&&cities[e]!=cities[b]&&cities[e]!=c&&cities[e]!=cities[d])
                          {
                                    minDistance=S("shalom",cities[d],cities[e],1);
                                    if (minDistance!=-1&&minDistance)
                                    {
                                    tDistance+=minDistance;
                                    if (check==1)
                                     {
                                     // printf("HOLYSHIT\n");
                                         if (best>tDistance)
                                        {
                                          best=tDistance;
                                               }tDistance=0;
                                              }
                                           }else { tDistance=0;check=k-3;continue;}
                              //printf("a= %d b= %d, c= %d d= %d e= %d\n",cities[a],cities[b],cities[c],cities[d],cities[e]);
                              for(int f=0;f<k&&check-1;f++){
                                  check-=1;
                           if(cities[f]!=cities[a]&&cities[f]!=cities[b]&&cities[f]!=cities[e]&&cities[f]!=cities[c]&&cities[f]!=cities[d])
                                {
                                    minDistance=S("shalom",cities[e],cities[f],1);
                                    if (minDistance!=-1&&minDistance)
                                    {
                                    tDistance+=minDistance;
                                    if (check==1)
                                     {
                                     // printf("HOLYSHIT\n");
                                         if (best>tDistance)
                                        {
                                          best=tDistance;
                                               }tDistance=0;
                                              }
                                           }else { tDistance=0;check=k-4;continue;}
                                }
                                check=k-4;
                              }
                          }
                          check=k-3;
                    }
                  }
                  check=k-2;
                }
            }
            check=k-1;
         }
     }
     check=k;
   }
}
//printf("Best route= %d",best);
if (best>=INT_MAX) return -1;
return best;
}
int S(char *graph,int s,int d,int type ){
//printf("Shalom = %s",graph);
char *num;
char tempC[2];
num=(char*)malloc(sizeof(graph));
num[0]='\0';
int src=0,dest=0;// delete later
int i=0,srcID=0,destID=0,t=0,cVal=0,check=0;
if(type==0) 
{
while (graph[t]!='\0')
{
    cVal=graph[t];
    if (cVal>=48&&cVal<=57)
    {
        tempC[0]=graph[t];
        strcat(num,tempC);
    }else if(strlen(num)!=0&&cVal!=83){
      if (check==0)
      {
          src=convert(num);
          check=1;
          free(num);
          num=(char*)malloc(strlen(graph));

          num[0]='\0';
      }
}
 t++;
}
dest=convert(num);
free(num);
}else{
    src=s; dest=d;
    free(num);
}
if(getNode(src,0)==NULL||getNode(dest,0)==NULL) return -1;
//printf("src= %d, dest= %d\n",src,dest);
nodes* currentNode=getNode(src,0);
nodes* temp=headNode;
edges* edgeTemp=currentNode->headEdge;
while (temp!=NULL)
                 {
                    temp->tempID=i;
                     if(temp->id==src) srcID=temp->tempID;
                     else if(temp->id==dest) destID=temp->tempID;
                     temp=temp->next;
                     i++;}
// //Dont forget to change the srcID and destID accordingly.
// //Dont forget to free the arrays used in the priority queue
        int minDist=0,newDist=0;
        int index=0;
        int tempNew[2]={0};
        int* distance = (int*)malloc(nodeCount()*sizeof(int));//dist==distance
        int* visited = (int*)malloc(nodeCount()*sizeof(int));
        //("node count = %d",nodeCount());
            for(int i=0;i<nodeCount();i++){
               visited[i]=0;
               distance[i]=INT_MAX;
                //System.out.println(visitKey);
            }
            distance[srcID]=0;
            enqueue(srcID,0);
           // printf("size= %d\n",pqSize);
             while(pqSize!=0){
                dequeue(tempNew); index=tempNew[0]; minDist=tempNew[1];// change temp name.
                visited[index]=1;
                //printf("size= %d\n",pqSize);
                 edgeTemp=getNode(index,1)->headEdge;
                 if(distance[index]<minDist) continue;
                 while(edgeTemp!=NULL){
                   //  printf("TEmp id=%d\n",visited[edgeTemp->destNode->tempID]);
                   if (visited[edgeTemp->destNode->tempID]) {edgeTemp=edgeTemp->next; continue;}//Thr problem is here. always enters continue.
                   newDist=distance[index]+edgeTemp->weight;
                   if(newDist<distance[edgeTemp->destNode->tempID]){
                       distance[edgeTemp->destNode->tempID]=newDist;
                       enqueue(edgeTemp->destNode->tempID,newDist);
                   }
                    edgeTemp=edgeTemp->next;
                 }
             }
             int ret= distance[destID];
            if(ret>=INT_MAX){
                return -1;
            }
            free(distance);
            free(visited);
        return ret;
}
void enqueue(int data,int p)//Enqueue function to insert data and its priority in queue
{
    int k =0;
	int i;
	if((f==0)&&(r==N-1)) //Check if Queue is full
		k++;
	else
	{
		if(f==-1)//if Queue is empty
		{
			f = r = 0;
			Q[r] = data;
			Pr[r] = p;
  
		}
		else if(r == N-1)//if there there is some elemets in Queue
		{
			for(i=f;i<=r;i++) { Q[i-f] = Q[i]; Pr[i-f] = Pr[i]; r = r-f; f = 0; for(i = r;i>f;i--)
				{
					if(p>Pr[i])
					{
						Q[i+1] = Q[i];
						Pr[i+1] = Pr[i];
					}
					else
						break;
					Q[i+1] = data;
					Pr[i+1] = p;
					r++;
				}
			}
		}
		else
		{
			for(i = r;i>=f;i--)
			{
				if(p>Pr[i])
				{
					Q[i+1] = Q[i];
					Pr[i+1] = Pr[i];	
				}
				else
					break;
			}
			Q[i+1] = data;
			Pr[i+1] = p;
			r++;
		}	
        pqSize++;
	}

}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void dequeue(int temp[]) //remove the data from front
{
    if(f == -1)
	{
		//printf("Queue is Empty");
	}	
	else
	{
		//printf("deleted Element = %d\t Its Priority = %d\n",Q[pqSize-1],Pr[pqSize-1]);
        temp[0]=Q[pqSize-1]; temp[1]=Pr[pqSize-1];
		if(f==r)
			f = r = -1;
		else
			f++;
        pqSize--;
	}
}
void A(char* graph){ //Sending the string after every n occures, it always a number which is equal to 2*n+1, when n is number of edges , and 1 is the id of the node.
//First char represents the id of the node.
//Aribtrary choice, but in reality it will the first char in the given string.
//Every time we enter A command start completely from scratch delete the whole graph.
//print(headNode);
if (nodeCount()>0) deleteGraph(); 
char *num;
num=(char*)malloc(strlen(graph));
num[0]='\0';
char temp[2];
//printf("A graph= %s\n",graph);
nodes* currentNode;
int cVal=0,i=0,j=0,nCheck,aCheck=0,convertNum=0,weight=0,nodeID=0,infoCheck=1;
while (graph[i]!='\0')
{
    cVal=graph[i];
if (cVal==65) aCheck=1;
else if (cVal==110)nCheck=1;
    
  if(nCheck==1){
        if (cVal>=48&&cVal<=57)
        {
            temp[0]=graph[i];
            strcat(num,temp);
        }else if(strlen(num)!=0){
            convertNum=convert(num);
            //printf("current node= %d\n",convertNum);
            currentNode=getNode(convertNum,0);
            free(num);
            num=(char*)malloc(strlen(graph));
            num[0]='\0';
            nCheck=0; infoCheck=1;
        }
    }else if (aCheck==1)
    {
        if (cVal>=48&&cVal<=57)
        {
            temp[0]=graph[i];
            strcat(num,temp);
            //printf("after A= %s\n",temp);
        }else if(strlen(num)!=0){
            convertNum=convert(num);
            //printf("node amount= %d\n",convertNum);
            for(int i=0;i<convertNum;i++){
               addNode(&headNode,i);
            }
            free(num);
            num=(char*)malloc(strlen(graph));
            num[0]='\0';
            aCheck=0;
        }
    }else if (infoCheck==1)
    {
        if (cVal==110)
        {
            nCheck=1;
            infoCheck=0;
        }
         if (cVal>=48&&cVal<=57)
        {
            temp[0]=graph[i];
            strcat(num,temp);
        }else if(strlen(num)!=0){
            convertNum=convert(num);
            if (j%2==0) {nodeID=convertNum; j++; infoCheck=1;}
            else if(j%2==1) {
                weight=convertNum;
                j++;
                addEdge(currentNode,nodeID,weight);
                // printf("dest ID= %d, weight= %d\n",nodeID,weight);
                }
                free(num);
                num=(char*)malloc(strlen(graph));
                num[0]='\0';
        }
    }
   i++;
}
   free(num);
//    printf("\n");
//    print(headNode);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void B(char *graph){
    int i=0,cVal=0,j=0,convertNum=0,weight=0,nodeID=0,idCheck=0;
    nodes* currentNode=NULL;
    char temp[2];
    char* num;
    num=(char*)malloc(strlen(graph));
    num[0]='\0';
    while (graph[i]!='\0')
    {
    cVal=graph[i];
      if (cVal>=48&&cVal<=57)
        {
            temp[0]=graph[i];
            strcat(num,temp);
           // printf("fucking string = %s\n",num);
            if (strlen(graph)-1==i)
            {
            convertNum=convert(num);
            if (j%2==0) {nodeID=convertNum; j++;}
            else if(j%2==1) {
                weight=convertNum;
                j++;
                addEdge(currentNode,nodeID,weight);
                 //printf("B dest ID= %d, weight= %d\n",nodeID,weight);
                }
                free(num);
                num=(char*)malloc(strlen(graph));
                num[0]='\0';
            }
            
        }else if(strlen(num)!=0&&cVal!=66&&idCheck==1){
            convertNum=convert(num);
            free(num);
            num=(char*)malloc(strlen(graph));
            num[0]='\0';
            if (j%2==0) {nodeID=convertNum; j++;}
            else if(j%2==1) {
                weight=convertNum;
                j++;
                addEdge(currentNode,nodeID,weight);
                // printf("B dest ID= %d, weight= %d\n",nodeID,weight);
            }
        }else if (idCheck==0&&strlen(num)!=0)
        {
            convertNum=convert(num);
            free(num);
            num=(char*)malloc(strlen(graph));
            num[0]='\0';
        if(getNode(convertNum,0)!=NULL){
            //deleteNode(&headNode,convertNum);
            //addNode(&headNode,convertNum);
           // printf("SHALOM");
            edges* eHead=getNode(convertNum,0)->headEdge;
            deleteEdges(&eHead);
            currentNode=getNode(convertNum,0);
            currentNode->headEdge=NULL;
            idCheck=1;
        }else{
            addNode(&headNode,convertNum);
            currentNode=getNode(convertNum,0);
            idCheck=1;
        }
    }
    i++;
}
free(num);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void deleteGraph(){
nodes** head=&headNode;
nodes* prev = *head;
edges *edgesEd;
    while (*head)
    {
        *head = (*head)->next;
        edgesEd=prev->headEdge;
        deleteEdges(&edgesEd);
         //printf("\n CURRENT ID= %d\n",prev->id);
        free(prev);
        //printE(edgesEd);
        prev = *head;
    }
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void deleteNodeD(int id){
nodes *temp=headNode;
edges *head;
while (temp!=NULL)
{
    if(id!=temp->id){
    head=temp->headEdge;
    //printf("curretnNode id= %d",temp->id);
    deleteEdgesD(&head,id);
    }
    temp=temp->next;
}
deleteNode(&headNode,id);
free(head);
free(temp);
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void deleteEdgesD(edges **head, int id){
  //temp is used to freeing the memory
      edges *temp;
      //key found on the head node.
      //move to head node to the next and free the head.
   // printf("\nbefore = \n");
    //printE(*head);
    if(head!=NULL&&*head!=NULL){
      if((*head)->destNode->id==id)
      {
          temp = *head;    //backup to free the memory
          *head = (*head)->next;
          free(temp);
      }
    
      else
      {
          edges *current  = *head;
          while(current->next != NULL)
          {
              //if yes, we need to delete the current->next node
              if(current->next->destNode->id== id)
              {
                  temp = current->next;
                  //node will be disconnected from the linked list.
                  current->next = current->next->next;
                  free(temp);
                  break;
              }
              //Otherwise, move the current node and proceed
              else
                  current = current->next;
          }
      }
    }
   // printf("\nAfter = \n");
   // printE(*head);
    free(currentNode);
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void print(nodes *head) {
    nodes *current_node = head;
   	while ( current_node != NULL) {
      //  printf("id= %d ", current_node->id);
        current_node = current_node->next;
    }
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// void printE(edges*head) {
//     edges*current_node = head;
//    	while ( current_node != NULL) {
//        // printf("id dest edge= %d ", current_node->destNode->id);
//         current_node = current_node->next;
//     }
// }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void deleteNode(nodes **head, int id){
      //temp is used to freeing the memory
      nodes *temp;
      edges *headEd;
      if(head!=NULL&&*head!=NULL){
      if((*head)->id == id)
      {
          temp = *head;    //backup to free the memory
          headEd=(*head)->headEdge;
          deleteEdges(&headEd);
          *head = (*head)->next;
          free(temp);
      }
      else
      {
          nodes *current  = *head;
          while(current->next != NULL)
          {
              //if yes, we need to delete the current->next node
              if(current->next->id== id)
              {
                  temp = current->next;
                  headEd=temp->headEdge;
                  deleteEdges(&headEd);
                  current->next = current->next->next;
                  free(temp);
                  break;
              }
              //Otherwise, move the current node and proceed
              else
                  current = current->next;
          }
      }
}
////printf("Deleted node = %d\n",id);
//print(headNode);
//printf("\n");
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void deleteEdges(edges** head){
  edges* p = *head;
    while (*head)
    {
        *head = (*head)->next;
        free(p);
        p = *head;
    }
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void D(char * graph){
char *num;
num=(char*)malloc(strlen(graph));
num[0]='\0';
int cVal=0,i=0,id=0;
char temp[2];
while(graph[i]!='\0'){
    cVal=graph[i];
    if (cVal>=48&&cVal<=57)
    {
        temp[0]=graph[i];
        strcat(num,temp);
       // printf("fucking string = %s\n",num);
        if(strlen(graph)-1==i){
           id=convert(num);
        }
    }else if(strlen(num)!=0){
         id=convert(num);
    }
i++;
}
//printf("deletion node= %d\n", id);
deleteNodeD(id);
free(num);
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int nodeCount(){
nodes* temp=headNode;
int i=0;
while (temp!=NULL)
{
    temp=temp->next;
    i++;
}
free(temp);
return i;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int myPow(int num,int hez){
    int temp=num;
    if (hez==0)
    {
        return 1;
    }
    
    for (int i = 0; i < hez-1; i++)
    {
        num*=temp;
    }
    return num;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int convert(char * num){//function to convert a char to int.
   // printf("converted = %s \n",num);
    int len=strlen(num);
    int sum=0,i=0,val=0;
    while (num[i]!='\0')
    {
        val=(int)(num[i])-48;//0 == 48 in ascii , so 48-48=0 in int
        sum=sum+(myPow(10,len-i-1)*val);
        i++; 
    }
    return sum;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void addNode(nodes** head,int id) {
  //create a new node
    nodes* newNode = malloc(sizeof(struct GraphNodes));
    newNode->id= id;
    newNode->tempID=0;
    newNode->next= NULL;
    newNode->edge=NULL;//init the edge linked list.
    newNode->headEdge=NULL;
    //if head is NULL, it is an empty list
    if(*head == NULL){
         *head = newNode;
    }
    //Otherwise, find the last node and add the newNode
    else
    {
        nodes* lastNode = *head;
    
        //last node's next address will be NULL.
        while(lastNode->next != NULL)
        {
            lastNode = lastNode->next;
        }

        //add the newNode at the end of the linked list
        lastNode->next = newNode;
    }
    //free(newNode); Why when I use free here it doesn't work , but when I dont it does work.
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void addEdge(nodes*node, int dest,int weight)
{
    //printf("dest= %d\n",dest);
   // printf("TRYING TO ADD EDGE!\n");
    edges** head=&(node->headEdge);
    // printf("hui2= %p\n",*head);
   // printf("hui= %p\n",&(node->headEdge));
    //printf("Edge addressasd in add edge= %p id= %d\n",&(node->edge),node->id); //just to check if it point to the correct address

    edges *newEdge = malloc(sizeof(struct GraphEdges));
    newEdge->destNode=(getNode(dest,0));
    //nodes* nd=getNode(3,0);
   // printf("wtf id= %p\n",nd);
   // printf("received id= %p", (getNode(dest)));
    newEdge->next= NULL;
    newEdge->weight=weight;
    if(*head == NULL){
         *head = newEdge;
    }
    else
    {
        edges *lastEdge = *head;
        while(lastEdge->next != NULL)
        {
            lastEdge = lastEdge->next;
            //printf("while#2");
        }
        //printf("Weight loop= %d\n",newEdge->weight);
        //printf("%d= \n",newEdge->destNode->id);
        lastEdge->next = newEdge;
    }
 //free(newEdge);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////

edges* getEdge(nodes* node, int dest,int funcType){
    //temp is the head
    edges *head=node->headEdge;
    if (funcType==0)
    {
     while(head!= NULL)
    {
         //key found return 1.
         if(head->destNode->id==dest)
             return head;
         head = head->next;
    }
    //key not found
    return NULL;
    }else {
          while(head!= NULL)
    {
         //key found return 1.
         if(head->destNode->tempID==dest)
             return head;
         head = head->next;
    }
    //key not found
    return NULL;
    }

}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////

nodes* getNode(int id,int type) {
   //start from the fi rst link
   nodes* current = headNode;

   //if list is empty
   if(headNode == NULL) {
      return NULL;
   }
   //navigate through list
   if (type==0)
   {
   while(current->id != id) {
      //if it is last node
      if(current->next == NULL) {
         return NULL;
      } else {
         //go to next link
         current = current->next;
      }
   }
   } else{
       while(current->tempID!= id) {
      //if it is last node
      if(current->next == NULL) {
         return NULL;
      } else {
         //go to next link
         current = current->next;
      }
   }
   }
   //if data found, return the current Link
  // printf("requested id= %p", &current);
   return current;
}
