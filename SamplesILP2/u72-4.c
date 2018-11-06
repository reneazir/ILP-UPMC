#include <stdio.h>
#include <stdlib.h>
#include "ilp.h"

/* Global variables */
ILP_Object foo;

/* Global prototypes */
ILP_Object ilp__foo (ILP_Closure ilp_useless, ILP_Object x1, ILP_Object y2);

/* Global functions */

ILP_Object
ilp__foo (ILP_Closure ilp_useless, ILP_Object x1, ILP_Object y2)
{
  {
    ILP_Object ilptmp558;
    ILP_Object ilptmp559;
    ilptmp558 = x1;
    ilptmp559 = y2;
    return ILP_Plus (ilptmp558, ilptmp559);
  }
}

struct ILP_Closure foo_closure_object = {
  &ILP_object_Closure_class,
  {{ilp__foo,
    2,
    {NULL}}}
};


ILP_Object
ilp_program ()
{
  {
    ILP_Object ilptmp560;
    ILP_Object ilptmp561;
    {
      ILP_Object ilptmp562;
      ilptmp562 = ILP_TRUE;
      if (ILP_isEquivalentToTrue (ilptmp562))
	{
	  ilptmp560 = ILP_Integer2ILP (8);

	}
      else
	{
	  ilptmp560 = ILP_Integer2ILP (1);

	}
    }
    {
      ILP_Object ilptmp563;
      ilptmp563 = ILP_Integer2ILP (8);

      {
	ILP_Object x3 = ilptmp563;
	{
	  ILP_Object ilptmp564;
	  ILP_Object ilptmp565;
	  ilptmp564 = x3;
	  ilptmp565 = x3;
	  ilptmp561 = ILP_Times (ilptmp564, ilptmp565);
	}

      }
    }
    return ilp__foo (NULL, ilptmp560, ilptmp561);
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
