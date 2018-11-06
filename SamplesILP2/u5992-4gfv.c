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
		ILP_Object	ilptmp144;
		ilptmp144 = function;
		{
			ILP_Object	ilptmp145;
			ILP_Object	ilptmp146;
			{
				ILP_Object	ilptmp147;
				ilptmp147 = x;
				ilptmp145 = ILP_invoke(deuxfois, 1, ilptmp147);
			}
			{
				ILP_Object	ilptmp148;
				ILP_Object	ilptmp149;
				ilptmp148 = ILP_Integer2ILP(2);
				ilptmp149 = x;
				ilptmp146 = ILP_Times(ilptmp148, ilptmp149);
			}
			ilptmp144 = ILP_invoke(ilptmp145, 1, ilptmp146);
		}
		{
			ILP_Object	ilptmp150;
			ilptmp150 = deuxfois;

			{
				ILP_Object	f1 = ilptmp150;
				{
					ILP_Object	ilptmp151;
					ILP_Object	ilptmp152;
					{
						ILP_Object	ilptmp153;
						ILP_Object	ilptmp154;
						ilptmp153 = f1;
						ilptmp154 = ILP_Integer2ILP(3000);
						ilptmp151 = ILP_invoke(ilptmp153, 1, ilptmp154);
					}
					ilptmp152 = ILP_Integer2ILP(8);
					ilptmp144 = ILP_Minus(ilptmp151, ilptmp152);
				}

			}
		}
		return ilptmp144;
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
