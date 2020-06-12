  /*
 * Name:adjacencyMatrix.c
 * 
 *
 * Group Memebers: Alina Kozhamberdina
 * Date: 11/27/2019
 * Description:  program in C that reads in graphs, 
 which are in the format specified below, 
 into an adjacency matrix data structure. 
 */

   #include <stdio.h>
   #include<stdlib.h>
   #define MAX 150

int numArray[MAX];
int graphArray[MAX][MAX];
FILE *infile;
int edgeWeight[MAX], origin[MAX], destin[MAX];
int a = 0;
int  max_edges;
int num1,num2,num3;

void openFile();
void createGraph();
void display();
void allPairs();
int centralNode();
int main() {
 openFile();
 createGraph();
 printf("Adjacency Matrix:\n");
 display();

 printf("\nAfter allPairs algorithm:\n");
 allPairs();
 display();
 printf("\nCentral Node:\n ");
 centralNode();
 return 0;
}

//method for opening the file
void openFile()  {

 infile = fopen("C:/Users/User/Desktop/fall 2019/ALG/Assignments/Ass3/test3.txt", "r");

   while(!feof(infile)){
      fscanf(infile,"%d",&numArray[a]);
     // printf ("%d\n", numArray[a]);
   a++;
   }
     // printf("%d\n", a);
      fclose(infile);
}

//creating a graph
void createGraph(){
 fscanf(infile, "%d", &numArray[0]);
 max_edges = a - 1;

   //origins index
 num1 =0;
 for (int i = 1; i < max_edges; i= i +3){

    origin[num1] = numArray[i];   
   // printf("origins:");
  //  printf("%d\n", origin[num1]);
    num1++;
   } 
   //destin index
 num2=0;
 for (int i = 2; i<max_edges; i= i +3){

    destin[num2] = numArray[i];  
   // printf("destin:");
  //  printf("%d\n", destin[num2]);
    num2++;
   }

   //edgeWeigh index
 num3=0;
 for (int i = 3; i<max_edges+1; i= i +3){

   edgeWeight[num3] = numArray[i];
  // printf("edgeWeight:");
  // printf("%d\n", edgeWeight[num3]);
   num3++;
   }

// 99 is INFINITY, means that nodes are not connected
for ( int m= 0; m < numArray[0]+1; m++) {
  for (int n = 0; n < numArray[0]+1; n++){
   graphArray[m][n]= 99;
   if (m == n){
      graphArray[m][n] = 0;
      }
   }
}

//assigning edge weight to corresponding nodes
for (int i = 0; i<numArray[0]*2-1; i++){
   graphArray[origin[i]][destin[i]] = edgeWeight[i];
   graphArray[destin[i]][origin[i]] = edgeWeight[i];
   }
}

//displaying the graph
void display() {
int i, j;
   for (i = 0; i < numArray[0]; i++) {
      for (j = 0; j < numArray[0]; j++){
       printf("%4d ", graphArray[i][j]);}
       printf("\n");
   }
}

//implementing All Pairs algorithm
void allPairs(){
   for (int k = 0; k < numArray[0]; k++){
      for(int i = 0; i < numArray[0]; i++){
         for (int j = 0; j < numArray[0]; j++){
            if (graphArray[i][k] + graphArray[k][j] < graphArray[i][j])
               {  graphArray[i][j] = graphArray[i][k] + graphArray[k][j];}
         }
      }
      printf("\nIntermediate Iteration: %d\n", k);
        display();
   }
}

//calculating central node
int centralNode(){
int i,j;
int count = 0 ;
int min[100];
int max;
int minimum;
int location = 1;
 
//checks whether the graph is connected or not  
    for (int m = 0; m < numArray[0]; m++) {
      for (int n = 0; n< numArray[0]; n++){
            if(graphArray[m][n] == 99){
              printf("not connected");
               return -1;
            }
      }
}
   for(i = 0;i < numArray[0];i++){
      max = graphArray[i][0];
      for(j = 1;j < numArray[0];j++){
      if(max < graphArray[i][j]) max = graphArray[i][j];
            }
   count++;
   min[i] = max;
  // printf("\nMaximum of each row: %d ", min[i]);
         }

  // printf("\n%d", count);
   minimum = min[0];
   for (int i= 0; i < count; i++){
    if (min[i] < minimum){
      minimum = min[i];
   location = i;
      }  
   }
printf("\nNode number: %d ", location);
return location;
}





