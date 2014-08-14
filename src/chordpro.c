#include "extern.h"

#include <stdio.h>
#include <string.h>



BOOLEAN process_file(char *filename)
{
	/* file parsing */
	FILE *fp;

	BOOLEAN parsing_status = TRUE;
	int line_count = 0;

	/* temporary buffers */
	char lin_buffer[BUFFER_LENGTH];
	char chd_buffer[BUFFER_LENGTH];
	char lyr_buffer[BUFFER_LENGTH];
	char dir_buffer[BUFFER_LENGTH];
	char arg_buffer[BUFFER_LENGTH];

	/* buffer indexes */
	char lin_ch;
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
	while (fgets(lin_buffer, BUFFER_LENGTH, fp) != NULL && parsing_status)
	{
		

		/* handle some known cases before we move on to processing chords/lyrics */
		switch (lin_buffer[0])
		{
		case '#':
			break;
		case '{':
			break;
		default:
			break;
		}

		/* just a normal line, lets get cracking */
		for (lin_buf_index = 0; lin_buf_index < strlen(lin_buffer); lin_buf_index++)
		{
			lin_ch = lin_buffer[lin_buf_index];
			
			if (lin_ch == '[' && !in_chord)
			{
				in_chord == TRUE;
			}
			else if (lin_ch == '[' && in_chord)
			{
				/* error */
			}
			else if (lin_ch == ']' && in_chord)
			{
				in_chord == FALSE;
			}
			else if (lin_ch == ']' && !in_chord)
			{
				/* error */
			}
			else if (in_chord)
			{
				
			}
			else
			{
				
			}
			
		}
		
	}
	
	fclose(fp);

	return (parsing_status);
	
}
