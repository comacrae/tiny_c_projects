#include <stdio.h>
#include <time.h>

int main(int argv, char * argc[])
{
	time_t now;
	struct tm * clock;
	char time_str[64];

	time(&now);
	clock = localtime(&now);
	strftime(time_str,64,"Today is %A, %B %d, %Y\nIt is %r%n", clock);

	printf("Greetings");
	
	if(argv > 1)
		printf(", %s!\n", argc[1]);

	printf("%s", time_str);
	
	return 0;
}
