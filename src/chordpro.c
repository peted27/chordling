#include "extern.h"

#include <stdio.h>
#include <string.h>


void read_rest_of_line(void);
void terminate_buffer(char *buffer);

BOOLEAN process_file(char *filename)
{
	FILE *fp;
	char buffer[BUFFER_LENGTH];
	char chord_buffer[BUFFER_LENGTH];
	char lyric_buffer[BUFFER_LENGTH];

	BOOLEAN parsing_status = TRUE;
	int line_count = 0;

	TRACE("Opening file: %s\n", filename);
	
	/* */
	fp = fopen(filename, "r");

	/* file couldnt be opened */
	if (fp == NULL)
	{
		fprintf(stderr, "Error! Could not open %s for reading.\n", filename);
		return FALSE;
	}
	
	/* loop over all lines in the file */
	while (fgets(buffer, BUFFER_LENGTH, fp) != NULL && parsing_status)
	{
		line_count++;

		TRACE("line: %d .. ", line_count);
		
		terminate_buffer(buffer);

		TRACE("%s\n", buffer);

		chord_buffer[0] = '\0';
		lyric_buffer[0] = '\0';
		
		/* do something with line */
		switch(buffer[0])
		{
		case '#':
			break;
		case '{':
			break;
		default:
			break;

		}

		
	}
	
	return (parsing_status);
	
}

void read_rest_of_line(void)
{
	int ch;
	while (ch = getc(stdin), ch != EOF && ch != '\n') ;
	clearerr(stdin);
}

void terminate_buffer(char *buffer)
{
	buffer[BUFFER_LENGTH - 1] = '\0';

	/* remove new line from buffer */
	if (buffer[strlen(buffer) - 1] == '\n')
	{
		buffer[strlen(buffer) - 1] = '\0';
	}
	
}


