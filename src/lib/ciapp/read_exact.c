/* SPDX-License-Identifier: GPL-2.0 */
/* X-SPDX-Copyright-Text: (c) Copyright 2003-2019 Xilinx, Inc. */
/**************************************************************************\
*//*! \file
** <L5_PRIVATE L5_SOURCE>
** \author  
**  \brief  
**   \date  
**    \cop  (c) Level 5 Networks Limited.
** </L5_PRIVATE>
*//*
\**************************************************************************/

/*! \cidoxg_lib_ciapp */

#include <ci/app.h>


int ci_read_exact(int fileno, void* buf, int bytes)
{
  int n = 0, rc;

  ci_assert(buf);
  ci_assert(bytes >= 0);

  while( bytes ) {
    rc = read(fileno, buf, bytes);
    if( rc <= 0 )  return n;

    buf = (char*) buf + rc;
    n += rc;
    bytes -= rc;
  }

  return n;
}

/*! \cidoxg_end */
