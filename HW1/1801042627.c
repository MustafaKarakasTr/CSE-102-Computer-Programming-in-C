#include<stdio.h>
#include<math.h>
void find_root();
void find_newtonian_root();
int find_multiple_closest(int a,int b);
int main(){      			
	int a;
	int b;
	find_root();
	find_newtonian_root();
	printf("Enter the first integer:");
	scanf("%d",&a);
	printf("Enter the second integer:");
	scanf("%d",&b);
	find_multiple_closest(a,b);
}
void find_root(){
	int a;
	int b;
	int c;
	double delta;	
	double swap;
	double temp;
	double sqrt_of_delta;
	double root1;
	double root2;
	printf("Please Enter the first coefficient:");
	scanf("%d",&a);
	printf("Please Enter the second coefficient:");
	scanf("%d",&b);
	printf("Please Enter the third coefficient:");
	scanf("%d",&c);
	delta=b*b-4*a*c;	
	if(delta>=0){						
		sqrt_of_delta=sqrt(delta);
		
		root1=(-b+sqrt_of_delta)/(2*a);
		root2=(-b-sqrt_of_delta)/(2*a);
		if(root2>root1){
			swap=root1;
			root1=root2;
			root2=swap;
		}
		printf("Your equation %dx^2",a);
		if(b<0){
			printf("%dx",b);
		}
		else{
			printf("+%dx",b);
		}
		if(c<0){
			printf("%d",c);
		}
		else{
			printf("+%d",c);
		}
		printf(" has real roots {%lf,%lf}\n\n",root1,root2);
		}
		
		else{
			printf("Your equation %dx^2",a);
		if(b<0){
			printf("%dx",b);
		}
		else{
			printf("+%dx",b);
		}
		if(c<0){
			printf("%d",c);
		}
		else{
			printf("+%d",c);
		}
		
			printf(" does not have any real roots.\n\n");
		}	
}

void find_newtonian_root(){
	int a;
	int b;
	int c;
	float init;
	int i=1;
	float swap;
	float delta;
	float sqrt_of_delta;
	float temp;
	float root1;
	float root2;
	float func;
	float der_of_func;
	float difference=1;
	
	float reel;	
	printf("Please Enter the first coefficient:");
	scanf("%d",&a);
	printf("Please Enter the second coefficient:");
	scanf("%d",&b);
	printf("Please Enter the third coefficient:");
	scanf("%d",&c);
	printf("Please Enter the initial:");
	scanf("%f",&init);
	func=a*init*init+b*init+c;
	der_of_func=2*a*init+b;
	delta=b*b-4*a*c;	
	if(delta>=0){						
		sqrt_of_delta=sqrt(delta);
		
		root1=(-b+sqrt_of_delta)/(2*a);
		root2=(-b-sqrt_of_delta)/(2*a);
		
	
	if(root2>root1){ // It makes me sure about root1 is biggest root because I will aproximate prediction to the nearest root 
			swap=root1;
			root1=root2;
			root2=swap;
	}
	//printf("root1:%f,root2:%f\n",root1,root2);
	if(init>root1){
		reel=root1;
		
	}
	else if(init<root2){
		reel=root2;
		
	}
	else if(root1-init>init-root2){
		
		reel=root2;
	}
	else if(root1-init<init-root2){
		
		reel=root1;
	}
	if(root1-init==init-root2){
		
		reel=root1;
		init=init+0.000001;//if prediction is the midmost number between roots,derivative of function becomes 0.It makes formula go to infinity 
		printf("Reel:%f Root1=%f Root2:%f init:%f\n",reel,root1,root2,init);
	}
	
	printf("Your equation %dx^2",a);
		if(b<0){
			printf("%dx",b);
		}
		else{
			printf("+%dx",b);
		}
		if(c<0){
			printf("%d ",c);
		}
		else{
			printf("+%d ",c);
		}
		printf("and iterations are\n");
	printf("Step	x		f(x)		Difference\n");
	
	der_of_func=a*2*init+b;
	init=init-(func)/(der_of_func);
	difference=init-reel;
	if(difference<0){
		difference=-difference;
	}
	func=a*init*init+b*init+c;
	printf("x%d	%f	%f	%f\n",i,init,func,difference);
	i++;

	der_of_func=a*2*init+b;
	init=init-(func)/(der_of_func);
	difference=init-reel;
	if(difference<0){
		difference=-difference;
	}
	func=a*init*init+b*init+c;
	printf("x%d	%f	%f	%f\n",i,init,func,difference);
	i++;
	
	der_of_func=a*2*init+b;
	init=init-(func)/(der_of_func);
	difference=init-reel;
	if(difference<0){
		difference=-difference;
	}
	func=a*init*init+b*init+c;
	printf("x%d	%f	%f	%f\n",i,init,func,difference);
	i++;
	
	der_of_func=a*2*init+b;
	init=init-(func)/(der_of_func);
	difference=init-reel;
	if(difference<0){
		difference=-difference;
	}
	func=a*init*init+b*init+c;
	printf("x%d	%f	%f	%f\n",i,init,func,difference);
	i++;
	
	der_of_func=a*2*init+b;
	init=init-(func)/(der_of_func);
	difference=init-reel;
	if(difference<0){
		difference=-difference;
	}
	func=a*init*init+b*init+c;
	printf("x%d	%f	%f	%f\n\n",i,init,func,difference);
	i++;

	
}
}
int find_multiple_closest(int a,int b){
	int mod;
	int multiple;
	int difference;
	int closest;
	
	if(b==0){// It checks if divider is zero to prevent dividing by zero error
		if(a==0){
			printf("Closest number to %d that is multiple of %d is itself\n",a,b);
		}
		else{
		printf("Closest number to %d that is multiple of %d is %d\n",a,b,b);
		}
	}
	else if(b!=0){
		difference=a%b;
		multiple=a/b;
		if(difference==0){
			printf("Closest number to %d that is multiple of %d is itself\n",a,b);
		}
		else if(difference>b/2){
			closest=b*(multiple+1);
			printf("Closest number to %d that is multiple of %d is %d\n",a,b,closest);
		}	
		else if((a+difference)%b==0 && (a-difference)%b==0){
			closest=b*(multiple+1);
			printf("Closest number to %d that is multiple of %d is %d\n",a,b,closest);		
		}
		else{				
			closest=b*multiple;
			printf("Closest number to %d that is multiple of %d is %d\n",a,b,closest);
		}
	}	
}
