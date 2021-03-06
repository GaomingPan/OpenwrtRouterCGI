/*
 * comm.h
 *
 *  Created on: Nov 19, 2015
 *      Author: GaomingPan
 */

#ifndef SRC_COMMON_H_
#define SRC_COMMON_H_

#define  SESSION_CONF_FILE  "/etc/.ui_info.properties"
#define  PAGES_HOME         "/pages"
#define  CGI_HOME           "/www_cloud/cgi-bin"

#define  STATUS_DATA_SCRIPT              CGI_HOME"/getStatusInfo"
#define  NETWORK_DATA_SCRIPT             CGI_HOME"/getNetworkInfo"
#define  WIRELESS_DATA_SCRIPT            CGI_HOME"/getWirelessInfo"
#define  NETWORK_SETTINGS_SCRIPT         CGI_HOME"/networkSettings"
#define  WIRELESS_SETTINGS_SCRIPT        CGI_HOME"/wirelessSettings"

#define  CMD_RESET                       "sh -c \"sleep 1; killall dropbear uhttpd; sleep 1; mtd -r erase rootfs_data\""
#define  CMD_STOP_START_DOG              "sh -c \"uci set dog_alive.@dog_alive[0].is_alive=%d;uci commit dog_alive;echo %d > /tmp/.is_stop_or_start_deamon\""

#define  SESSION_TIME_OUT        180
#define  MAX_ARRAY_LENTH         2048
#define  HTTP_HEADER_LENTH       1024
#define  MAX_FORM_DATA_LENTH     1024
#define  MAX_PROPERTY_DARA_SIZE  64


#define  PAGE_INDEX        "/index.html"
#define  PAGE_LOGIN        "/pages/login.html"
#define  PAGE_STATUS       "/pages/status.html"

#define  PAGE_AUTH_ERR     "/pages/autherr.html"

#define  HIDDEN_FORM_ID     "form_id"



typedef enum{

	rLogin,
	rLogout,
	rStatus,
	rSystem,
	rBadRequest,
	rInvalid,

	rdStatus,
	rdNetwork,
	rdWireless,
	rdAdmin,
	rdDogstat,

	rsWan,
	rsLan,
	rsWireless,
	rsAdmin,
	rsDogstat,

	rsReboot,
	rsReset,

}RequestCode;


#define  DEBUG(func, msg, code) do{ \
		FILE * fp; \
		char log[1024] = {0}; \
		sprintf(log, "\n\n[<< DEBUG >>] --> f name: %s\n msg: %s\n code: %ld\n", func, msg, code); \
        fp = fopen("/dev/console", "w"); \
        if(fp){ \
          fwrite(log, 1, strlen(log), fp); \
          fclose(fp); \
         } \
        }while(0)

#endif /* SRC_COMMON_H_ */
