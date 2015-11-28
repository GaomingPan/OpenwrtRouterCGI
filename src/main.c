/*
 * main.c
 *
 *  Created on: Nov 19, 2015
 *      Author: GaomingPan
 */


#include <stdio.h>
#include <stdlib.h>
#include "common.h"
#include "util.h"
#include "md5.h"
#include "session_info.h"
#include "login.h"
#include "do_process.h"


static int http_post_data_length,
	       http_get_data_length,
		   request_code;

static long _time;


static int do_invalid_session()
{
    	request_code = get_post_request_code();
    	DEBUG("session is invalid", "RequestCode", request_code);

    	switch(request_code){
    	case rLogin:
//    		DEBUG("switch", "rLogin", rLogin);
    		output_header_v("text/html;charset=utf-8");
    		if ( 0 != do_login_process()){
    			send_redirect_to_page(PAGE_AUTH_ERR);
    			return 0;
    		}
    		send_redirect_to_page(PAGE_STATUS);
    		break;
        case rdNetwork:
        	output_header_v("application/json");
        	return 0;
        	break;
        case rdWireless:
        	output_header_v("application/json");
        	return 0;
        	break;
        case rsWan:
        	output_header_v("application/json");
        	return 0;
        	break;
        case rsLan:
        	output_header_v("application/json");
        	return 0;
        	break;
        case rsWireless:
        	output_header_v("application/json");
        	return 0;
        	break;
    	default:
    		output_header_v("text/html;charset=utf-8");
    		send_redirect_to_page(PAGE_LOGIN);
    		break;
    	}
//    	DEBUG("main", "RequestCode", request_code);
    	return 0;
}



static int do_valid_session()
{
    request_code = get_post_request_code();
    DEBUG("session is valid", "RequestCode", request_code);
    switch(request_code){
    case rLogin:
    	output_header_v("text/html;charset=utf-8");
    	fprintf(stdout, "%s", "<hr><center><br><h1>Login Valid ! Hello world.</h1></center>");
    	return 0;
    	break;
    case rLogout:
    	output_header_v("application/json");
//    	DEBUG("Logout","rLogout",rLogout);
    	do_logout();
    	return 0;
    	break;

    case rdStatus:
    	output_header_v("application/json");
    	fprintf(stdout, "%s", get_status_data());
    	save_session_info(NULL, NULL);
//    	DEBUG("buffers data",get_buffers_data(),0);
    	return 0;
    	break;
    case rdNetwork:
    	output_header_v("application/json");
    	fprintf(stdout, "%s", get_network_data());
    	DEBUG("network-data",get_network_data(),0);
    	return 0;
    	break;
    case rdWireless:
    	output_header_v("application/json");
    	fprintf(stdout, "%s", get_wireless_data());
    	DEBUG("wireless-data",get_wireless_data(),0);
    	return 0;
    	break;
    case rsWan:
    	output_header_v("application/json");
    	do_network_settings(rsWan);
    	return 0;
    	break;
    case rsLan:
    	output_header_v("application/json");
    	do_network_settings(rsLan);
    	return 0;
    	break;
    case rsWireless:
    	output_header_v("application/json");
    	do_wireless_settings();
    	return 0;
    	break;
    default:
    	output_header_v("text/html;charset=utf-8");
    	send_redirect_to_page(PAGE_STATUS);
    	break;
    }

	return 0;
}




int main(int argc, char *argv[])
{

	if(0 != init_session())
		send_redirect_to_page(PAGE_INDEX);

	_time = get_last_session_time();
    http_get_data_length = parse_get_request(NULL);
    http_post_data_length = parse_post_request(NULL);

    DEBUG("post-data:",get_http_post_data(),0);
    if ( is_session_valid(_time) < 0 )
    	return do_invalid_session();

    return do_valid_session();
}




/*
	 char *lenstr;

	 char input[MAXINPUT], data[MAXINPUT];

	 long len;

	 login_status();
	 int i = 0;
	 for(;i<argc;i++)
		 printf("<p>argv[%d]: %s", i, argv[i]);

	 printf("<TITLE>Response</TITLE> ");

	 lenstr = getenv("CONTENT_LENGTH");

	 if(lenstr == NULL || sscanf(lenstr,"%ld",&len)!=1 || len > MAXLEN)

	 printf("<p>form data error,len = %ld.", len);

	 else {

	 fgets(input, len+1, stdin);

	 http_data_decode(input+EXTRA, input+len, data);

	 printf("<p>form data is: <br>%s",data);

	 }

	 return 0;

	//printf("%s%c%c%c%c","Content-Type:text/html;charset=utf-8", '\r', '\n', '\r', '\n');
*/


	// login_status();
	// fprintf(stdout,"<br>parse_post_request return code: %d<br>", parse_post_request(NULL));
	// request_code = get_request_code();
	// login_status();
//	 printf("<hr><br>request_code: %d<br><hr>",request_code);
/*
	 switch(request_code){
	 case rLogin:
		 if(!is_session_valid(_time)){
			 login_status();
			  return 0;
		 }
		 break;
	 case rBadRequest:
		 login_page();
		 break;
	 }

	 if(!is_session_valid(_time)){
		 login_page();
		   return 0;
	 }

	set_http_response_header_content_type("text/html;charset=utf-8");
	printf("%s",get_http_response_header());

    MD5_CTX md5;
    MD5Init(&md5);
    int i;
    unsigned char encrypt[] ="admin";//21232f297a57a5a743894a0e4a801fc3
    unsigned char decrypt[16];
    MD5Update(&md5,encrypt,strlen((char *)encrypt));
    MD5Final(&md5,decrypt);
    printf("<br>加密前:%s\n加密后16位:<br>",encrypt);
    for(i=4;i<12;i++)
    {
        printf("%02x",decrypt[i]);  //02x前需要加上 %
    }

    printf("<br>\n加密前:%s\n加密后32位:<br>",encrypt);
    for(i=0;i<16;i++)
    {
        printf("%02x",decrypt[i]);  //02x前需要加上 %
    }
   // getchar();

    if(0 != init_session())
    	printf("init_session ERROR !\n");

    printf("<br><br>user:%s\n<br>passwd:%s\n<br>session:%ld\n<br>", get_user_name(),
    		get_password(), get_last_session_time());
*/
