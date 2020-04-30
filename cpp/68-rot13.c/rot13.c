#include <stdio.h>
#include <unistd.h>

char rot13(char c) {
	return isalpha(c)?tolower(c)<'n'?c+13:c-13:c;
}

int main(){
	char c, t[4096];
	int n=0;

	while(read(STDIN_FILENO, &c, 1)>0) t[n++]=c; t[n]=0;

	for(int i=0; t[i]!=0; i++){ t[i]=rot13(t[i]); }
	printf("%s", t);

	return 0;
}
