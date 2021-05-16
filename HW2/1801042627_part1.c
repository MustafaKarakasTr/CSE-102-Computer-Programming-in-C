#include<stdio.h>
#include<math.h>

int draw_triangle(int side1,int side2,int side3);
void type_triangle(int side1,int side2,int side3);
int perimeter_triangle(int side1,int side2,int side3);
double area_triangle(int side1,int side2,int side3);

int main(){
	int a,b,c;
	float amount;
	int choice,choice2;
	printf("Enter the first integer:");
	scanf("%d",&a);
	printf("Enter the second integer:");
	scanf("%d",&b);
	printf("Enter the third integer:");
	scanf("%d",&c);	
	if(draw_triangle(a,b,c)){
		printf("According to triangle inequality theorem,this triangle can be drawn.\n\n");
		type_triangle(a,b,c);
		printf("The perimeter of the triangle:%d\n",perimeter_triangle(a,b,c));
		printf("The area of the triangle:%f\n",area_triangle(a,b,c));	
	}
	else{
		printf("According to triangle inequality theorem,this triangle cannot be drawn \n\n");	
	}
	return 0;
}

int draw_triangle(int side1,int side2,int side3){
	int i;
	if(side1+side2<=side3 || side1+side3<=side2 || side2+side3<=side1){
		i=0;
	}
	else{
		i=1;
	}
	return i;
}
void type_triangle(int a,int b,int c){
	if(a==b && b==c){
		printf("It is an Equilateral Triangle\n");
	}
	else if (a==b || b==c ||a==c){
		printf("It is an Isosceles Triangle\n");
	}
	else{
		printf("It is a Scalene Triangle\n");
	}
	
}
int perimeter_triangle(int side1,int side2,int side3){
	return(side1+side2+side3);
}
double area_triangle(int side1,int side2,int side3){
	double per=side1+side2+side3;
	double p=per/2;
	double area=sqrt(p*(p-side1)*(p-side2)*(p-side3));
	return (area);
}


