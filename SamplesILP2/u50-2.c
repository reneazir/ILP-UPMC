#include <stdio.h>
#include <stdlib.h>
#include "ilp.h"

/* Global variables */

/* Global prototypes */

/* Global functions */


ILP_Object
ilp_program ()
{
  {
    ILP_Object ilptmp257;
    ilptmp257 = ILP_Integer2ILP (50);

    {
      ILP_Object x1 = ilptmp257;
      {
	ILP_Object ilptmp258;
	{
	  ILP_Object ilptmp259;
	  ilptmp259 = ILP_Integer2ILP (500);
	  ilptmp258 = (x1 = ilptmp259);
	}
	ilptmp258 = x1;
	return ilptmp258;
      }

    }
  }

}

static ILP_Object
ilp_caught_program ()
{
  struct ILP_catcher *current_catcher = ILP_current_catcher;
  struct ILP_catcher new_catcher;

  if (0 == setjmp (new_catcher._jmp_buf))
    {
      ILP_establish_catcher (&new_catcher);
      return ilp_program ();
    };
  return ILP_current_exception;
}

int
main (int argc, char *argv[])
{
  ILP_START_GC;
  ILP_print (ilp_caught_program ());
  ILP_newline ();
  return EXIT_SUCCESS;
}
