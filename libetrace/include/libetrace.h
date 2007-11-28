/*
** @file libetrace.h
**
** Started on  Sat Nov 17 12:10:12 2007 eau
**
**
** $Id: libetrace.h,v 1.1 2007-11-28 09:32:07 rival Exp $
**
*/

#ifndef __LIBETRACE_H_
#define __LIBETRACE_H_

#include "libvars.h"

#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <regex.h>

//#include "elfsh-libc.h"

#include <elf.h>
#include "libaspect.h"
#include "libelfsh.h"
//#include <libelfsh/libelfsh-compat.h>

#ifdef __BEOS__
#include <bsd_mem.h>
#endif

#if !defined(__USE_GNU)
#define __USE_GNU
#endif

#include <sys/ucontext.h>

#if !defined(sgi)
#include <sys/user.h>
#endif

#if defined(__NetBSD__)
#include <miscfs/procfs/procfs.h>
#else
#include <sys/procfs.h>
#endif

#define TRACES_CFLOW 	1
#define TRACES_PLT 	2
#define TRACES_GOT 	3

char buf[BUFSIZ];

#define TRACE_USED_longjmp		0
#define TRACE_USED__setjmp		1
#define TRACE_USED_sigaction		2
#define TRACE_USED_snprintf		3
#define TRACE_USED_memset		4
#define TRACE_USED_gettimeofday		5
#define TRACE_USED_write		6
#define TRACE_USED_exit			7
#define TRACE_USED_MAX			8

#define TRACE_UNTRACABLE_NAME "untracable"

typedef struct _trace_used
{
  char *name;
  u_char exist;
} trace_used, *ptrace_used;

/* Untracable table */
hash_t traces_untracable;
u_char untracable_ostype;

#define TRACE_FUNCTIONS_ADD(_name) \
{ #_name, 0 }

#define FUNC_BEGIN(_name) \
(trace_functions[TRACE_USED_##_name].exist ? "old_" : "")

/*
trace_used trace_functions[] = 
  { 
    TRACE_FUNCTIONS_ADD(longjmp),
    TRACE_FUNCTIONS_ADD(_setjmp),
    TRACE_FUNCTIONS_ADD(sigaction),
    TRACE_FUNCTIONS_ADD(snprintf),
    TRACE_FUNCTIONS_ADD(memset),
    TRACE_FUNCTIONS_ADD(gettimeofday),
    TRACE_FUNCTIONS_ADD(write),
    TRACE_FUNCTIONS_ADD(exit),
    { "", 0 }
  };
  */

/**
 * @brief Store every traces, this table store another hash table for each key 
 */
hash_t traces_table;

/**
 * @brief Exclude hash table which contain regex
 */
hash_t exclude_table;

/**
 * @brief Whole active elements 
 */
/* int trace_enabled_count = 0;*/

#define ELFSH_TRACES_TABLE_NAME 	"elfsh_traces_table"
#define ELFSH_TRACES_EXCLUDE_TABLE_NAME "elfsh_traces_exclude_table"
#define ELFSH_TRACES_PATTERN 		"traces_%s"

/* traces.c */
int		*elfsh_traces_inittrace();
hash_t		*elfsh_traces_createtrace(char *trace);
hash_t		*elfsh_traces_gettrace(char *trace);

/* check.c */
int		elfsh_traces_valid_faddr(elfshobj_t *file, elfsh_Addr addr, elfsh_Addr *vaddr, u_char *dynsym);
int 		elfsh_traces_tracable(elfshobj_t *file, char *name,
				      elfsh_Addr *vaddr, u_char *dynsym);
/* check_untracable.c */
int		elfsh_traces_untracable(elfshobj_t *file, char *name);

/* func_add.c */
elfshtraces_t 	*elfsh_traces_funcadd(char *trace, char *name, elfshtraces_t *newtrace);

/* func_remove.c */
int		elfsh_traces_funcrm(char *trace, char *name);
int		elfsh_traces_funcrmall(char *trace);

/* func_exclude.c */
int		elfsh_traces_funcexclude(char *regstr);
int		elfsh_traces_funcrmexclude(char *regstr);

/* func_enable.c */
int		elfsh_traces_funcenable(char *trace, char *name);
int		elfsh_traces_funcenableall(char *trace);

/* func_disable.c */
int		elfsh_traces_funcdisable(char *trace, char *name);
int		elfsh_traces_funcdisableall(char *trace);

/* func_status.c */
int		elfsh_traces_funcsetstatus(hash_t *table, int status);

/* delete.c */
int		elfsh_traces_deletetrace(char *trace);

/* save.c */
int		elfsh_traces_save(elfshobj_t *file);

/* search.c */
elfshobj_t   	*elfsh_traces_search_sym(elfshobj_t *file, char *name);

/* search_addr.c */
int		elfsh_addr_get_func_list(elfshobj_t *file, elfsh_Addr **addr);
int		elfsh_addr_is_called(elfshobj_t *file, elfsh_Addr addr);

/* errfunc.c */
char		*elfsh_traces_geterrfunc();

#endif
