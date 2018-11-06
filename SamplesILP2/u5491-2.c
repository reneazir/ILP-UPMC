#include <stdio.h>
#include <stdlib.h>
#include "ilp.h"

/* Global variables */
ILP_Object	f;
ILP_Object	function;
ILP_Object	ma_3angle;


ILP_Object 
ilp_program()
{
	{
		ILP_Object	ilptmp51;
		ilptmp51 = function;
		{
			ILP_Object	ilptmp52;
			ILP_Object	ilptmp53;
			{
				ILP_Object	ilptmp54;
				ilptmp54 = ma_3angle;
				ilptmp52 = ILP_invoke(f, 1, ilptmp54);
			}
			{
				ILP_Object	ilptmp55;
				ILP_Object	ilptmp56;
				ilptmp55 = ma_3angle;
				ilptmp56 = ILP_Integer2ILP(3);
				ilptmp53 = ILP_Divide(ilptmp55, ilptmp56);
			}
			ilptmp51 = ILP_invoke(ilptmp52, 1, ilptmp53);
		}
		{
			ILP_Object	ilptmp57;
			{
				ILP_Object	ilptmp58;
				ILP_Object	ilptmp59;
				ilptmp58 = ILP_Integer2ILP(3);
				ilptmp59 = ILP_Integer2ILP(5491);
				ilptmp57 = ILP_Times(ilptmp58, ilptmp59);
			}
			ilptmp51 = ILP_invoke(f, 1, ilptmp57);
		}
		return ilptmp51;
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
