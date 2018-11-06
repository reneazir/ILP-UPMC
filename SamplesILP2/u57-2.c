#include <stdio.h>
#include <stdlib.h>
#include "ilp.h"

/* Global variables */


ILP_Object 
ilp_program()
{
	{
		ILP_Object	ilptmp100;
		ILP_Object	ilptmp101;
		ilptmp100 = ILP_Integer2ILP(51);
		ilptmp101 = ILP_Integer2ILP(6);

		{
			ILP_Object	x1 = ilptmp100;
			ILP_Object	y2 = ilptmp101;
			{
				ILP_Object	ilptmp102;
				ILP_Object	ilptmp103;
				ilptmp102 = x1;
				ilptmp103 = y2;
				return ILP_Plus(ilptmp102, ilptmp103);
			}

		}
	}

}

static ILP_Object 
ilp_caught_program()
{
	struct ILP_catcher *current_catcher = ILP_current_catcher;
	struct ILP_catcher new_catcher;

	if (0 == setjmp(new_catcher._jmp_buf)) {
		ILP_establish_catcher(&new_catcher);
		return ilp_program();
	};
	return ILP_current_exception;
}

int 
main(int argc, char *argv[])
{
	ILP_START_GC;
	ILP_print(ilp_caught_program());
	ILP_newline();
	return EXIT_SUCCESS;
}
