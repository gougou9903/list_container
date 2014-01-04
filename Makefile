CC=g++

all: clean print create_build_dir
	$(CC) main.cpp exception.cpp -o product/myList.exe
	$(CC) api_test.cpp exception.cpp -o product/tester.exe

clean:
	@echo -------------------------------------------------
	@echo ---           Cleaning /product/ dir          ---
	@echo -------------------------------------------------
	@echo
	@rm product -f -r

rebuild: clean all

create_build_dir:
	mkdir product

print:
	@echo -------------------------------------------------
	@echo ---  Building list by github.com/SergNikitin/ ---
	@echo -------------------------------------------------
