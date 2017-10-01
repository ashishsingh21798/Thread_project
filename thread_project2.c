#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <math.h>
#include <string.h>
#include <fcntl.h>
#include <stdbool.h>

#define size_buf 500000

char keyword[20];

int s;
char buffer[size_buf];

struct buff_data
{

	int start;
	int end; 
};
  


void * search_key(void * b1)
{
	printf("thread created\n");
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

	printf("size of b= %d\n",sizeof(b1));
	sleep(1);
	s=(*b1).start;
	printf("s= %d\n", s);
	sleep(2);
	while(count)
    {
		count=read(fd,&ch,1);

		if(ch==' ' || ch=='\n') 
		{
			w++;
		}
		buffer[i]=ch;	
		printf("w= %d\n",w);
    	no_of_pth=(int)ceil((double)w/100);
    	printf("start %d\n",(*b1).start);
    	pthread_t tid[no_of_pth];

		if(w==j*100)
		{
			(*b1).end=i;
			printf("end %d\n", (*b1).end);
			int p;
	   		p=pthread_create(&tid[j],NULL,&search_key,(void *)b1);
	   		sleep(5);
	   		/*if(p==0)
	   		{
	   			printf("thread created\n");
	   		}*/
	   		(*b1).start = (*b1).end;
	   		i++;
	   		j++;
	   		(*b1).start++;
		}
		else
		{
			i++;
			
		}
   
   }
    //printf("final end %d\n", (*b1).end);
	printf("word=%d\n",w);
	return 0;
}