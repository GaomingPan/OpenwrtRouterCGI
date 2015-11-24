/*
 * data_request.c
 *
 *  Created on: Nov 23, 2015
 *      Author: GaomingPan
 */


#include <stdio.h>
#include <stdlib.h>

#include "common.h"
#include "contents.h"
#include "data_request.h"



char * get_status_data()
{
	FILE *fp;

	memset(buffers, 0, MAX_ARRAY_LENTH);

	fp = popen(STATUS_DATA_SCRIPT, "r");

	if (!fp)
		goto err;

	fread(buffers, 1, MAX_ARRAY_LENTH, fp);
	pclose(fp);

	return buffers;
err:
	return NULL;
}
