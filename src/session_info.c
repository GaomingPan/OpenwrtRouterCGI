/*
 * session_info.c
 *
 *  Created on: Nov 20, 2015
 *      Author: GaomingPan
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "common.h"
#include "contents.h"
#include "util.h"
#include "session_info.h"

int parse_session_file()
{
	char         session[MAX_ARRAY_LENTH] = {0},
			     _time[11] = {0},
	             *ptr1 = NULL,
				 *ptr1_1 = NULL,
				 *ptr2 = NULL;
	int          lenth;
	FILE         *fp;

	lenth = get_file_size(SESSION_CONF_FILE);

	fp = fopen(SESSION_CONF_FILE,"r");

	if(!fp || lenth == -1)
		return -1;

	fread(session, 1, lenth, fp);
	fclose(fp);

	ptr1 = strstr(session, "user:");
	ptr2 = strstr(session, "session:");

	if(!ptr1 || !ptr2)
		return -1;

	ptr1 += 5;
	ptr2 += 8;

	ptr1_1 = strstr(ptr1, ":");

	if(!ptr1_1)
		return -1;

	ptr1_1 += 1;

	snprintf(user_name, ptr1_1 - ptr1, "%s", ptr1);
	snprintf(password, 33, "%s", ptr1_1);
	snprintf(_time, 10, "%s", ptr2);

	last_session_time = atol(_time);

	return 0;
}


int init_session()
{
	return parse_session_file();
}


char * get_user_name()
{

	return user_name;
}


char * get_password()
{
	return password;
}


long get_last_session_time()
{
	return last_session_time;
}


int save_session_info(char * _user_name, char * _password)
{
	DEBUG("save_session user_name",_user_name,01);
	DEBUG("save_session password",_password,02);

	FILE *fp;
	char session[128] = {0};

	if( !_user_name || !_password)
		sprintf(session, "user:%s:%s\nsession:%ld\n", user_name, password, time(NULL));
	else if(_user_name && _password)
		sprintf(session, "user:%s:%s\nsession:%ld\n", _user_name, _password, time(NULL));

	DEBUG("save_session","step 1", 1);
	fp = fopen(SESSION_CONF_FILE, "w");
	if(!fp)
		return -1;
	DEBUG("save_session","step 2", 2);
	fwrite(session, 1, strlen(session), fp);
	fclose(fp);

	return 0;
}


int clean_session()
{
	FILE *fp;
	char session[128] = {0};
	sprintf(session, "user:%s:%s\nsession:%ld\n", user_name, password, 0);

	fp = fopen(SESSION_CONF_FILE, "w");
	if(!fp)
		return -1;

	fwrite(session, 1, strlen(session), fp);
	fclose(fp);

	return 0;
}



