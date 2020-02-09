#include<stdio.h>
#include<string.h>

class Teacher{
// Members are private by default
	char name[10];
	int age;
	float value;
public:
	Teacher(char *anaddress, int anage, float avalue) :age(anage), value(avalue){ strcpy(name, anaddress); }
};

struct Student{
// Members are public by default
	char name[10];
	int age;
	float value;
};

int main(){
	char c[]="RodolfoAP";
	Student s;
	Teacher t(c, 5, 5);
	FILE *file;
	file=fopen("freadwrt.dat", "w+");
	//clrscr();

	strcpy(s.name, "RodolfoAP"); s.age=65; s.value=6.9;
	fwrite(&s, sizeof(s), 1, file);

	strcpy(s.name, "PatriciaP"); s.age=55; s.value=7.3;
	fwrite(&s, sizeof(s), 1, file);

	fclose(file);

	file=fopen("freadwrt.dat", "r");
	while(fread(&s, sizeof(s), 1, file)==1) {
		printf("Register: %s\t%d\t%.1f\n", s.name, s.age, s.value);
	}
	fclose(file);

	return 0;
}
