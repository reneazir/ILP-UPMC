#include <stdio.h>
#include <stdlib.h>
#include "ilp.h"

/* Global variables */
ILP_Object	g_3d;
ILP_Object	f;
ILP_Object	function;
ILP_Object	g;
ILP_Object	x;
ILP_Object	deuxfois;


ILP_Object 
ilp_program()
{
	{
		ILP_Object	ilptmp178;
		ilptmp178 = function;
		{
			ILP_Object	ilptmp179;
			ilptmp179 = x;
			ilptmp178 = ILP_invoke(deuxfois, 1, ilptmp179);
		}
		{
			ILP_Object	ilptmp180;
			ILP_Object	ilptmp181;
			ilptmp180 = ILP_Integer2ILP(2);
			ilptmp181 = x;
			ilptmp178 = ILP_Times(ilptmp180, ilptmp181);
		}
		{
			ILP_Object	ilptmp182;
			ilptmp182 = deuxfois;

			{
				ILP_Object	f1 = ilptmp182;
				ilptmp178 = g_3d;

			}
		}
		ilptmp178 = f;
		{
			ILP_Object	ilptmp183;
			ILP_Object	ilptmp184;
			{
				ILP_Object	ilptmp185;
				ilptmp185 = ILP_Integer2ILP(3000);
				ilptmp183 = ILP_invoke(g, 1, ilptmp185);
			}
			ilptmp184 = ILP_Integer2ILP(5);
			ilptmp178 = ILP_Minus(ilptmp183, ilptmp184);
		}
		return ilptmp178;
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
