CXX = clang++
CC = clang

main:	main

test: main
	./main

clean:
	rm -f *.o main
