	.file	"app.cpp"
	.text
	.p2align 4,,15
	.globl	_Z10regressioni
	.type	_Z10regressioni, @function
_Z10regressioni:
.LFB0:
	.cfi_startproc
	leal	7(%rdi,%rdi,8),	%eax
	ret
	.cfi_endproc
.LFE0:
	.size _Z10regressioni, .-_Z10regressioni
	.section	.text.startup,"ax",@progbits
	.p2align 4,,15
	.globl	main
	.type	main, @function
main:
.LFB1:
	.cfi_startproc
	leal	7(%rdi,%rdi,8), %eax
	ret
	.cfi_endproc
.LFE1:
	.size	main, .-main
	.ident	"GCC: (Debian 8.3.0-6) 8.3.0"
	.section	.note.GNU-stack,"",@progbits
