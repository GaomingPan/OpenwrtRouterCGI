/*
 * util.c
 *
 *  Created on: Nov 19, 2015
 *      Author: GaomingPan
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <time.h>

#include "contents.h"
#include "util.h"
#include "common.h"

int is_session_valid(long int _time)
{
	return (time(NULL) - _time < SESSION_TIME_OUT ? 0 : -1);
}


int is_authority_ok(const char * _user_name, const char * _password)
{
	if((strcmp(user_name, _user_name) == 0) && (strcmp(password, _password)))
		return 0;

	return -1;
}


int set_http_response_header_content_type(const char * type)
{
	memset(http_response_header,0,HTTP_HEADER_LENTH);

	sprintf(http_response_header,
			"Cache-Control: no-cache\r\n" \
			"Connetction: Keep-Alive\r\n" \
			"Content-Type: %s\r\n" \
			"\r\n" \
			"\r\n",
			type
		   );

	return 0;
}

char * get_http_response_header()
{
	return http_response_header;
}


void output_header()
{
	printf("%s",get_http_response_header());
}

int get_file_size(const char *file_name)
{
	struct stat  buffer;
	int          ret;

	ret = stat(file_name, &buffer);

	if(ret)
		return ret;

	return buffer.st_size;
}


void send_direct_to_page(const char * page_name)
{
	printf(DIRECT_PAGES, page_name);
}

