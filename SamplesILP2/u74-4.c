#include <stdio.h>
#include <stdlib.h>
#include "ilp.h"

/* Global variables */
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
    ILP_Object ilptmp617;
    {
      ILP_Object ilptmp618;
      ILP_Object ilptmp619;
      ilptmp618 = x1;
      ilptmp619 = ILP_Integer2ILP (74);
      ilptmp617 = ILP_LessThan (ilptmp618, ilptmp619);
    }
    if (ILP_isEquivalentToTrue (ilptmp617))
      {
	{
	  ILP_Object ilptmp620;
	  ILP_Object ilptmp621;
	  ilptmp620 = ILP_Integer2ILP (2);
	  ilptmp621 = x1;
	  return ILP_Times (ilptmp620, ilptmp621);
	}

      }
    else
      {
	return x1;

      }
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
    ILP_Object ilptmp622;
    {
      ILP_Object ilptmp623;
      ilptmp623 = x2;
      ilptmp622 = ilp__f1 (NULL, ilptmp623);
    }
    return ilp__f1 (NULL, ilptmp622);
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
    ILP_Object ilptmp624;
    ILP_Object ilptmp625;
    {
      ILP_Object ilptmp626;
      ilptmp626 = x4;
      ilptmp624 = ilp__f1 (NULL, ilptmp626);
    }
    {
      ILP_Object ilptmp627;
      ILP_Object ilptmp628;
      ilptmp627 = x4;
      ilptmp628 = x4;
      ilptmp625 = ilp__f2 (NULL, ilptmp627, ilptmp628);
    }
    return ilp__f2 (NULL, ilptmp624, ilptmp625);
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
    ILP_Object ilptmp629;
    ilptmp629 = x5;
    return ilp__fr2 (NULL, ilptmp629);
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
    ILP_Object ilptmp630;
    {
      ILP_Object ilptmp631;
      ilptmp631 = x6;
      ilptmp630 = ilp__fr3 (NULL, ilptmp631);
    }
    return ilp__fr3 (NULL, ilptmp630);
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
    ILP_Object ilptmp632;
    {
      ILP_Object ilptmp633;
      {
	ILP_Object ilptmp634;
	ilptmp634 = x7;
	ilptmp633 = ilp__f3 (NULL, ilptmp634);
      }
      ilptmp632 = ilp__f1 (NULL, ilptmp633);
    }
    return ilp__f3 (NULL, ilptmp632);
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
    ILP_Object ilptmp635;
    ilptmp635 = ILP_Integer2ILP (74);
    return ilp__fr3 (NULL, ilptmp635);
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
