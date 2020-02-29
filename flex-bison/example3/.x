execute(){
	echo [e:input] ==========================
	cat input.txt
	echo [e:process] ==========================
	cat input.txt|./app
	echo [e:done]
}
build(){
	echo [b:lex] 'lex tokens.l'
	lex tokens.l
	echo [b:ls] $(ls -l lex.yy.c)

	echo [b:yacc] 'lex tokens.l'
	yacc -d parser.y

	echo [b:cc] 'cc lex.yy.c y.tab.c -o app'
	cc lex.yy.c y.tab.c -o app

	echo [b:done]
}
case "$1" in
e)
	vi -p tokens.l parser.y
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

