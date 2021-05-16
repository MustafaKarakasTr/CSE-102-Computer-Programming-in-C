#include<stdio.h>
#include<math.h>
#include <string.h>
#include<stdlib.h>
#define N 8
void install_pipes(int visited[N][N],int x,int y,int orientation,int i)// I could not do part2.
{	
	int a=x+y;
	int k,l;
	orientation=1;
	visited[x][y]=i;
	if(i<=10){
		
		if( visited[x+2][y+1]<i && x<6 && y<7 )
		{
			
			k=-2;
			l=-1;
			y++;
			x=x+2;
			printf("O1 ");
			install_pipes(visited,x,y,orientation,i);
			
			
		}
		
		else if(visited[x+1][y-2]<i && x<7 && y>1){
			k=-1;
			l=2;
			x++;
			y=y-2;
			printf("O2 ");
			install_pipes(visited,x,y,orientation,i);
			
		}
		
		else if(visited[x-2][y-1]<i && x>2 && y>0){
			k=2;
			l=1;
			x=x-2;
			y=y-1;
			printf("O3 ");
			install_pipes(visited,x,y,orientation,i);
			
			
		}
		
		else if( visited[x-1][y+2]<i && x>0 && y<6){
			k=1;
			l=-2;
			x--;
			y+=2;
			printf("O4 ");
			
			install_pipes(visited,x,y,orientation,i);
			
			
		}
		
		else if( visited[x+1][y+2]<i && x<7 && y<6)
		{
			k=-1;
			l=-2;
			x++;
			y+=2;
			printf("O5 ");
			install_pipes(visited,x,y,orientation,i);
			 
		}
		
		else if( visited[x+2][y-1]<i && x<6 && y>0){
			k=-2;
			l=1;
			
			x+=2;
			y--;
			printf("O6 ");
			install_pipes(visited,x,y,orientation,i);
			
		}
		
		 else if (visited[x-1][y-2]<i && x>0 && y>1)
		{
			k=1;
			l=2;			
			x--;
			y=-2;
			printf("O7 ");
			install_pipes(visited,x,y,orientation,i);
			

			
		}
		
		else  if(visited[x-2][y+1]<i && x>1 && y<7){
			k=2;
			l=-1;

			x-=2;
			y++;
			printf("O8 ");
			install_pipes(visited,x,y,orientation,i);
			
		}
		else {
			visited[x][y]=0;
			x=x+k;
			y=y+l;
			i++;
			printf("\n");	
			install_pipes(visited,x,y,1,i);
		}
		
	}
		
	
}
void generate_hofstadters_sequence(int *arr,int n){
	
	if(n==0 ||n==1){ 
		arr[n]=1;
		if(n==1)
			generate_hofstadters_sequence(arr,n-1);	
	}
	else{
		generate_hofstadters_sequence(arr,n-1);
		arr[n]=arr[n-arr[n-1]]+arr[n-arr[n-2]];
	}
	
}
int find_max(int arr[],int index,int max_value){
	if(index==0){
		return arr[0];
	}
	else{
		max_value=find_max(arr,index-1,max_value);
		if(max_value<arr[index])
			max_value=arr[index];
	}
	return max_value;
}
void makearrayempty(int arr[],int size){
	arr[size]=0;
	if(size!=0)
		makearrayempty(arr,size-1);
	
}
int sum_array(int arr[]){
	int sum=0;
	if(arr[0]<300 && arr[0]>0)// This statement was if(arr[0]!=0) but it didnt work for n=500 so I had to change it
		sum=arr[0]+sum_array(arr+1);
	
	return sum;
}
double std_array(int arr[],double *mean,int n,int index){
	double difference=0;
	if(index<n){/*To find mean*/
		*mean=*mean+arr[index];
		std_array(arr,mean,n,index+1);
		}
	
	else if(index==n){
		if(n!=0)
			*mean=*mean/n;
		else
			return 0;
		
		}/*We have found mean so we can start calculating standart deviation*/
	if(index<2*n && index>=n){
		
		difference=std_array(arr,mean,n,index+1)+(*mean-arr[index-n])*(*mean-arr[index-n]);
		/*To calculate sum of square of difference between mean and each index*/
		
	}
	if(index<2*n && index>n)
		return difference;
		
	else if(index==n)
		return sqrt(difference/(n-1));
	
/*Difference keeps track of sum of last calculations at the end of the recursion index will be equal to n and I will send it to main after making it standart deviation*/
		
	
}
void part1(){
	int a=0,n=1;
	int i;
	int arr[500]={0};//To make all elements 0
	double mean=0;
	while(a!=5){
		printf("Please make your choice:\n");
		printf("---------------------\n");
		printf("1) Fill Array\n");
		printf("2) Find Biggest Number\n");
		printf("3) Calculate Sum\n");
		printf("4) Calculate Standart Deviation\n");
		printf("5) Exit\n");
		scanf("%d",&a);
		switch(a){
			case 1:
				n=1;
				printf("Enter a number:");
				scanf("%d",&n);
				
				makearrayempty(arr,499);
				if(n!=0)
					generate_hofstadters_sequence(arr,n-1);
				for (i = 0; i < n; ++i)
				{
					printf("%d ",arr[i]);
				}
				printf("\n");
				break;
			case 2:
				if(n==0){
					n++;
				}
				printf("Maximum value:%d\n",find_max(arr,n-1,arr[0]));
				break;
			case 3:
				printf("Sum of array:%d\n",sum_array(arr));
				break;
			case 4:
				mean=0;
				printf("Standart deviation of the sequence:%lf\n",std_array(arr,&mean,n,0));
				printf("Mean of the sequence:%lf\n",mean);
		}
	}
}
void shift(char *str){
	str[0]=str[1];
	if(str[1]!='\0')
		shift(str+1);
}
char * remove_duplicates(char* str){

	if(str[0]==str[1])
	{	
		shift(str);
		remove_duplicates(str);
	}
	else if(str[1]!='\0')
		remove_duplicates(str+1);
	
	return str;
}
void menu(){
	int i=0;
	int visited[N][N]={0};
	int orientation;
	char str[100];
	printf("Welcome to Homework 8, please  choose one of the parts to continue\n--------------------\n");
	while(i!=4){	
	printf("1) Execute Part 1\n");
	printf("2) Execute Part 2 (It does not work properly)\n");	
	printf("3) Execute Part 3\n");
	printf("4) Exit\n");
	scanf("%d",&i);
		if(i==1)
			part1();
		else if(i==2){
			orientation=0;
			install_pipes( visited,0,0,orientation,1);
			printf("\n");
		}

		else if(i==3){
			printf("Enter a string:");
			scanf(" %[^\n]s",str);//To be able to taking all string even if user presses space		
			printf("Your text : %s\n",remove_duplicates(str));
		}
	}	
}
void main(){
	menu();	
}
