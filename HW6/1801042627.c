#include<stdio.h>
#include<time.h>
#include<stdlib.h>

void uppercase(char arr[20][20],char found[11],int row_number,int col,int len,int direc,char words[10][11]){
	int a,b=32;//b=97-65 it means 'a'-'A';
	if(direc==0){
		for(a=0;a<len;a++){
			arr[row_number][col+a]=arr[row_number][col+a]-b;
		}
	}
	if(direc==1){
		for(a=0;a<len;a++){
			arr[row_number+a][col]=arr[row_number+a][col]-b;
		}
	}
	if(direc==2){
		for(a=0;a<len;a++){
			arr[row_number+a][col+a]=arr[row_number+a][col+a]-b;
		}
	}
	if(direc==3){
		for(a=0;a<len;a++){
			arr[row_number-a][col-a]=arr[row_number-a][col-a]-b;
		}
	}	
	if(direc==4){
		for(a=0;a<len;a++){
			arr[row_number-a][col]=arr[row_number-a][col]-b;
		}
	}
	if(direc==5){
		for(a=0;a<len;a++){
			arr[row_number][col-a]=arr[row_number][col-a]-b;
		}
	}
	if(direc==6){
		for(a=0;a<len;a++){
			arr[row_number-a][col+a]=arr[row_number-a][col+a]-b;
		}
	}
	if(direc==7){
		for(a=0;a<len;a++){
			arr[row_number+a][col-a]=arr[row_number+a][col-a]-b;
		}
	}
}
int check_found(char words[10][11],char found[11],int len){
	int i,t,flag=1;
	for(i=0;i<10;i++){
		flag=1;
		for(t=0;words[i][t+1]!='\0';t++){
			if(words[i][t]!=found[t])
				flag=0;
		}
		if(flag==1){
			return 1;
		}
		
	}
	return 0;
}
int find_direction(char arr[20][20],char found[11],int row_number,int col,int p){
	int i,a,t,direction=0;
	
		for(t=0;t<p;t++){
			if(arr[row_number][col+t]!=found[t])
				direction=-1;
		}
		if(direction==-1){
			for(t=0;t<p;t++){
				if(arr[row_number+t][col]!=found[t])
					direction=-2;
			}
			if(direction==-1){
				direction=1;
			}
		}
		if(direction<0){
			for(t=0;t<p;t++){
				if(arr[row_number+t][col+t]!=found[t])
					direction=-3;
			}
			if(direction>-3){
				direction=2;
			}
		}
		if(direction<0){
			for(t=0;t<p;t++){
				if(arr[row_number-t][col-t]!=found[t])
					direction=-4;
			}
			if(direction>-4){
				direction=3;
			}
		}
		if(direction<0){
			for(t=0;t<p;t++){
				if(arr[row_number-t][col]!=found[t])
					direction=-5;
			}
			if(direction>-5){
				direction=4;
			}
		}
		if(direction<0){
			for(t=0;t<p;t++){
				if(arr[row_number][col-t]!=found[t])
					direction=-6;
			}
			if(direction>-6){
				direction=5;
			}
		}
		if(direction<0){
			for(t=0;t<p;t++){
				if(arr[row_number-t][col+t]!=found[t])
					direction=-7;
			}
			if(direction>-7){
				direction=6;
			}
		}
		if(direction<0){
			for(t=0;t<p;t++){
				if(arr[row_number+t][col-t]!=found[t])
					direction=-8;
			}
			if(direction>-8){
				direction=7;
			}
		}

	return direction;
}
int check(char arr[20][20],char words[10][11],int coor[10][11][2],int *a,int *b){
	int i,t,y,e=1;
	for(i=0;i<10;i++){
		for (t = 0; t < 11;t++)
		{
			if(coor[i][t][0]== *a && coor[i][t][1]== *b){
				e=0;
			}
		}
	}
	return e;
}
void showTable(char arr[20][20],char words[10][11]){
	int p,l,col,row,a,b;
	char c;
	for(a=0;a<10;a++){
		for(b=0;b<11;b++){
			printf("%c",words[a][b]);
			}
		printf("\n");
	}
	printf("  ");
	for(p=0;p<20;p++){
		if(p<=10)
			printf(" %d",p);
		else{
			printf("%d",p);	
		}	
	}
	printf("\n\n");
	c='a';
	for(col=0;col<20;col++){
		printf("%c  ",c);
		c++;
		
		for(row=0;row<20;row++){
			printf("%c ",arr[col][row]);
		}
		printf("\n");
	}
}
void play(char arr[20][20],char words[10][11]){
	int len,l,d=0,t,direc,comp,comp2,keePlaying=1,row_number,col_number,col,found_true,i=0,flag=1;
	char row,column,found[11]={},a;
	while(keePlaying==1){
		
		showTable(arr,words);

		printf("Please enter the coordinate and the word,If you want to exit,Please enter 'Exit'\n");
		scanf(" %c%c%c %s",&row,&column,&a,found);
		
		
		if(a==' '){
			col=column-'0';
		}
		else{
			col=(column-'0')*10+a-'0';
		}
		if((row=='e' || row=='E')&&(column=='x'||column=='X')){
			keePlaying=0;
			printf("See you later...\n");
		}
		else{
		
		if(row>=97){
			row_number=row-'a';
		}
		else if(row<97){
			row_number=row-'A';
		}	
		
		len=0;
		while(found[len]!='\0'){
			len++;
		}
	found_true=check_found(words,found,len);
	if(found_true){
		direc=find_direction(arr,found,row_number,col,len);
		
		if(direc>=0){
			uppercase(arr,found,row_number,col,len,direc,words);
			
		for(t=0;t<10;t++){
			flag=1;
			for(i=0;words[t][i+1]!='\0';i++){
				if(words[t][i]!=found[i]){
					flag=0;
					
				}
			}
			if(flag==1){
				
				for(i=0;words[t][i+1]!='\0';i++){
					words[t][i]=words[t][i]-32;
				}
			}
			
		}

			d++;
			if(d==10){
				printf("Congratulations!!!!!!!\n");
				keePlaying=0;
			}
		}
		else{
			printf("Your coordinates are wrong\n");
		}
	}
	else{
		printf("Your answer is not valid\n");
	}
	}
	}
}
void take_randoms(char arr[10][11]){
	FILE *f;
	int d=0,a=0,b=0,i=0,t,s=0,taken[10],o;
	char c;
	srand(time(NULL));
	while(d!=EOF && i<10){
		f=fopen("words.txt","r");
		t=rand()%98+1;
		for(o=0;o<i;o++){
			if(taken[o]==t){
				t=rand()%98+1;
				o=0;
			}
		}
		taken[i]=t;
		while(s<t && d!=EOF){
			d=fscanf(f,"%c",&c);
			if(c=='\n'){
				s++;
			}
		}
		s=0;
		d=fscanf(f,"%c",&c);
		while(c!='\n'){
			arr[a][b]=c;
			b++;
			d=fscanf(f,"%c",&c);
		}
		arr[a][b+1]='\0';
		a++;
		b=0;
		i++;
		fclose(f);
	}
}
void main(){
	int p,l,coor[10][11][2]={{{0}}};
	char c=122;//122 z 97 a
	char words[10][11]={{'\0'}};
	char random_words[10][11];	
	char arr[20][20],w;
	int col,row,check_value;
	int a,b,i=0,direction,t=0,order_of_word,d=1;
	srand(time(NULL));
	a=rand()%20;
	b=rand()%20;
	for(col=0;col<20;col++){
		for(row=0;row<20;row++){
			c=(rand()%25)+97;
			arr[col][row]=c;
		}
	}
	take_randoms(words);
	while(i<10){	
			a=rand()%20;
			b=rand()%20;
			t=0;
			direction=rand()%8;
			if(direction==0){//left to right
				if(b>9){
					b=rand()%9;
				}
				while(words[i][t]!='\0'&&words[i][t]<122 && words[i][t]>65){
					check_value=check(arr,words,coor,&a,&b);//check function checks if there is a word which has been put these coordinates before this word
					if(check_value==1){
						arr[a][b]=words[i][t];
						coor[i][t][0]=a;
						coor[i][t][1]=b;
						t++;
						b++;
					}
					else{
						break;
					}
				}
			}
			else if(direction==1){//Up to down
				if(a>9)
					a=rand()%9;
				while(words[i][t]!='\0'&&words[i][t]<122 && words[i][t]>65){
						check_value=check(arr,words,coor,&a,&b);
						if(check_value==1){
						arr[a][b]=words[i][t];
						coor[i][t][0]=a;
						coor[i][t][1]=b;
						t++;
						a++;
					}
					else{
						break;
					}
				}
			}
			else if(direction==2){//Left top
				if(a>9){
					a=rand()%9;
				}
				if(b>9){
					b=rand()%9;
				}
				while(words[i][t]!='\0'&&words[i][t]<122 && words[i][t]>65){
					check_value=check(arr,words,coor,&a,&b);
					if(check_value==1){
					arr[a][b]=words[i][t];
					coor[i][t][0]=a;
					coor[i][t][1]=b;
					t++;
					a++;
					b++;
					
					}
					else{
						break;
					}
				}
			}
			else if(direction==3){// right bottom
				if(b<11){
					b=b+9;
				}
				if(a<11)
					a=a+9;
				while(words[i][t]!='\0'&&words[i][t]<122 && words[i][t]>65){
					check_value=check(arr,words,coor,&a,&b);
					if(check_value==1){
					arr[a][b]=words[i][t];
					coor[i][t][0]=a;
					coor[i][t][1]=b;
					t++;
					a--;
					b--;
					}
					else{
						break;
					}
				}
			}
			else if(direction==4){//down to up
				if(a<11){
					a=a+9;
				}
				while(words[i][t]!='\0'&&words[i][t]<122 && words[i][t]>65){
					check_value=check(arr,words,coor,&a,&b);
					if(check_value==1){
					arr[a][b]=words[i][t];
					coor[i][t][0]=a;
					coor[i][t][1]=b;
					
					t++;
					a--;
					
					}
					else{
						break;
					}
				}
			}
			else if(direction==5){//right to left
				
				if(b<11){
					b=b+9;
				}
				while(words[i][t]!='\0'&&words[i][t]<122 && words[i][t]>65){
					check_value=check(arr,words,coor,&a,&b);
					if(check_value==1){
					arr[a][b]=words[i][t];
					coor[i][t][0]=a;
					coor[i][t][1]=b;
					
					t++;
					b--;
					
					}
					else{
						break;
					}
				}
			}
			else if(direction==6){//left bottom
				
				if(a<11){
					a=a+9;
				}
				if(b>11)
					b=b-10;
				while(words[i][t]!='\0'&&words[i][t]<122 && words[i][t]>65){
					check_value=check(arr,words,coor,&a,&b);
					if(check_value==1){
					arr[a][b]=words[i][t];
					coor[i][t][0]=a;
					coor[i][t][1]=b;				
					t++;
					b++;
					a--;
					
					}
					else{
						break;
					}
				}
			}
			else if(direction==7){//right top
				
				if(b<11){
					b=b+9;
				}
				if(a>11)
					a=a-10;
				while(words[i][t]!='\0'&&words[i][t]<122 && words[i][t]>65){
					check_value=check(arr,words,coor,&a,&b);
					if(check_value==1){
					arr[a][b]=words[i][t];
					coor[i][t][0]=a;
					coor[i][t][1]=b;
					t++;
					b--;
					a++;
					}
					else{
						break;
					}
				}
			}
		if(check_value==1){
			i++;
		}
	}
	
	play(arr,words);
}
