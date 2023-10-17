#include <stdio.h>
#include <time.h>

int main(int argc, char* argv[])
{
	time_t now;
	struct tm *clock;
	int hour;

	time(&now); //get current time
	clock = localtime(&now);
	hour = clock -> tm_hour;
	printf("%d\n",hour);

	printf("Good");
	
	if(hour < 12)
		printf(" morning");	
	else if (hour < 17)
		printf(" afternoon");
	else
		printf(" evening");

	if(argc > 1)
		printf(", %s", argv[1]);
	
	putchar('\n');
	
	return 0;
}
