/* pooln.c: NULL POOL CLASS
 *
 * $Id$
 * Copyright (c) 2001-2014 Ravenbrook Limited.  See end of file for license.
 */

#include "pooln.h"
#include "mpm.h"

SRCID(pooln, "$Id$");


/* PoolNStruct -- the pool structure */

typedef struct PoolNStruct {
  PoolStruct poolStruct;                /* generic pool structure */
  /* and that's it */
} PoolNStruct;


typedef PoolN NPool;
DECLARE_CLASS(Pool, NPool, AbstractPool);


/* PoolPoolN -- get the PoolN structure from generic Pool */

#define PoolPoolN(pool) PARENT(PoolNStruct, poolStruct, pool)


/* PoolPoolN -- get the generic pool structure from a PoolN */

#define PoolNPool(pooln) (&(poolN)->poolStruct)


/* NInit -- init method for class N */

static Res NInit(Pool pool, Arena arena, PoolClass klass, ArgList args)
{
  PoolN poolN;
  Res res;

  AVER(pool != NULL);
  AVERT(Arena, arena);
  AVERT(ArgList, args);
  UNUSED(klass); /* used for debug pools only */

  /* FIXME: Reduce this boilerplate. */
  res = PoolAbsInit(pool, arena, klass, args);
  if (res != ResOK)
    goto failAbsInit;
  poolN = CouldBeA(NPool, pool);
  
  /* Initialize pool-specific structures. */

  SetClassOfPoly(pool, CLASS(NPool));
  AVERC(PoolN, poolN);

  return ResOK;

failAbsInit:
  AVER(res != ResOK);
  return res;
}


/* NFinish -- finish method for class N */

static void NFinish(Inst inst)
{
  Pool pool = MustBeA(AbstractPool, inst);
  PoolN poolN = MustBeA(NPool, pool);

  /* Finish pool-specific structures. */
  UNUSED(poolN);

  NextMethod(Inst, NPool, finish)(inst);
}


/* NAlloc -- alloc method for class N */

static Res NAlloc(Addr *pReturn, Pool pool, Size size)
{
  PoolN poolN = MustBeA(NPool, pool);

  AVER(pReturn != NULL);
  AVER(size > 0);
  UNUSED(poolN);

  return ResLIMIT;  /* limit of nil blocks exceeded */
}


/* NFree -- free method for class N */

static void NFree(Pool pool, Addr old, Size size)
{
  PoolN poolN = MustBeA(NPool, pool);

  AVER(old != (Addr)0);
  AVER(size > 0);
  UNUSED(poolN);

  NOTREACHED;  /* can't allocate, should never free */
}


/* NBufferFill -- buffer fill method for class N */

static Res NBufferFill(Addr *baseReturn, Addr *limitReturn,
                       Pool pool, Buffer buffer, Size size)
{
  PoolN poolN = MustBeA(NPool, pool);

  AVER(baseReturn != NULL);
  AVER(limitReturn != NULL);
  AVERT(Buffer, buffer);
  AVER(BufferIsReset(buffer));
  AVER(size > 0);
  UNUSED(poolN);

  NOTREACHED;   /* can't create buffers, so shouldn't fill them */
  return ResUNIMPL;
}


/* NBufferEmpty -- buffer empty method for class N */

static void NBufferEmpty(Pool pool, Buffer buffer,
                         Addr init, Addr limit)
{
  AVERT(Pool, pool);
  AVERT(Buffer, buffer);
  AVER(BufferIsReady(buffer));
  AVER(init <= limit);

  NOTREACHED;   /* can't create buffers, so they shouldn't trip */
}


/* NDescribe -- describe method for class N */

static Res NDescribe(Inst inst, mps_lib_FILE *stream, Count depth)
{
  Pool pool = CouldBeA(AbstractPool, inst);
  PoolN poolN = CouldBeA(NPool, pool);
  Res res;

  res = NextMethod(Inst, NPool, describe)(inst, stream, depth);
  if (res != ResOK)
    return res;

  /* This is where you'd output some information about pool fields. */
  UNUSED(poolN);

  return ResOK;
}


/* NWhiten -- condemn method for class N */

static Res NWhiten(Pool pool, Trace trace, Seg seg)
{
  PoolN poolN = MustBeA(NPool, pool);

  AVERT(Trace, trace);
  AVERT(Seg, seg);
  UNUSED(poolN);
 
  NOTREACHED; /* pool doesn't have any actions */

  return ResUNIMPL;
}


/* NGrey -- greyen method for class N */

