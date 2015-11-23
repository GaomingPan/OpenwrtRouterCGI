/*
 * util.h
 *
 *  Created on: Nov 19, 2015
 *      Author: GaomingPan
 */

#ifndef SRC_UTIL_H_
#define SRC_UTIL_H_


int is_session_valid(long int _time);

int is_authority_ok(char * _user_name, char * _password);

int set_http_response_header_content_type(char * type);

char * get_http_response_header();

void output_header();

void output_header_v(char * type);

int get_file_size(char *file_name);

int get_http_data_size();

void send_redirect_to_page(char * page_name);

void http_data_decode(char *src, char *dest, char *last);

char * get_http_post_data();

char * get_http_get_data();

char * get_post_data_property(char * property);

char * get_get_data_property(char * property);


#endif /* SRC_UTIL_H_ */
