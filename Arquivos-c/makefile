index:
	@if [ -f Log/log.dat ]; then \
		rm Log/log.dat; \
	fi
	gcc -o executavel *.c
	clear
	./executavel

Testes:
	@if [ -f Log/log.dat ]; then \
		rm Log/log.dat; \
	fi
	gcc -o executavel *.c -g
	./executavel

clear:
	@if [ -f executavel ]; then \
		rm executavel; \
	fi
	@if [ -f Log/log.dat ]; then \
		rm Log/log.dat; \
	fi
	clear