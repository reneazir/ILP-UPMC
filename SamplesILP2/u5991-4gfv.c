#include <stdio.h>
#include <stdlib.h>
#include "ilp.h"

/* Global variables */
ILP_Object	function;
ILP_Object	x;
ILP_Object	deuxfois;


ILP_Object 
ilp_program()
{
	{
		ILP_Object	ilptmp133;
		ilptmp133 = function;
		{
			ILP_Object	ilptmp134;
			ILP_Object	ilptmp135;
			{
				ILP_Object	ilptmp136;
				ilptmp136 = x;
				ilptmp134 = ILP_invoke(deuxfois, 1, ilptmp136);
			}
			{
				ILP_Object	ilptmp137;
				ILP_Object	ilptmp138;
				ilptmp137 = ILP_Integer2ILP(2);
				ilptmp138 = x;
				ilptmp135 = ILP_Times(ilptmp137, ilptmp138);
			}
			ilptmp133 = ILP_invoke(ilptmp134, 1, ilptmp135);
		}
		{
			ILP_Object	ilptmp139;
			ILP_Object	ilptmp140;
			{
				ILP_Object	ilptmp141;
				ILP_Object	ilptmp142;
				{
					ILP_Object	ilptmp143;
					ilptmp143 = deuxfois;
					if (ILP_isEquivalentToTrue(ilptmp143)) {
						ilptmp141 = deuxfois;

					} else {
						ilptmp141 = deuxfois;

					}
				}
				ilptmp142 = ILP_Integer2ILP(3000);
				ilptmp139 = ILP_invoke(ilptmp141, 1, ilptmp142);
			}
			ilptmp140 = ILP_Integer2ILP(9);
			ilptmp133 = ILP_Minus(ilptmp139, ilptmp140);
		}
		return ilptmp133;
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
