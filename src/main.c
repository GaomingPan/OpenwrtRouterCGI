/*
 * main.c
 *
 *  Created on: Nov 19, 2015
 *      Author: GaomingPan
 */


#include <stdio.h>
#include <stdlib.h>
#include "util.h"
#include "md5.h"
#include "session_info.h"
#include "login.h"

 int main(int argc, char *argv[])
{
	//printf("%s%c%c%c%c","Content-Type:text/html;charset=utf-8", '\r', '\n', '\r', '\n');

	 long _time = time(NULL);

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

    return 0;
}
