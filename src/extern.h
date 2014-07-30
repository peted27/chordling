
#ifndef EXTERN_H
#define EXTERN_H

#ifdef DEBUG
#define TRACE(msg, arg) do { fprintf(stderr, msg, arg); } while (0);
#else
#define TRACE(msg, arg)
#endif

typedef enum truefalse
{
	FALSE, TRUE
} BOOLEAN;

/* global buffer length, to keep things simple */
#define BUFFER_LENGTH 512

BOOLEAN process_file(char *filename);
void ps_init_function_pointer();


#endif /* EXTERN_H */
