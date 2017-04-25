# I am a comment, and I want to say that the variable CC will be
# the compiler to use.
CC=g++
# Hey!, I am comment number 2. I want to say that CFLAGS will be the
# options I'll pass to the compiler.
#LIBS=-I$(CPT_PATH) -L$(CPT_PATH) -lcpt


all: numalg_tests root_finding simple_root_finding

numalg_tests: numalg_tests.cpp
	$(CC) $^ -o numalg_tests

root_finding: root_finding.cpp
	$(CC) $^ -o root_finding

simple_root_finding: simple_root_finding.cpp
	$(CC) $^ -o simple_root_finding

clean:
	rm -rf *o numalg_tests root_finding simple_root_finding
