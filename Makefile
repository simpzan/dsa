all: circular_buffer_tests
	./circular_buffer_tests

circular_buffer_tests: circular_buffer_tests.c circular_buffer.c circular_buffer.h
	gcc -o circular_buffer_tests circular_buffer_tests.c circular_buffer.c

clean:
	rm -rf circular_buffer_tests
