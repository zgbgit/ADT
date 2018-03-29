#ifndef _ERR_H
#define _ERR_H

#include "gcc_optimize.h"

typedef enum {
	OK,
	ERROR,
	INFEASIBLE,
	OVERFLOW
}Status;


/*  Same as system assert(). However, under Win32 assert has some deficiencies.
    Thus this macro. */
#define c_assert(x) \
    do {\
        if (unlikely (!(x))) {\
            fprintf (stderr, "Assertion failed: %s (%s:%d)\n", #x, \
                __FILE__, __LINE__);\
            fflush (stderr);\
            c_err_abort ();\
        }\
    } while (0)

#define c_assert_return(x) \
			do {\
				if (unlikely (!(x))) {\
					fprintf (stderr, "Assertion failed: %s (%s:%d)\n", #x, \
						__FILE__, __LINE__);\
					fflush (stderr);\
					return ERROR;\
				}\
			} while (0)

void c_err_abort (void);

#endif

