/*********************************************************************
*A Random Number Generator based on coupled chaotic Logistic lattice *
*                                                                    *
*  (both double and single precision random numbers are supported)   *
*                                                                    *
*  Author: Qianqian Fang <q.fang at neu.edu>                         *
*                                                                    *
*  History: 2009/03/02  CUDA version based on Neal Wagner 1993       *
*         http://www.cs.utsa.edu/~wagner/pubs/logistic/logistic.pdf  *
*                                                                    *
*********************************************************************/

/***************************************************************************//**
\file    posix_randr.h

\brief   An interface to use a 48bit multi-threaded GNU RNG
*******************************************************************************/

#ifndef _MCEXTREME_STDC_RAND_H
#define _MCEXTREME_STDC_RAND_H

#include <stdlib.h>

#define __device__  static inline

#define MCX_RNG_NAME       "POSIX Multi-threaded RNG"

#define RAND_BUF_LEN       3        //register arrays
#define RAND_SEED_LEN      3

typedef unsigned int uint;

#ifdef _WIN32
  #include "drand48_r_libgw32c.h"
#endif

typedef unsigned short RandType;

// transform into [0,1] random number
__device__ float rand_uniform01(RandType t[RAND_BUF_LEN]);
__device__ void rng_init(RandType t[RAND_BUF_LEN], RandType tnew[RAND_BUF_LEN],uint *n_seed,int idx);
__device__ void rand_need_more(RandType t[RAND_BUF_LEN],RandType tbuf[RAND_BUF_LEN]);
// generate [0,1] random number for the next scattering length
__device__ float rand_next_scatlen(RandType t[RAND_BUF_LEN]);
// generate [0,1] random number for the next arimuthal angle
__device__ float rand_next_aangle(RandType t[RAND_BUF_LEN]);
// generate random number for the next zenith angle
__device__ float rand_next_zangle(RandType t[RAND_BUF_LEN]);
__device__ float rand_next_reflect(RandType t[RAND_BUF_LEN]);
__device__ float rand_do_roulette(RandType t[RAND_BUF_LEN]);

#endif
