/*
 * parse_request.h
 *
 *  Created on: Nov 20, 2015
 *      Author: GaomingPan
 */

#ifndef SRC_PARSE_REQUEST_H_
#define SRC_PARSE_REQUEST_H_

int parse_pages_request(char * out_contents, char *request);

int parse_get_request(char * out_contents, char *request);

int parse_post_request(char * out_contents, char *request);


#endif /* SRC_PARSE_REQUEST_H_ */
