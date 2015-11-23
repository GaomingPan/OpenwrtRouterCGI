/*
 * parse_request.h
 *
 *  Created on: Nov 20, 2015
 *      Author: GaomingPan
 */

#ifndef SRC_PARSE_REQUEST_H_
#define SRC_PARSE_REQUEST_H_

int parse_pages_request(char * out_data);

int parse_get_request(char * out_data);

int parse_post_request(char * out_data);

int get_post_request_code();

#endif /* SRC_PARSE_REQUEST_H_ */
