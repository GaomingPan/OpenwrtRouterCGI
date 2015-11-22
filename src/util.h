/*
 * util.h
 *
 *  Created on: Nov 19, 2015
 *      Author: GaomingPan
 */

#ifndef SRC_UTIL_H_
#define SRC_UTIL_H_


int is_session_valid(long int _time);

int is_authority_ok(const  char * _user_name, const  char * _password);

int set_http_response_header_content_type(const char * type);

char * get_http_response_header();

void output_header();

int get_file_size(const char *file_name);

void send_direct_to_page(const char * page_name);


#endif /* SRC_UTIL_H_ */
