#include <stdio.h>
#include <time.h>

int main(int argc, char * argch[]){
	time_t now;
	time(&now);
	struct tm * clock;
	clock = localtime(&now);
	
	int * ptr = (int*)&clock;
	char* strs[] = {
		"Day of the year: ",
		"Day of the week: ",
		"           Year: ",
		"          Month: ",
		"   Day of month: ",
		"           Hour: ",
		"         Minute: ",
		"         Second: "
	};


	for(int i = 0; i < 8; i++){
		printf("%s %d\n",strs[i],(*ptr++));
	}

	printf("%d\n",clock->tm_yday);
	return 0;
}
