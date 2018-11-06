#include <stdio.h>
#include <stdlib.h>
#include "ilp.h"

/* Global variables */
ILP_Object even;
ILP_Object odd;

/* Global prototypes */
ILP_Object ilp__odd (ILP_Closure ilp_useless, ILP_Object n1);
ILP_Object ilp__even (ILP_Closure ilp_useless, ILP_Object n2);

/* Global functions */

ILP_Object
ilp__odd (ILP_Closure ilp_useless, ILP_Object n1)
{
  {
    ILP_Object ilptmp390;
    {
      ILP_Object ilptmp391;
      ILP_Object ilptmp392;
      ilptmp391 = n1;
      ilptmp392 = ILP_Integer2ILP (0);
      ilptmp390 = ILP_Equal (ilptmp391, ilptmp392);
    }
    if (ILP_isEquivalentToTrue (ilptmp390))
      {
	return ILP_FALSE;

      }
    else
      {
	{
	  ILP_Object ilptmp393;
	  {
	    ILP_Object ilptmp394;
	    ILP_Object ilptmp395;
	    ilptmp394 = n1;
	    ilptmp395 = ILP_Integer2ILP (1);
	    ilptmp393 = ILP_Equal (ilptmp394, ilptmp395);
	  }
	  if (ILP_isEquivalentToTrue (ilptmp393))
	    {
	      return ILP_TRUE;

	    }
	  else
	    {
	      {
		ILP_Object ilptmp396;
		{
		  ILP_Object ilptmp397;
		  ILP_Object ilptmp398;
		  ilptmp397 = n1;
		  ilptmp398 = ILP_Integer2ILP (1);
		  ilptmp396 = ILP_Minus (ilptmp397, ilptmp398);
		}
		return ilp__even (NULL, ilptmp396);
	      }

	    }
	}

      }
  }
}

struct ILP_Closure odd_closure_object = {
  &ILP_object_Closure_class,
  {{ilp__odd,
    1,
    {NULL}}}
};

ILP_Object
ilp__even (ILP_Closure ilp_useless, ILP_Object n2)
{
  {
    ILP_Object ilptmp399;
    {
      ILP_Object ilptmp400;
      ILP_Object ilptmp401;
      ilptmp400 = n2;
      ilptmp401 = ILP_Integer2ILP (0);
      ilptmp399 = ILP_Equal (ilptmp400, ilptmp401);
    }
    if (ILP_isEquivalentToTrue (ilptmp399))
      {
	return ILP_TRUE;

      }
    else
      {
	{
	  ILP_Object ilptmp402;
	  {
	    ILP_Object ilptmp403;
	    ILP_Object ilptmp404;
	    ilptmp403 = n2;
	    ilptmp404 = ILP_Integer2ILP (1);
	    ilptmp402 = ILP_Equal (ilptmp403, ilptmp404);
	  }
	  if (ILP_isEquivalentToTrue (ilptmp402))
	    {
	      return ILP_FALSE;

	    }
	  else
	    {
	      {
		ILP_Object ilptmp405;
		{
		  ILP_Object ilptmp406;
		  ILP_Object ilptmp407;
		  ilptmp406 = n2;
		  ilptmp407 = ILP_Integer2ILP (1);
		  ilptmp405 = ILP_Minus (ilptmp406, ilptmp407);
		}
		return ilp__odd (NULL, ilptmp405);
	      }

	    }
	}

      }
  }
}

struct ILP_Closure even_closure_object = {
  &ILP_object_Closure_class,
  {{ilp__even,
    1,
    {NULL}}}
};


ILP_Object
ilp_program ()
{
  {
    ILP_Object ilptmp408;
    {
      ILP_Object ilptmp409;
      ilptmp409 = ILP_Integer2ILP (56);
      ilptmp408 = ilp__odd (NULL, ilptmp409);
    }
    return ILP_Not (ilptmp408);
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
