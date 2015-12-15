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
    	switch(request_code){
    	case rLogin:
    		output_header_v("text/html;charset=utf-8");
    		if ( 0 != do_login_process()){
    			send_redirect_to_page(PAGE_AUTH_ERR);
    			return 0;
    		}
    		send_redirect_to_page(PAGE_STATUS);
    		break;

    	case rStatus:
    	case rdAdmin:
        case rdNetwork:
        case rdWireless:
        case rdStatus:
        case rdDogstat:

        case rsWan:
        case rsLan:
        case rsWireless:
        case rsAdmin:
        case rsReboot:
        case rsReset:
        	output_header_v("application/json");
        	fprintf(stdout, "{\"result\":1}");
        	return 0;
        	break;

    	default:
    		output_header_v("text/html;charset=utf-8");
    		send_redirect_to_page(PAGE_LOGIN);
    		break;
    	}
    	return 0;
}



static int do_valid_session()
{
    request_code = get_post_request_code();
//    DEBUG("session is valid", "RequestCode", request_code);
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
    	do_logout();
    	return 0;
    	break;

    case rdStatus:
    	output_header_v("application/json");
    	fprintf(stdout, "%s", get_status_data());
    	save_session_info(NULL, NULL);
    	return 0;
    	break;
    case rdNetwork:
    	output_header_v("application/json");
    	fprintf(stdout, "%s", get_network_data());
    	save_session_info(NULL, NULL);
//    	DEBUG("network-data",get_network_data(),0);
    	return 0;
    	break;
    case rdWireless:
    	output_header_v("application/json");
    	fprintf(stdout, "%s", get_wireless_data());
    	save_session_info(NULL, NULL);
//    	DEBUG("wireless-data",get_wireless_data(),0);
    	return 0;
    	break;
    case rdAdmin:
    	output_header_v("application/json");
    	fprintf(stdout, "{\"result\":0,\"username\":\"%s\"}", get_user_name());
    	save_session_info(NULL, NULL);
    	return 0;
    	break;
    case rdDogstat:
    	output_header_v("application/json");
    	do_dogstat();
    	save_session_info(NULL, NULL);
    	return 0;
    	break;
    case rsDogstat:
    	output_header_v("application/json");
//    	DEBUG("rsDogstat", "Enter", 0);
    	do_wifidog_up_down();
    	save_session_info(NULL, NULL);
    	return 0;
    	break;
    case rsWan:
    	output_header_v("application/json");
    	do_network_settings(rsWan);
    	save_session_info(NULL, NULL);
    	return 0;
    	break;
    case rsLan:
    	output_header_v("application/json");
    	do_network_settings(rsLan);
    	save_session_info(NULL, NULL);
    	return 0;
    	break;
    case rsWireless:
    	output_header_v("application/json");
    	do_wireless_settings();
    	save_session_info(NULL, NULL);
    	return 0;
    	break;
    case rsAdmin:
    	output_header_v("application/json");
    	do_change_admin_password();
//    	save_session_info(NULL, NULL);
    	return 0;
    	break;
    case rsReboot:
    	output_header_v("application/json");
    	do_sys_reboot();
    	return 0;
    	break;
    case rsReset:
    	output_header_v("application/json");
    	do_sys_reset();
    	break;
    default:
    	output_header_v("text/html;charset=utf-8");
    	send_redirect_to_page(PAGE_STATUS);
    	save_session_info(NULL, NULL);
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

//    DEBUG("post-data:",get_http_post_data(),0);
    if ( is_session_valid(_time) < 0 )
    	return do_invalid_session();

    return do_valid_session();
}




