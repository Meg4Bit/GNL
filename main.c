
#include <fcntl.h>
#include "get_next_line.h"
#include <stdio.h>

int main()
{
	char *buf;
	int i;

//	int fd = open("42", O_RDONLY);
	i = get_next_line(0,&buf);
	    printf("%d", i);
		    printf("\n%s\n", buf);
			i = get_next_line(0,&buf);
			        printf("%d", i);
					            printf("\n%s\n", buf);
	/*int fd2 = open("43", O_RDONLY);
	i = get_next_line(0,&buf);
	printf("%d", i);
	printf("\n%s\n", buf);
	i = get_next_line(fd, &buf);
		    printf("%d", i);
	    printf("\n%s\n", buf);
		i = get_next_line(fd2, &buf);
			    printf("%d", i);
		    printf("\n%s\n", buf);
			i = get_next_line(fd, &buf);
				    printf("%d", i);
			    printf("\n%s\n", buf);
				i = get_next_line(fd2, &buf);
					    printf("%d", i); 
					 printf("\n%s\n", buf);*/
	return 0;
}
