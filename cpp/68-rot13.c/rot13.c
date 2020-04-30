#include <stdio.h>
#include <unistd.h>

void rot13(char* t) {
	for(int i=0; t[i]!=0; i++){
		if(t[i]>='a'&&t[i]<='z') t[i]=(((t[i]-'a')+13)%26)+'a';
		if(t[i]>='A'&&t[i]<='Z') t[i]=(((t[i]-'A')+13)%26)+'A';
	}
}

int main(){
	char c, t[4096];
	int n=0;

	while(read(STDIN_FILENO, &c, 1)>0) t[n++]=c; t[n]=0;

	rot13(t);
	printf("%s", t);

	return 0;
}
