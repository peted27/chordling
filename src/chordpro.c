#include "extern.h"

#include <stdio.h>
#include <string.h>


void read_rest_of_line(void);
void terminate_buffer(char *buffer);

BOOLEAN process_file(char *filename)
{
	/* file parsing */
	FILE *fp;
	char c;
	BOOLEAN parsing_status = TRUE;
	int line_count = 0;

	/* temporary buffers */
	char lin_buffer[BUFFER_LENGTH];
	char chd_buffer[BUFFER_LENGTH];
	char lyr_buffer[BUFFER_LENGTH];
	char dir_buffer[BUFFER_LENGTH];
	char arg_buffer[BUFFER_LENGTH];

	/* buffer indexes */
	int lin_buf_index = 0;
	int chd_buf_index = 0;
	int lyr_buf_index = 0;
	int dir_buf_index = 0;
	int arg_buf_index = 0;

	/* in section bools */
	BOOLEAN in_chord = FALSE;
	BOOLEAN in_tab = FALSE;
	BOOLEAN in_comment = FALSE;
	BOOLEAN in_directive = FALSE;
	BOOLEAN in_directive_arg = FALSE;


	TRACE("Opening file: %s\n", filename);
	fp = fopen(filename, "r");

	/* file couldnt be opened */
	if (fp == NULL)
	{
		fprintf(stderr, "Error! Could not open %s for reading.\n", filename);
		return FALSE;
	}
	
	/* loop over all lines in the file */
	while ((c = fgetc(fp)) != EOF && parsing_status)
	{

		switch (c)
		{
		case '{':
			if (in_directive)
			{
				fprintf(stderr, "Error, in %s at line %d. Already in directive\n", filename, line_count);
			}
			else
			{
				in_directive = TRUE;
			}
			break;


		case '}':
			in_directive = FALSE;
			in_directive_arg = FALSE;
			/* process directive */
			break;

		case ':':
			if (in_directive)
			{
				in_directive_arg = TRUE;
			}
			else
			{
				
			}
			break;


		case '[':
			if (in_chord)
			{
				fprintf(stderr, "Error, in %s at line %d. Already in chord\n", filename, line_count);
			}
			else
			{
				in_chord = TRUE;
				chd_buf_index = 0;
			}
			break;


		case ']':
			if (!in_chord)
			{
			}
			else
			{
				in_chord = FALSE;
			}
			/* process chord */
			break;


		case '#':
			in_comment = TRUE;
			break;


		case '\n':
		case '\r':
			line_count++;
			/* process line */
			break;
		default:
			if (in_chord)
			{
				chd_buffer[chd_buf_index++] = c;
			}
			else if (in_directive_arg)
			{
			}
			else if (in_directive)
			{
			}
			else if (in_tab)
			{
			}
			else
			{
			}

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


