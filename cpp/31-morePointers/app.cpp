#include<iostream>
/*

+-----------+
|           |
|   Heap    |
|           |
+-----------+
|           |
|   Stack   |
|           |
+-----------+
|           |
|  Static/  |
|  Global   |
|           |
+-----------+
|           |
| Code/Text |
|           |
+-----------+

*/
int main(){
	/* Memorize: AN ARRAY IS AN ADDRESS */

	int i=22;		// Goes to the stack
	char c[]="text";	// Goes to the stack
	const char *p="char";	// p goes to the stack, "char" goes to the CODE segment (Read-Only)
	std::cout<<std::endl;

	// &i and i are different: &i is an address, i is the content.
	printf("&i=%d, i:%d, i:%d\n", &i, i, i);
	// &i=1685897468, i:22, 	i:22

	// &c == &c[0] == c; all are identic: all are AN ADDRESS.
	// c cannot be the content: on strings, c points to the start,
	// but the end is defined by \0.
	printf("&c=%d, c:%d, c:%d, c:%s\n", &c, &c[0], c, c);
	// &c=1685897463, c:1685897463,	c:1685897463, c:1685897463, c:text

	// &p is an address; p is also an address (but different, in the CODE segment).
	printf("&p=%d, p:%d, p:%s\n", &p, p, p);
	// &p=1685897448, p:253079557, 	p:char

	std::cout<<std::endl;
	return 0;
}



