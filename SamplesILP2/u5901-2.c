#include <stdio.h>
#include <stdlib.h>
#include "ilp.h"

/* Global variables */
ILP_Object	pseudosequence;
ILP_Object	y_3d;
ILP_Object	function;
ILP_Object	foo;
ILP_Object	one;
ILP_Object	x;
ILP_Object	y;
ILP_Object	two;


ILP_Object 
ilp_program()
{
	{
		ILP_Object	ilptmp106;
		ilptmp106 = function;
		{
			ILP_Object	ilptmp107;
			ILP_Object	ilptmp108;
			{
				ILP_Object	ilptmp109;
				ilptmp109 = x;
				ilptmp107 = ILP_invoke(foo, 1, ilptmp109);
			}
			{
				ILP_Object	ilptmp110;
				ILP_Object	ilptmp111;
				ilptmp110 = ILP_Integer2ILP(2);
				ilptmp111 = x;
				ilptmp108 = ILP_Times(ilptmp110, ilptmp111);
			}
			ilptmp106 = ILP_invoke(ilptmp107, 1, ilptmp108);
		}
		ilptmp106 = function;
		{
			ILP_Object	ilptmp112;
			ILP_Object	ilptmp113;
			ilptmp112 = one;
			ilptmp113 = two;
			ilptmp106 = ILP_invoke(pseudosequence, 2, ilptmp112, ilptmp113);
		}
		ilptmp106 = two;
		{
			ILP_Object	ilptmp114;
			ilptmp114 = ILP_Integer2ILP(11);

			{
				ILP_Object	y1 = ilptmp114;
				ilptmp106 = foo;

			}
		}
		{
			ILP_Object	ilptmp115;
			ilptmp115 = pseudosequence;
			{
				ILP_Object	ilptmp116;
				{
					ILP_Object	ilptmp117;
					ilptmp117 = y_3d;
					{
						ILP_Object	ilptmp118;
						ILP_Object	ilptmp119;
						ilptmp118 = y;
						ilptmp119 = ILP_Integer2ILP(1);
						ilptmp117 = ILP_Plus(ilptmp118, ilptmp119);
					}
					ilptmp116 = ilptmp117;
				}
				ilptmp116 = y;
				ilptmp115 = ilptmp116;
			}
			ilptmp106 = ilptmp115;
		}
		return ilptmp106;
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
