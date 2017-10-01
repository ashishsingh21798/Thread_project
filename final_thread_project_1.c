#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <math.h>
#include <string.h>
#include <fcntl.h>
//#include <stdbool.h>

#define size_buf 500000

char keyword[20],buffer[size_buf];
int s; 
//int boolean=0;

struct buff_data
{

	int start;
	int end; 
};  

void * search_key(void * b1)
{
	//printf("thread created\n");		

	struct buff_data *b=(struct buff_data *)b1;

	int i,count=0;
	int j=(*b).start;
	int buff_len,key_len;

	key_len=strlen(keyword);

	for(i=0;i<key_len;i++)
	{
		while( j<(*b).end )
		{ 		
			if( keyword[i] == buffer[j] )
			{
				count++;
				j++;
				break;
			}
			else
			{        
				j++;
				i=0;
				count=0;
			}
		}
	}

	if(count==key_len)
	{
		printf("yoo!!..word found...\n");
		//boolean=1;
	}
	else
	{
		printf("not found...\n");
	}
}

int main(int agrc,char *argv[])
{

	int fd,w=0,j=1,i=0,count=1;
	char ch;
	int no_of_pth;

	struct buff_data *b1;
	b1 = (struct buff_data *)malloc(sizeof(struct buff_data));
	(*b1).start=0;

	printf("Enter keyword to search\n");
	scanf("%s",&keyword);

	fd=open("/home/ashish/project2/ashish.txt",O_RDWR);
	s=(*b1).start;

	while(count)
	{

		count = read( fd, &ch, 1 );

		if(ch==' ' || ch=='\n') 
		{
			w++;
		}

		buffer[i]=ch;	
		no_of_pth=(int)ceil((double)w/100);
		pthread_t tid[no_of_pth];

		if(w==j*100)
		{
			
			(*b1).end=i;
			int p;
			
			p=pthread_create(&tid[j],NULL,&search_key,(void *)b1);
			sleep(1);
			
			(*b1).start = (*b1).end;
			i++;
			j++;
			(*b1).start++;
		}
		else
		{
			i++;

		}
		/*if(boolean==1){
			int g;
			for(g=0;g<no_of_pth;g++){
			pthread_join(tid[g],NULL);
		}
		}*/

	}

	return 0;
}
