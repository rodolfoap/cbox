/*
 * This is all compiled to a simple
 *
 *	movl	$13, %eax
 *	ret
 */
inline int regression(int x) { return (9*x+7); }
int main(int argc, char** argv) {
	int y=regression(argc);
	return y;
}
