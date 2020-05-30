/*
 * This is all compiled to a simple
 *
 *	movl	$13, %eax
 *	ret
 */
constexpr char adder(char x, char y) { return (x + y); }
int main() {
	const char x=adder(6, 7);
	return x;
}
