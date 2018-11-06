#include <stdio.h>
#include <stdlib.h>
#include "ilp.h"

/* Global variables */
ILP_Object	dou_ble;
ILP_Object	function;
ILP_Object	x;


ILP_Object 
ilp_program()
{
	{
		ILP_Object	ilptmp60;
		ilptmp60 = function;
		{
			ILP_Object	ilptmp61;
			ILP_Object	ilptmp62;
			{
				ILP_Object	ilptmp63;
				ilptmp63 = x;
				ilptmp61 = ILP_invoke(dou_ble, 1, ilptmp63);
			}
			{
				ILP_Object	ilptmp64;
				ILP_Object	ilptmp65;
				ilptmp64 = ILP_Integer2ILP(2);
				ilptmp65 = x;
				ilptmp62 = ILP_Times(ilptmp64, ilptmp65);
			}
			ilptmp60 = ILP_invoke(ilptmp61, 1, ilptmp62);
		}
		{
			ILP_Object	ilptmp66;
			{
				ILP_Object	ilptmp67;
				ILP_Object	ilptmp68;
				ilptmp67 = ILP_Integer2ILP(52);
				ilptmp68 = ILP_Integer2ILP(3);
				ilptmp66 = ILP_Plus(ilptmp67, ilptmp68);
			}
			ilptmp60 = ILP_invoke(dou_ble, 1, ilptmp66);
		}
		return ilptmp60;
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
