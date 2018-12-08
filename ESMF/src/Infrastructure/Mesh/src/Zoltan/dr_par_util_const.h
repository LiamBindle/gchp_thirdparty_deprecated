/*****************************************************************************
 * Zoltan Library for Parallel Applications                                  *
 * Copyright (c) 2000,2001,2002, Sandia National Laboratories.               *
 * For more info, see the README file in the top-level Zoltan directory.     *  
 *****************************************************************************/
/*****************************************************************************
 * CVS File Information :
 *    $RCSfile: dr_par_util_const.h,v $
 *    $Author: mathomp4 $
 *    $Date: 2013-01-11 20:23:44 $
 *    Revision: 1.8 $
 ****************************************************************************/


#ifndef _DR_PAR_UTIL_CONST_H_
#define _DR_PAR_UTIL_CONST_H_

#ifdef __cplusplus
/* if C++, define the rest of this header file as extern C */
extern "C" {
#endif


extern
void print_sync_start (
  int proc,
  int do_print_line
);

extern
void print_sync_end (
  int proc,
  int nprocs,
  int do_print_line
);

extern
void boundary_exchange(
  MESH_INFO_PTR mesh,
  int vec_len,
  int *send_vec,
  int *recv_vec
);
/* Function prototypes */

#ifdef __cplusplus
} /* closing bracket for extern "C" */
#endif
#endif /* _DR_PAR_UTIL_CONST_H_ */
