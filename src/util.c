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
	if (time(NULL) - _time > SESSION_TIME_OUT)
		return  -1;

	return 0;
}


int is_authority_ok(char * _user_name, char * _password)
{
	if((strcmp(user_name, _user_name) == 0) && (strcmp(password, _password)))
		return 0;

	return -1;
}


int set_http_response_header_content_type(char * type)
{
	memset(http_response_header,0,HTTP_HEADER_LENTH);

	sprintf(http_response_header,
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
	fprintf(stdout, "%s",get_http_response_header());
}

void output_header_v(char * type)
{
	set_http_response_header_content_type(type);
	fprintf(stdout, "%s",get_http_response_header());
}

int get_file_size(char *file_name)
{
	struct stat  buffer;
	int          ret;

	ret = stat(file_name, &buffer);

	if(ret)
		return ret;

	return buffer.st_size;
}


int get_http_data_size()
{
	char *len_addr = getenv("CONTENT_LENGTH");

	//DEBUG(len_addr, "getenv");

	if(NULL == len_addr)
		return -1;

	return atoi(len_addr);
}

void send_redirect_to_page(char * page_name)
{
	fprintf(stdout, REDIRECT_PAGES, page_name);
}


void http_data_decode(char *src, char *dest, char *last)
{
	char code;

	for(; src != last; src++, dest++)
		if(*src == '+')
			*dest = ' ';
		else if(*src == '%'){
			if(sscanf(src + 1, "%2x", &code) != 1)
				*dest = code;
			src += 2;
		}else{
			*dest = *src;
			*dest = ' ';
			*++dest = 0;
		}
}


char * get_http_post_data()
{
	return http_post_data;
}


char * get_http_get_data()
{
	return http_get_data;
}


char * get_post_data_property(char * property)
{
//	DEBUG("get_post_data_property00",property,strlen(property));
//	DEBUG("get_post_data_property00-00",http_post_data,strlen(http_post_data));
	char *ptr1,
	     *ptr2,
		 *ptr3,
		 *data;
	data = get_http_post_data();

	ptr1 = strstr(data, property);

//	DEBUG("get_post_data_property11",data,strlen(data));
//
//	DEBUG("get_post_data_property","ptr1",(int)ptr1);

	if (!ptr1)
		return NULL;

	ptr2 = strstr(ptr1, "=");

//	DEBUG("get_post_data_property","ptr2",(int)ptr2);
	if (!ptr2)
		return NULL;

	ptr3 = strstr(ptr2, "&");


//	DEBUG("get_post_data_property","ptr3",(int)ptr3);

	if(!ptr3)
		snprintf(property_data, MAX_PROPERTY_DARA_SIZE - 1, ++ptr2);
	else
		snprintf(property_data, ptr3 - ptr2, ++ptr2);

//	DEBUG("get_post_data_property",property_data, strlen(property_data));
	return property_data;
}

char * get_get_data_property(char * property)
{
	char *ptr1,
	     *ptr2,
		 *ptr3;
	ptr1 = strstr(http_get_data, property);

	if (!ptr1)
	     ptr2 = strstr(ptr1, "=");
	else
		return NULL;

	if (!ptr2)
	     ptr3 = strstr(ptr2, "&");
	else
		return NULL;

	if(!ptr3)
		snprintf(property_data, ptr3 - ptr2, ++ptr2);
	else
		snprintf(property_data, MAX_PROPERTY_DARA_SIZE - 1, ++ptr2);

	DEBUG("get_get_data_property",property_data, strlen(property_data));
	return property_data;
}

