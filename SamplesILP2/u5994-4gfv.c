#include <stdio.h>
#include <stdlib.h>
#include "ilp.h"

/* Global variables */
ILP_Object twice;
ILP_Object deuxfois;

/* Global prototypes */
ILP_Object ilp__deuxfois (ILP_Closure ilp_useless, ILP_Object x1);
ILP_Object ilp__twice (ILP_Closure ilp_useless, ILP_Object f2, ILP_Object x3);

/* Global functions */

ILP_Object
ilp__deuxfois (ILP_Closure ilp_useless, ILP_Object x1)
{
  {
    ILP_Object ilptmp512;
    ILP_Object ilptmp513;
    ilptmp512 = ILP_Integer2ILP (2);
    ilptmp513 = x1;
    return ILP_Times (ilptmp512, ilptmp513);
  }
}

struct ILP_Closure deuxfois_closure_object = {
  &ILP_object_Closure_class,
  {{ilp__deuxfois,
    1,
    {NULL}}}
};

ILP_Object
ilp__twice (ILP_Closure ilp_useless, ILP_Object f2, ILP_Object x3)
{
  {
    ILP_Object ilptmp514;
    ILP_Object ilptmp515;
    ilptmp514 = f2;
    {
      ILP_Object ilptmp516;
      ILP_Object ilptmp517;
      ilptmp516 = f2;
      ilptmp517 = x3;
      ilptmp515 = ILP_invoke (ilptmp516, 1, ilptmp517);
    }
    return ILP_invoke (ilptmp514, 1, ilptmp515);
  }
}

struct ILP_Closure twice_closure_object = {
  &ILP_object_Closure_class,
  {{ilp__twice,
    2,
    {NULL}}}
};


ILP_Object
ilp_program ()
{
  {
    ILP_Object ilptmp518;
    ILP_Object ilptmp519;
    {
      ILP_Object ilptmp520;
      ILP_Object ilptmp521;
      ilptmp520 = (ILP_Object) & deuxfois_closure_object;
      ilptmp521 = ILP_Integer2ILP (1500);
      ilptmp518 = ilp__twice (NULL, ilptmp520, ilptmp521);
    }
    ilptmp519 = ILP_Integer2ILP (6);
    return ILP_Minus (ilptmp518, ilptmp519);
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
