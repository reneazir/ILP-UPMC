#include <stdio.h>
#include <stdlib.h>
#include "ilp.h"

/* Global variables */
ILP_Object fr1;
ILP_Object fr3;
ILP_Object fr2;
ILP_Object f1;
ILP_Object f2;
ILP_Object f3;

/* Global prototypes */
ILP_Object ilp__f1 (ILP_Closure ilp_useless, ILP_Object x1);
ILP_Object ilp__f2 (ILP_Closure ilp_useless, ILP_Object x2, ILP_Object y3);
ILP_Object ilp__f3 (ILP_Closure ilp_useless, ILP_Object x4);
ILP_Object ilp__fr1 (ILP_Closure ilp_useless, ILP_Object x5);
ILP_Object ilp__fr2 (ILP_Closure ilp_useless, ILP_Object x6);
ILP_Object ilp__fr3 (ILP_Closure ilp_useless, ILP_Object x7);

/* Global functions */

ILP_Object
ilp__f1 (ILP_Closure ilp_useless, ILP_Object x1)
{
  {
    ILP_Object ilptmp582;
    ILP_Object ilptmp583;
    ilptmp582 = ILP_Integer2ILP (2);
    ilptmp583 = x1;
    return ILP_Times (ilptmp582, ilptmp583);
  }
}

struct ILP_Closure f1_closure_object = {
  &ILP_object_Closure_class,
  {{ilp__f1,
    1,
    {NULL}}}
};

ILP_Object
ilp__f2 (ILP_Closure ilp_useless, ILP_Object x2, ILP_Object y3)
{
  {
    ILP_Object ilptmp584;
    {
      ILP_Object ilptmp585;
      ilptmp585 = x2;
      ilptmp584 = ilp__f1 (NULL, ilptmp585);
    }
    return ilp__f1 (NULL, ilptmp584);
  }
}

struct ILP_Closure f2_closure_object = {
  &ILP_object_Closure_class,
  {{ilp__f2,
    2,
    {NULL}}}
};

ILP_Object
ilp__f3 (ILP_Closure ilp_useless, ILP_Object x4)
{
  {
    ILP_Object ilptmp586;
    ILP_Object ilptmp587;
    {
      ILP_Object ilptmp588;
      ilptmp588 = x4;
      ilptmp586 = ilp__f1 (NULL, ilptmp588);
    }
    {
      ILP_Object ilptmp589;
      ILP_Object ilptmp590;
      ilptmp589 = x4;
      ilptmp590 = x4;
      ilptmp587 = ilp__f2 (NULL, ilptmp589, ilptmp590);
    }
    return ilp__f2 (NULL, ilptmp586, ilptmp587);
  }
}

struct ILP_Closure f3_closure_object = {
  &ILP_object_Closure_class,
  {{ilp__f3,
    1,
    {NULL}}}
};

ILP_Object
ilp__fr1 (ILP_Closure ilp_useless, ILP_Object x5)
{
  {
    ILP_Object ilptmp591;
    ilptmp591 = x5;
    return ilp__fr2 (NULL, ilptmp591);
  }
}

struct ILP_Closure fr1_closure_object = {
  &ILP_object_Closure_class,
  {{ilp__fr1,
    1,
    {NULL}}}
};

ILP_Object
ilp__fr2 (ILP_Closure ilp_useless, ILP_Object x6)
{
  {
    ILP_Object ilptmp592;
    {
      ILP_Object ilptmp593;
      ilptmp593 = x6;
      ilptmp592 = ilp__fr3 (NULL, ilptmp593);
    }
    return ilp__fr3 (NULL, ilptmp592);
  }
}

struct ILP_Closure fr2_closure_object = {
  &ILP_object_Closure_class,
  {{ilp__fr2,
    1,
    {NULL}}}
};

ILP_Object
ilp__fr3 (ILP_Closure ilp_useless, ILP_Object x7)
{
  {
    ILP_Object ilptmp594;
    {
      ILP_Object ilptmp595;
      {
	ILP_Object ilptmp596;
	ilptmp596 = x7;
	ilptmp595 = ilp__fr3 (NULL, ilptmp596);
      }
      ilptmp594 = ilp__fr1 (NULL, ilptmp595);
    }
    return ilp__f3 (NULL, ilptmp594);
  }
}

struct ILP_Closure fr3_closure_object = {
  &ILP_object_Closure_class,
  {{ilp__fr3,
    1,
    {NULL}}}
};


ILP_Object
ilp_program ()
{
  {
    ILP_Object ilptmp597;
    ilptmp597 = ILP_Integer2ILP (73);
    return ilp__f3 (NULL, ilptmp597);
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
