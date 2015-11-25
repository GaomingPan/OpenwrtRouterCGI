/*
 * do_process.c
 *
 *  Created on: Nov 24, 2015
 *      Author: GaomingPan
 */

#include <stdio.h>
#include <stdlib.h>

#include "common.h"
#include "util.h"
#include "contents.h"

#include "do_process.h"


void do_logout()
{
    clean_session();
    fprintf(stdout, "%s", "[\"code\":0]");
}
