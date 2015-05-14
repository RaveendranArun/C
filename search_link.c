#include<stdio.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<unistd.h>
main(int argc,char **argv)
{
	if(argc!=3)
	{
		printf("usage: ./a.out file_name file_name\n");
		return;
	}
	struct stat v1,v2;
	stat(argv[1],&v1);
	stat(argv[2],&v2);
	if(v1.st_ino==v2.st_ino)
	{
		lstat(argv[1],&v1);
		lstat(argv[2],&v2);
		if(v1.st_ino==v2.st_ino)
		{
			printf("hard link\n");
		}
		else
		{
			printf("soft link\n");
		}
	}
	else
	{
		printf("there is no link between the files\n");
	}
}	
