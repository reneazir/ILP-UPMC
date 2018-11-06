#include <stdio.h>
#include <stdlib.h>
#include "ilp.h"

/* Global variables */
ILP_Object deuxfois;

/* Global prototypes */
ILP_Object ilp__deuxfois (ILP_Closure ilp_useless, ILP_Object x1);

/* Global functions */

ILP_Object
ilp__deuxfois (ILP_Closure ilp_useless, ILP_Object x1)
{
  {
    ILP_Object ilptmp479;
    ILP_Object ilptmp480;
    ilptmp479 = ILP_Integer2ILP (2);
    ilptmp480 = x1;
    return ILP_Times (ilptmp479, ilptmp480);
  }
}

struct ILP_Closure deuxfois_closure_object = {
  &ILP_object_Closure_class,
  {{ilp__deuxfois,
    1,
    {NULL}}}
};


ILP_Object
ilp_program ()
{
  {
    ILP_Object ilptmp481;
    ilptmp481 = (ILP_Object) & deuxfois_closure_object;

    {
      ILP_Object f2 = ilptmp481;
      {
	ILP_Object ilptmp482;
	ILP_Object ilptmp483;
	{
	  ILP_Object ilptmp484;
	  ILP_Object ilptmp485;
	  ilptmp484 = f2;
	  ilptmp485 = ILP_Integer2ILP (3000);
	  ilptmp482 = ILP_invoke (ilptmp484, 1, ilptmp485);
	}
	ilptmp483 = ILP_Integer2ILP (8);
	return ILP_Minus (ilptmp482, ilptmp483);
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
