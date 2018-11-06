#include <stdio.h>
#include <stdlib.h>
#include "ilp.h"

/* Global variables */
ILP_Object	apply;
ILP_Object	f;
ILP_Object	function;
ILP_Object	x;
ILP_Object	deuxfois;


ILP_Object 
ilp_program()
{
	{
		ILP_Object	ilptmp155;
		ilptmp155 = function;
		{
			ILP_Object	ilptmp156;
			ilptmp156 = x;
			ilptmp155 = ILP_invoke(deuxfois, 1, ilptmp156);
		}
		{
			ILP_Object	ilptmp157;
			ILP_Object	ilptmp158;
			ilptmp157 = ILP_Integer2ILP(2);
			ilptmp158 = x;
			ilptmp155 = ILP_Times(ilptmp157, ilptmp158);
		}
		ilptmp155 = function;
		{
			ILP_Object	ilptmp159;
			ILP_Object	ilptmp160;
			ilptmp159 = f;
			ilptmp160 = x;
			ilptmp155 = ILP_invoke(apply, 2, ilptmp159, ilptmp160);
		}
		{
			ILP_Object	ilptmp161;
			ilptmp161 = x;
			ilptmp155 = ILP_invoke(f, 1, ilptmp161);
		}
		{
			ILP_Object	ilptmp162;
			ILP_Object	ilptmp163;
			{
				ILP_Object	ilptmp164;
				ILP_Object	ilptmp165;
				ilptmp164 = deuxfois;
				ilptmp165 = ILP_Integer2ILP(3000);
				ilptmp162 = ILP_invoke(apply, 2, ilptmp164, ilptmp165);
			}
			ilptmp163 = ILP_Integer2ILP(7);
			ilptmp155 = ILP_Minus(ilptmp162, ilptmp163);
		}
		return ilptmp155;
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
