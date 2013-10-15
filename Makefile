CC=g++

all: clean print create_build_dir
	$(CC) main.cpp -o product/myList.exe

clean:
	@echo -------------------------------------------------
	@echo ---           Cleaning /product/ dir          ---
	@echo -------------------------------------------------
	@rm product -f -r

rebuild: clean all

create_build_dir:
	mkdir product

print:
	@echo -------------------------------------------------
	@echo ---  Building list by github.com/SergNikitin/ ---
	@echo -------------------------------------------------
