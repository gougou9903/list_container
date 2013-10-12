CC=g++

all: print create_build_dir
	$(CC) main.cpp -o product/myList.exe

clean:
	@rm product -f -r

rebuild: clean all

create_build_dir:
	mkdir product

print:
	@echo -------------------------------------------------
	@echo ---                                           ---
	@echo -------------------------------------------------
