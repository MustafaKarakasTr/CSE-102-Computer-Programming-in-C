#include<stdio.h>
#include<math.h>
int number_length(int number);
int find_digit(int number,int index);
int main(){
	int a;
	int index;
	printf("Enter a number (maximum 6 digits):");
	scanf("%d",&a);
	if(a<0){
		a=-a;
	}
	printf("Your number has %d digits.\n",number_length(a));
	printf("When your number is written 100 times next to each other, which digit of this number would you like to see?:");
	scanf("%d",&index);
	printf("%d.th digit of the big number sequence is %d \n",index,find_digit(a,index));
	return 0;
	}

int number_length(int number){
	int len;	
	if(number==0){
		len=1;
	}
	else{
		len=(log10(number)+1);
}
	return len;
}
int find_digit(int number,int index){
	int digit=number_length(number); 	
	int a=index%digit;
	int n=digit-a+1;
	int y=pow(10,n);
	int t=number%y;
	t=t/(pow(10,digit-a));
	if(t==0){
		t=number%10;	
	}
	return t;
}
