// This just plays with a couple of values. See the assembler and include-d files.
int main(){
	int a=13;
	int& b=a;
	/*

	The '-Os' flag (see CMakeLists.txt) will optimize this,
	calculate the value and just return 14:

	.cfi_startproc
	movl	$14, %eax
	ret
	.cfi_endproc

	*/
	b++;
	return b;
}
