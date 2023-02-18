CFLAGS=-g -O3

all: uimain

history.o: history.h
tokenizer.o: tokenizer.h

uimain: history.o tokenizer.o uimain.o

	cc -o $@ $^ $(CFLAGS)

clean:

	rm -f *.o uimain

run: uimain
	./uimain
