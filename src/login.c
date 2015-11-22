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

}
