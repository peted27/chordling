TARGET = chordling
OBJS = chordpro.o postscript.o
DEPS = extern.h

CC = gcc
DEBUG = -DDEBUG -g
CFLAGS = -pedantic -Wall -ansi
LFLAGS = -Wall

$(TARGET): $(OBJS)
	$(CC) -c -o $@.o $@.c
	$(CC) -o $@ $@.o $(OBJS)

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

debug: CFLAGS += $(DEBUG)
debug: LFLAGS += $(DEBUG)
debug: $(TARGET)

.PHONY: indent
indent:
	-astyle --style=bsd --align-pointer=name --max-code-length=75 \
	--max-instatement-indent=60 *.c *.h
	-rm -f *.orig


.PHONY: clean
clean:
	-rm -f *.o
	-rm -f $(TARGET) $(TARGET).exe
