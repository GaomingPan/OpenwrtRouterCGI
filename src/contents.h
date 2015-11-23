/*
 * contents.h
 *
 *  Created on: Nov 20, 2015
 *      Author: GaomingPan
 */

#ifndef SRC_CONTENTS_H_
#define SRC_CONTENTS_H_


extern  char user_name[];

extern  char password[];

extern  long last_session_time;

extern char  http_response_header[];

extern char  http_post_data[];

extern char  http_get_data[];

extern char  property_data[];


#define  REDIRECT_PAGES "<?xml version=\"1.0\" encoding=\"utf-8\"?> \
	<!DOCTYPE html PUBLIC \"-//W3C//DTD XHTML 1.1//EN" "http://www.w3.org/TR/xhtml11/DTD/xhtml11.dtd\"> \
	<html xmlns=\"http://www.w3.org/1999/xhtml\"> \
	<head> \
	<meta http-equiv=\"refresh\" content=\"0; url=%s\" /> \
	</head>  \
	<body style=\"background-color: black\">  \
	</body> \
	</html>"

#endif /* SRC_CONTENTS_H_ */
