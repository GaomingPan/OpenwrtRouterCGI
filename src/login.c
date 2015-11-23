/*
 * login.c
 *
 *  Created on: Nov 21, 2015
 *      Author: GaomingPan
 */

#include <stdio.h>
#include <stdlib.h>

#include "common.h"
#include "contents.h"
#include "util.h"
#include "md5.h"

#include "login.h"




void login_page()
{
	set_http_response_header_content_type("text/html;charset=utf-8");
	output_header();

    if(0 != init_session()){
    	printf("init_session ERROR !\n");
    	return;
    }

    send_redirect_to_page(PAGE_LOGIN);

}

int login_status()
{
	set_http_response_header_content_type("text/html;charset=utf-8");
	output_header();
	fprintf(stdout, "form_data: %s", http_post_data);

	return 0;
}


int do_login_process()
{
//	DEBUG("do_login_process", "0", 0);
	char user_name[MAX_PROPERTY_DARA_SIZE],
	     password[MAX_PROPERTY_DARA_SIZE];

	unsigned char decrypt[16];

    MD5_CTX   md5;
    int       i;
//    DEBUG("do_login_process", "1", 1);
//    DEBUG("do_login_process--data", http_post_data, 1);

	sprintf(user_name, "%s", get_post_data_property("user_name"));
//	DEBUG("do_login_process", "2", 2);
	sprintf(password, "%s", get_post_data_property("password"));

//	DEBUG("do_login_process_01", user_name, 0);
//	DEBUG("do_login_process_02", password, 2);

	MD5Init(&md5);
    MD5Update(&md5,password,strlen((char *)password));
    MD5Final(&md5,decrypt);

    memset(password, 0, MAX_PROPERTY_DARA_SIZE);
    for(i=0;i<16;i++)
        sprintf(password,"%s%02x", password, decrypt[i]);

//    DEBUG("do_login_process_03", password, 3);

    if(is_authority_ok(user_name, password) < 0)
    	return -1;

    save_session_info(NULL, NULL);

//    DEBUG("md5 password", password, 007);

	return 0;
}



