#include "debug_utils.h"

#define FINE_LEVEL 1
#define INFO_LEVEL 2
#define WARN_LEVEL 3
#define ERROR_LEVEL 5
#define ALL_LEVEL 10
#define NONE_LEVEL 0

#include <stdio.h>
#include <stdarg.h>

char * WARN_TAG = "WARN";
char * INFO_TAG = "INFO";
char * FINE_TAG = "FINE";
char * ERROR_TAG = "++ERROR++";

int DEBUG_LEVEL = 0;

void set_debug_level(int new_level)
{
	DEBUG_LEVEL = new_level;
	print_msg("NEWS", "new DEBUG_LEVEL = %d", DEBUG_LEVEL );
}

int get_debug_level()
{
	print_msg("NEWS", "current DEBUG_LEVEL = %d", DEBUG_LEVEL );
	return DEBUG_LEVEL;
}

void print_msg_private( char * tag, char* msg, va_list args ) {
    fprintf(stdout, "[%s] ", tag );
    vprintf( msg, args );
    fprintf(stdout, "\n");
}

void print_msg(char * tag, char * msg, ...)
{
    va_list vargs;
	va_start(vargs, msg);
	print_msg_private(tag,msg,vargs);
	va_end( vargs );
}

void print_info(char * msg, ...)
{
	if(DEBUG_LEVEL<=INFO_LEVEL)
	{
		va_list vargs;
		va_start(vargs, msg);
		print_msg_private(INFO_TAG,msg,vargs);
		va_end( vargs );
	}
}

void print_warning(char * msg, ...)
{
	if(DEBUG_LEVEL<=WARN_LEVEL)
	{
		va_list vargs;
		va_start(vargs, msg);
		print_msg_private(WARN_TAG, msg, vargs);
		va_end( vargs );
	}
}


void print_fine(char * msg, ...)
{
	if(DEBUG_LEVEL<=FINE_LEVEL)
	{
		va_list vargs;
		va_start(vargs, msg);
		print_msg_private(FINE_TAG, msg, vargs);
		va_end( vargs );
	}
}

void print_error(char * msg, ...)
{
	if(DEBUG_LEVEL<=ERROR_LEVEL)
	{
		va_list vargs;
		va_start(vargs, msg);
		print_msg_private(ERROR_TAG, msg, vargs);
		va_end( vargs );
	}
}