/*
 * session_info.h
 *
 *  Created on: Nov 20, 2015
 *      Author: GaomingPan
 */

#ifndef SRC_SESSION_INFO_H_
#define SRC_SESSION_INFO_H_

char * get_user_name();

char * get_password();

long get_last_session_time();

int save_session_info(char * _user_name, char * _password);

int clean_session();

int init_session();

#endif /* SRC_SESSION_INFO_H_ */
