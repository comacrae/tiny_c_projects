#include <stdio.h>
#include <time.h>

int moon_phase(int day, int month, int year);

int main(int argv, char * argc[])
{
	time_t now;
	struct tm * clock;
	char time_str[64];
	char* phase[8] = {
	"waxing crescent", "at first quarter",
	"waxing gibbous", "full", "waning gibbous",
	"at last quarter", "waning crescent", "new"
	};

	time(&now);
	clock = localtime(&now);
	strftime(time_str,64,"Today is %A, %B %d, %Y\nIt is %r%n", clock);

	printf("Greetings");
	
	if(argv > 1)
		printf(", %s!\n", argc[1]);

	printf("%s", time_str);
	printf("The moon's phase is: %s\n", phase[moon_phase(clock->tm_mday, clock->tm_mon, clock->tm_year)]);
	
	return 0;
}

int moon_phase(int day, int month, int year){
	int d,g,e;	

	d = day;

	if(month == 2)
		day +=31;
	else if(month > 2)
		d += 59+(month-3)*30.6+0.5;
	g = (year-1900)%19;
	e = (11*g + 29) % 30;
	if(e == 25 || e == 24)
		++e;
	return ((((e+d)*6+5)%177)/22 & 7);

}
