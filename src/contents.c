/*
 * contents.c
 *
 *  Created on: Nov 23, 2015
 *      Author: GaomingPan
 */

#include "common.h"
#include "contents.h"

char user_name[30];

char password[33];

long last_session_time = 0;

char  http_response_header[HTTP_HEADER_LENTH];

char  http_post_data[MAX_FORM_DATA_LENTH];

char  http_get_data[MAX_FORM_DATA_LENTH];

char  property_data[MAX_PROPERTY_DARA_SIZE];

char  buffers[MAX_ARRAY_LENTH];

