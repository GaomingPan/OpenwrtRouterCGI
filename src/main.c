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
        case rdWireless:
        case rsWan:
        case rsLan:
        case rsWireless:
        	output_header_v("application/json");
        	fprintf(stdout, "{\"result\":1}");
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
		if ( 0 != do_login_process()){
			send_redirect_to_page(PAGE_AUTH_ERR);
			return 0;
		}
		send_redirect_to_page(PAGE_STATUS);
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
    case rdAdmin:
    	output_header_v("application/json");
    	fprintf(stdout, "{\"result\":0,\"username\":\"%s\"}", get_user_name());
    	return 0;
    	break;
    case rdDogstat:
    	output_header_v("application/json");
    	do_dogstat();
    	return 0;
    	break;
    case rsDogstat:
    	do_wifidog_up_down( atoi( get_post_data_property("stat") ) );
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
    case rsAdmin:
    	output_header_v("application/json");
    	do_change_admin_password();
    	return 0;
    	break;
    case rsReboot:
    	output_header_v("application/json");
    	do_sys_reboot();
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




