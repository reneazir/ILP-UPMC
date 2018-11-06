#include <stdio.h>
#include <stdlib.h>
#include "ilp.h"

/* Global variables */
ILP_Object print;

/* Global prototypes */

/* Global functions */


ILP_Object
ilp_program ()
{
  {
    ILP_Object ilptmp316;
    ilptmp316 = ILP_Integer2ILP (5);

    {
      ILP_Object x1 = ilptmp316;
      {
	ILP_Object ilptmp317;
	while (1)
	  {
	    ILP_Object ilptmp318;
	    {
	      ILP_Object ilptmp319;
	      ILP_Object ilptmp320;
	      ilptmp319 = x1;
	      ilptmp320 = ILP_Integer2ILP (53);
	      ilptmp318 = ILP_LessThan (ilptmp319, ilptmp320);
	    }
	    if (ILP_isEquivalentToTrue (ilptmp318))
	      {
		{
		  ILP_Object ilptmp321;
		  {
		    ILP_Object ilptmp322;
		    ilptmp322 = x1;
		    ilptmp321 = ILP_print (ilptmp322);
		  }
		  {
		    ILP_Object ilptmp323;
		    {
		      ILP_Object ilptmp324;
		      ILP_Object ilptmp325;
		      ilptmp324 = ILP_Integer2ILP (2);
		      ilptmp325 = x1;
		      ilptmp323 = ILP_Times (ilptmp324, ilptmp325);
		    }
		    ilptmp321 = (x1 = ilptmp323);
		  }
		  while (1)
		    {
		      ILP_Object ilptmp326;
		      {
			ILP_Object ilptmp327;
			ILP_Object ilptmp328;
			ilptmp327 = x1;
			ilptmp328 = ILP_Integer2ILP (53);
			ilptmp326 = ILP_GreaterThan (ilptmp327, ilptmp328);
		      }
		      if (ILP_isEquivalentToTrue (ilptmp326))
			{
			  {
			    ILP_Object ilptmp329;
			    {
			      ILP_Object ilptmp330;
			      ilptmp330 = x1;
			      ilptmp329 = ILP_print (ilptmp330);
			    }
			    {
			      ILP_Object ilptmp331;
			      {
				ILP_Object ilptmp332;
				ILP_Object ilptmp333;
				ilptmp332 = x1;
				ilptmp333 = ILP_Integer2ILP (3);
				ilptmp331 = ILP_Minus (ilptmp332, ilptmp333);
			      }
			      ilptmp329 = (x1 = ilptmp331);
			    }
			    (void) ilptmp329;
			  }

			}
		      else
			{
			  break;

			}
		    }
		  ilptmp321 = ILP_FALSE;
		  (void) ilptmp321;
		}

	      }
	    else
	      {
		break;

	      }
	  }
	ilptmp317 = ILP_FALSE;
	ilptmp317 = x1;
	return ilptmp317;
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
