index:
	@if [ -f Log/log.dat ]; then \
		rm Log/log.dat; \
	fi
	gcc -o executavel Arquivos-c/*.c
	clear
	./executavel

Testes:
	@if [ -f Log/log.dat ]; then \
		rm Log/log.dat; \
	fi
	gcc -o executavel Arquivos-c/*.c -g
	./executavel

clear:
	@if [ -f executavel ]; then \
		rm executavel; \
	fi
	@if [ -f Log/log.dat ]; then \
		rm Log/log.dat; \
	fi
	clear