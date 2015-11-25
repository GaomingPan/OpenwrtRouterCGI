/*
 * parse_request.c
 *
 *  Created on: Nov 20, 2015
 *      Author: GaomingPan
 */

#include <stdio.h>
#include <stdlib.h>

#include "util.h"
#include "common.h"
#include "contents.h"
#include "parse_request.h"


static const struct{
	const char *name;
	RequestCode rCode;
}keywords[] = {

		{"page_login", rLogin},
		{"page_status", rStatus},
		{"page_logout", rLogout},
		{"page_error", rBadRequest},

		{"data_status", rdStatus},
		{"data_network", rdNetwork},
		{"data_wireless", rdWireless},
		{"data_admin", rdAdmin},

		{"set_wan", rsWan},
		{"set_lan", rsLan},
		{"set_wireless", rsWireless},
		{"set_admin", rsAdmin},

		{NULL, rInvalid},
};

int parse_pages_request(char * out_data)
{
	return 0;
}

int parse_get_request(char * out_data)
{
	int length = 0;
	char input[MAX_FORM_DATA_LENTH] = {0};
	char *addr = getenv("QUERY_STRING" );

	if (addr){
        fprintf( http_get_data, addr);
        //http_data_decode(input, http_post_data, input + length);
        length = strlen(http_get_data);
//        DEBUG("parse_get_request",http_get_data, length);
        return length;
	}

	return length;
}

int parse_post_request(char * out_data)
{
	char input[MAX_FORM_DATA_LENTH] = {0};
    int length;
    int i;

    char *addr = getenv("CONTENT_LENGTH");

    memset(http_post_data, 0, MAX_FORM_DATA_LENTH);

    if ( addr ){
    	length = atoi(addr);
    	if(length > MAX_FORM_DATA_LENTH)
    		return 0;
    	fgets(http_post_data, length + 1, stdin);
    //	http_data_decode(input, http_post_data, input + length);

//    	DEBUG("parse_post_request",http_post_data,length);

    	//for(i = 0; i < length; i++)
        //	DEBUG(length, http_post_data,http_post_data[i]);
//    	fnsprintf(http_post_data, length + 1,"%s", stdin);
    }else
    	length = 0;

    if(!out_data)
    	out_data = http_post_data;

    return length;
}


int get_post_request_code()
{
	char *ptr1,
	     *ptr2,
		 *ptr3,
		 page_name[64] = {0};

	ptr1 = strstr(http_post_data, HIDDEN_FORM_ID);

//	DEBUG("get_post_request_code_01", http_post_data, (int)ptr1);

	if (!ptr1)
		return rBadRequest;

	ptr2 = strstr(ptr1, "=");

	if (!ptr2)
		return rBadRequest;

	ptr3 = strstr(ptr2, "&");

	if (!ptr3)
		//return rBadRequest;
		snprintf(page_name, MAX_PROPERTY_DARA_SIZE - 1, ++ptr2);
	else
		snprintf(page_name, ptr3 - ptr2, ++ptr2);

//	DEBUG("get_post_request_code_02", page_name, strlen(page_name));

	int i;

	for (i = 0; keywords[i].name; i++)
	     if (strcasecmp(page_name, keywords[i].name) == 0)
	    	 return keywords[i].rCode;

	return rInvalid;

}



