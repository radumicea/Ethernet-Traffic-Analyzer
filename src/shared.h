/*****************************************************************************
 * shared.h
 *****************************************************************************/

#ifndef __SHARED_H__
#define __SHARED_H__

#include <cdefbf537.h>
/*  
#include <builtins.h>
#include <sys/exception.h>
#include <sys/pll.h>
 */
#define sleep(counter) for (volatile long ___i = 0; ___i < (counter); ___i++)
typedef unsigned char byte_t;

#endif /* __SHARED_H__ */
