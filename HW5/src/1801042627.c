#include<stdio.h>
void menu();
double f_func(int x){
	return (x*x*x-x*x+2);
}
double g_func(double f(int x),int a){
	return (f(a)*f(a));
}
void read_magic_numbers(char buffer_magic[10],char buffer_news[500]){
	int r=0,number_of_secrets=0,t=0;
	double total=0;
	char secret;
	while(buffer_news[r]!='\0'){
		printf("%c",buffer_news[r]);
		if(buffer_news[r]=='#'){
			buffer_magic[t]=buffer_news[r+1];
			t++;			
			number_of_secrets++;
		}
		r++;
	}
	for(r=0;r<t;r++){
		total=total+g_func(f_func,buffer_magic[r]-'0');
	}
	if(buffer_news[0]=='Y'){
		printf("\nNumber of tests performed:%.2f\n",total);
	}
	else if(buffer_news[0]=='F'){
		printf("\nNumber of sick people:%.2f\n",total );
	}
	else if(buffer_news[0]=='K'){
		printf("\nNumber of deaths:%.2f\n",total );
	}
	else if(buffer_news[0]=='S'){
		printf("\nExpected number of sick people:%.2f\n",total );
	}

}
void append_file(char* file_path,char c){
	FILE* fp=fopen(file_path,"a");
	fprintf(fp,"%c",c);
	fclose(fp);
}
void read_news(char buffer[500],char file_path[10],int is_Only_Title){
	FILE *fp1=fopen(file_path,"r");
	char a,d,p;
	int coun=0,i=0,t=1;	
	
	if(is_Only_Title==1){
		fscanf(fp1,"%c",&a);
		while(a!='\n'){
			buffer[coun]=a;
			fscanf(fp1,"%c",&a);
			coun++;
		}
		for(i=0;i<coun;i++){
			printf("%c",buffer[i]);
		}
	printf("\n");
	}
	
	else if(is_Only_Title==0){
		t=fscanf(fp1,"%c",&a);
		while(t!=EOF){
			buffer[coun]=a;
			t=fscanf(fp1,"%c",&a);
			coun++;
		}
		for(i=0;i<coun;i++){
			printf("%c",buffer[i]);
		}
	printf("\n");
	
	fclose(fp1);
	}
}
int main(){
	menu();
}
void menu(){
	char d,buffer[500],choice='y',readed,buffer_magic[10],buffer_news[500];
	int t,check_file=1,i=0,flag=0,ans=1,new,r,y;
	FILE *f;
	
	FILE *fp3;
	
		while(choice=='y'){
			fp3=fopen("readed_news_id.txt","r");//I open it because it should keep track of new file which could have been updated
			flag=0;
			printf("*************DAILY PRESS***************\n");
			printf("Today's News Are Listed For You:\n\n");
			printf("1-)");
			read_news(buffer,"news/1.txt",1);
			printf("2-)");
			read_news(buffer,"news/2.txt",1);
			printf("3-)");
			read_news(buffer,"news/3.txt",1);
			printf("4-)");
			read_news(buffer,"news/4.txt",1);
		
			printf("\nWhat do you want to do?\na.Read a new\nb.List the readed news\nc.Get decrypted information from the news\n");
			scanf(" %c",&d);
			if(d=='a'){
				printf("Which news do you want to read?\n");
				scanf("%d",&t);
				if(t==1){
					
					check_file=fscanf(fp3,"%c",&readed);
					
						while(check_file!=EOF){
							if(readed=='1'){
								flag=1;
							}	
							check_file=fscanf(fp3,"%c",&readed);
						}
					
						if(flag==1){
							printf("This new is readed,Do you want to read again? Yes(1)/No(0)");	
							scanf("%d",&ans);
							if(ans==1){
								read_news(buffer,"news/1.txt",0);
							}
						}
						else{
							read_news(buffer,"news/1.txt",0);
							append_file("readed_news_id.txt",'1');
						}					
				}
				else if(t==2){
					check_file=fscanf(fp3,"%c",&readed);
						while(check_file!=EOF){
							if(readed=='2'){
								flag=1;
							}	
							check_file=fscanf(fp3,"%c",&readed);
						}
						if(flag==1){
							printf("This new is readed,Do you want to read again? Yes(1)/No(0)");	
							scanf("%d",&ans);
							if(ans==1){
								read_news(buffer,"news/2.txt",0);
							}
						}
						else{
							read_news(buffer,"news/2.txt",0);
							append_file("readed_news_id.txt",'2');
						}
					
				}
				else if(t==3){
					
					check_file=fscanf(fp3,"%c",&readed);
					
						while(check_file!=EOF){
							if(readed=='3'){
								flag=1;
							}	
							check_file=fscanf(fp3,"%c",&readed);
						}
					
						if(flag==1){
							printf("This new is readed,Do you want to read again? Yes(1)/No(0)");	
							scanf("%d",&ans);
							if(ans==1){
								read_news(buffer,"news/3.txt",0);
							}
						}
						else{
							read_news(buffer,"news/3.txt",0);
							append_file("readed_news_id.txt",'3');
						}
				}
				else if(t==4){
					check_file=fscanf(fp3,"%c",&readed);
					
						while(check_file!=EOF){
							if(readed=='4'){
								flag=1;
							}	
							check_file=fscanf(fp3,"%c",&readed);
						}
					
						if(flag==1){
							printf("This new is readed,Do you want to read again? Yes(1)/No(0)");	
							scanf("%d",&ans);
							if(ans==1){
								read_news(buffer,"news/4.txt",0);
							}
						}
						else{
							read_news(buffer,"news/4.txt",0);
							append_file("readed_news_id.txt",'4');
						}
					
				}
			}
			else if(d=='b'){
				check_file=fscanf(fp3,"%c",&readed);
				if(check_file!=EOF){
					printf("Readed news are listed below:\n");
					for(t=0;t<4;t++){
						if(check_file!=EOF){
						printf("%c.new is readed\n",readed);
						}
					check_file=fscanf(fp3,"%c",&readed);
					}
				}
				else{
					printf("You have not read any news yet\n");
				}
			}
			else if (d=='c')
			{
				for(y=0;y<500;y++){
					buffer_news[y]='\0';
				}
				printf("Which news would you like to decrypt\n");
				scanf("%d",&new);

				if(new==1){
					y=0;
					r=1;
					f=fopen("news/1.txt","r");
					r=fscanf(f,"%c",&buffer_news[0]);
					while(r!=-1){
						y++;
						r=fscanf(f,"%c",&buffer_news[y]);
						
						
					}
					
				}
				if(new==2){
					y=0;
					r=1;
					f=fopen("news/2.txt","r");
					r=fscanf(f,"%c",&buffer_news[0]);
					while(r!=-1){
						y++;
						r=fscanf(f,"%c",&buffer_news[y]);	
					}
				}
				if(new==3){
					y=0;
					r=1;
					f=fopen("news/3.txt","r");
					r=fscanf(f,"%c",&buffer_news[0]);
					while(r!=-1){
						y++;
						r=fscanf(f,"%c",&buffer_news[y]);	
					}
				}
				if(new==4){
					y=0;
					r=1;
					f=fopen("news/4.txt","r");
					r=fscanf(f,"%c",&buffer_news[0]);
					while(r!=-1){
						y++;
						r=fscanf(f,"%c",&buffer_news[y]);	
					}
				}
				read_magic_numbers(buffer_magic,buffer_news);
				fclose(f);
			}

			printf("\nDo you want to continue?Yes(y)/No(n)\n");
			scanf(" %c",&choice);
			if(choice=='n'){
				choice='n';
				printf("Good Bye!\n");
			}
		
			fclose(fp3);// I closed it in while loop because I will open it again in same loop
		}
	
}