static void NGrey(Pool pool, Trace trace, Seg seg)
{
  PoolN poolN = MustBeA(NPool, pool);

  AVERT(Trace, trace);
  AVERT(Seg, seg);
  UNUSED(poolN);
}


/* NBlacken -- blacken method for class N */

static void NBlacken(Pool pool, TraceSet traceSet, Seg seg)
{
  PoolN poolN = MustBeA(NPool, pool);

  AVERT(TraceSet, traceSet);
  AVERT(Seg, seg);
  UNUSED(poolN);
}


/* NScan -- scan method for class N */

static Res NScan(Bool *totalReturn, ScanState ss, Pool pool, Seg seg)
{
  PoolN poolN = MustBeA(NPool, pool);

  AVER(totalReturn != NULL);
  AVERT(ScanState, ss);
  AVERT(Seg, seg);
  UNUSED(poolN);

  return ResOK;
}


/* NFix -- fix method for class N */

static Res NFix(Pool pool, ScanState ss, Seg seg, Ref *refIO)
{
  PoolN poolN = MustBeA(NPool, pool);

  AVERT(ScanState, ss);
  UNUSED(refIO);
  AVERT(Seg, seg);
  UNUSED(poolN);
  NOTREACHED;  /* Since we don't allocate any objects, should never */
               /* be called upon to fix a reference. */
  return ResFAIL;
}


/* NReclaim -- reclaim method for class N */

static void NReclaim(Pool pool, Trace trace, Seg seg)
{
  PoolN poolN = MustBeA(NPool, pool);

  AVERT(Trace, trace);
  AVERT(Seg, seg);
  UNUSED(poolN);
  /* all unmarked and white objects reclaimed */
}


/* NTraceEnd -- trace end method for class N */

static void NTraceEnd(Pool pool, Trace trace)
{
  PoolN poolN = MustBeA(NPool, pool);

  AVERT(Trace, trace);
  UNUSED(poolN);
}


/* NPoolClass -- pool class definition for N */

DEFINE_CLASS(Pool, NPool, klass)
{
  INHERIT_CLASS(klass, NPool, AbstractPool);
  klass->instClassStruct.describe = NDescribe;
  klass->instClassStruct.finish = NFinish;
  klass->size = sizeof(PoolNStruct);
  klass->attr |= AttrGC;
  klass->init = NInit;
  klass->alloc = NAlloc;
  klass->free = NFree;
  klass->bufferFill = NBufferFill;
  klass->bufferEmpty = NBufferEmpty;
  klass->whiten = NWhiten;
  klass->grey = NGrey;
  klass->blacken = NBlacken;
  klass->scan = NScan;
  klass->fix = NFix;
  klass->fixEmergency = NFix;
  klass->reclaim = NReclaim;
  klass->traceEnd = NTraceEnd;
  AVERT(PoolClass, klass);
}


/* PoolClassN -- returns the PoolClass for the null pool class */

PoolClass PoolClassN(void)
{
  return CLASS(NPool);
}


/* PoolNCheck -- check a pool of class N */

Bool PoolNCheck(PoolN poolN)
{
  CHECKL(poolN != NULL);
  CHECKD(Pool, PoolNPool(poolN));
  CHECKC(NPool, poolN);
  UNUSED(poolN); /* <code/mpm.c#check.unused> */

  return TRUE;
}


/* C. COPYRIGHT AND LICENSE
 *
 * Copyright (C) 2001-2014 Ravenbrook Limited <http://www.ravenbrook.com/>.
 * All rights reserved.  This is an open source license.  Contact
 * Ravenbrook for commercial licensing options.
 * 
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are
 * met:
 * 
 * 1. Redistributions of source code must retain the above copyright
 * notice, this list of conditions and the following disclaimer.
 * 
 * 2. Redistributions in binary form must reproduce the above copyright
 * notice, this list of conditions and the following disclaimer in the
 * documentation and/or other materials provided with the distribution.
 * 
 * 3. Redistributions in any form must be accompanied by information on how
 * to obtain complete source code for this software and any accompanying
 * software that uses this software.  The source code must either be
 * included in the distribution or be available for no more than the cost
 * of distribution plus a nominal fee, and must be freely redistributable
 * under reasonable conditions.  For an executable file, complete source
 * code means the source code for all modules it contains. It does not
 * include source code for modules or files that typically accompany the
 * major components of the operating system on which the executable file
 * runs.
 * 
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS
 * IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED
 * TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR
 * PURPOSE, OR NON-INFRINGEMENT, ARE DISCLAIMED. IN NO EVENT SHALL THE
 * COPYRIGHT HOLDERS AND CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT
 * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF
 * USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
 * ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
 * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */
