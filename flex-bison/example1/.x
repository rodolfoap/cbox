execute(){
	echo [e:start]
	cat input.txt|./app
	echo [e:done]
}
build(){
	echo [b:lex] 'lex example1.l'
	lex example1.l
	echo [b:ls] $(ls -l lex.yy.c)

	echo [b:cc] 'cc lex.yy.c -o app -ll'
	cc lex.yy.c -o app -ll

	echo [b:done]
}
case "$1" in
e)
	vi -p example1.l
	build
	execute
;;
x|execute)
	execute
;;
""|*)
	build
	execute
;;
esac
