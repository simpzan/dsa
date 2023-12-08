all: circular_buffer_tests
	./circular_buffer_tests

circular_buffer_tests: circular_buffer_tests.c circular_buffer.c
	gcc -o circular_buffer_tests circular_buffer_tests.c circular_buffer.c
