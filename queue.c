 /* Group Memebers: Alina Kozhamberdina
 * Date: 10/17/2019
 * Description: This program implements priorty queue by using an array
 */
#include <stdio.h>
#include <time.h>
#define MAX 5000000
 
void insert();
void delete();
void display();
int queue_array[MAX];
int rear = - 1;
int front = - 1;
FILE *fp;
 
int main(){
clock_t start1 = clock();
insert();
double timeElapsed1  = ((double)clock() - start1) / CLOCKS_PER_SEC;

clock_t start = clock();
delete();  
double timeElapsed  = ((double)clock() - start) / CLOCKS_PER_SEC;
printf("\n%f", timeElapsed1);
printf("\n%f", timeElapsed);

getchar();
} /* End of main */
    


void insert(){	
	   
    fp = fopen("C:/Users/User/Desktop/fall 2019/ALG/Assignments/Ass2/test_dat.txt", "r");
        if (fp == NULL) {
        printf("Error opening inputFile.txt");
        }

    int add_item;
   
    
        if (front == - 1){
        front = 0;
	   int time = 1;
	    while ((add_item = fgetc(fp)) != EOF){
        fscanf(fp,"%d", &add_item);
        rear = rear + 1;
        queue_array[rear] = add_item;
		
		time = time +1;
		
		if (time > 150000){
			break;}
	   }
    }
		
	  fclose(fp);
} 
 
void delete(){
    if (front == - 1 || front > rear)
    {
        printf("Queue Underflow \n");
        return ;
    }
    else
    {
      
         int small = queue_array[rear];
        for (int p=0; p < rear; p++){
           
            if(queue_array[p] < small){
                small = queue_array[p];
                
             
               
            }
        }
       
        
        for(int z= 0; z < rear; z++){
            if(queue_array[z] == small){
               int temp = queue_array[rear];
                
                queue_array[z] = temp;
            }
          
        }
         
        rear = rear - 1; // delete the last one
    
    }

} // End of delete() 
 
void display()
{
    int i;
    if (front == - 1)
        printf("Queue is empty \n");
    else
    {
        printf("Queue is : \n");
        for (i = front; i <= rear; i++)
            printf("%d ", queue_array[i]);
        printf("\n");
    }
}
