index:
	@if [ ! -d Log ]; then \
		mkdir Log; \
	fi
	@if [ -f Log/log.dat ]; then \
		rm Log/log.dat; \
	fi
	gcc -o executavel Arquivos-c/*.c
	clear
	./executavel

Testes:
	@if [ ! -d Log ]; then \
		mkdir Log; \
	fi
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
	@if [ -d Log ]; then \
		rmdir Log; \
	fi
	clear
