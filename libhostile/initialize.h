/*  vim:expandtab:shiftwidth=2:tabstop=2:smarttab:
 *
 *  Data Differential's libhostle
 *
 *  Copyright (C) 2012 Data Differential, http://datadifferential.com/
 *
 *  Redistribution and use in source and binary forms, with or without
 *  modification, are permitted provided that the following conditions are
 *  met:
 *
 *      * Redistributions of source code must retain the above copyright
 *  notice, this list of conditions and the following disclaimer.
 *
 *      * Redistributions in binary form must reproduce the above
 *  copyright notice, this list of conditions and the following disclaimer
 *  in the documentation and/or other materials provided with the
 *  distribution.
 *
 *      * The names of its contributors may not be used to endorse or
 *  promote products derived from this software without specific prior
 *  written permission.
 *
 *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 *  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 *  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 *  A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 *  OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 *  SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 *  LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 *  DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 *  THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 *  (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 *  OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 */

#pragma once

#include <pthread.h>

#include <stdbool.h>

#include <libhostile/accept.h>
#include <libhostile/action.h>
#include <libhostile/getaddrinfo.h>
#include <libhostile/malloc.h>
#include <libhostile/poll.h>
#include <libhostile/realloc.h>
#include <libhostile/recv.h>
#include <libhostile/send.h>
#include <libhostile/setsockopt.h>
#include <libhostile/write.h>

#include <libhostile/hostile.h>

#ifdef __cplusplus
extern "C" {
#endif

union function_un {
  accept_fn *accept;
  getaddrinfo_fn *getaddrinfo;
  malloc_fn *malloc;
  poll_fn *poll;
  realloc_fn *realloc;
  recv_fn *recv;
  send_fn *send;
  setsockopt_fn *setsockopt;
  write_fn *write;
  void *ptr;
};

struct function_st {
  const char *name;
  union function_un function;
  enum action_t action;
  int frequency;
};

void hostile_initialize(void);
struct function_st set_function(const char *name, const char *environ_name);
void set_action_frequency(enum action_t action, int frequency);

#ifdef __cplusplus
}
#endif
