#include <stdio.h>
#include <stdlib.h>
#include "ilp.h"

/* Global variables */
ILP_Object	even;
ILP_Object	function;
ILP_Object	odd;
ILP_Object	n;


ILP_Object 
ilp_program()
{
	{
		ILP_Object	ilptmp69;
		ilptmp69 = function;
		{
			ILP_Object	ilptmp70;
			ILP_Object	ilptmp71;
			{
				ILP_Object	ilptmp72;
				ilptmp72 = n;
				ilptmp70 = ILP_invoke(odd, 1, ilptmp72);
			}
			{
				ILP_Object	ilptmp73;
				{
					ILP_Object	ilptmp74;
					ILP_Object	ilptmp75;
					ilptmp74 = n;
					ilptmp75 = ILP_Integer2ILP(0);
					ilptmp73 = ILP_Equal(ilptmp74, ilptmp75);
				}
				if (ILP_isEquivalentToTrue(ilptmp73)) {
					ilptmp71 = ILP_FALSE;

				} else {
					{
						ILP_Object	ilptmp76;
						{
							ILP_Object	ilptmp77;
							ILP_Object	ilptmp78;
							ilptmp77 = n;
							ilptmp78 = ILP_Integer2ILP(1);
							ilptmp76 = ILP_Equal(ilptmp77, ilptmp78);
						}
						if (ILP_isEquivalentToTrue(ilptmp76)) {
							ilptmp71 = ILP_TRUE;

						} else {
							{
								ILP_Object	ilptmp79;
								{
									ILP_Object	ilptmp80;
									ILP_Object	ilptmp81;
									ilptmp80 = n;
									ilptmp81 = ILP_Integer2ILP(1);
									ilptmp79 = ILP_Minus(ilptmp80, ilptmp81);
								}
								ilptmp71 = ILP_invoke(even, 1, ilptmp79);
							}

						}
					}

				}
			}
			ilptmp69 = ILP_invoke(ilptmp70, 1, ilptmp71);
		}
		ilptmp69 = function;
		{
			ILP_Object	ilptmp82;
			ILP_Object	ilptmp83;
			{
				ILP_Object	ilptmp84;
				ilptmp84 = n;
				ilptmp82 = ILP_invoke(even, 1, ilptmp84);
			}
			{
				ILP_Object	ilptmp85;
				{
					ILP_Object	ilptmp86;
					ILP_Object	ilptmp87;
					ilptmp86 = n;
					ilptmp87 = ILP_Integer2ILP(0);
					ilptmp85 = ILP_Equal(ilptmp86, ilptmp87);
				}
				if (ILP_isEquivalentToTrue(ilptmp85)) {
					ilptmp83 = ILP_TRUE;

				} else {
					{
						ILP_Object	ilptmp88;
						{
							ILP_Object	ilptmp89;
							ILP_Object	ilptmp90;
							ilptmp89 = n;
							ilptmp90 = ILP_Integer2ILP(1);
							ilptmp88 = ILP_Equal(ilptmp89, ilptmp90);
						}
						if (ILP_isEquivalentToTrue(ilptmp88)) {
							ilptmp83 = ILP_FALSE;

						} else {
							{
								ILP_Object	ilptmp91;
								{
									ILP_Object	ilptmp92;
									ILP_Object	ilptmp93;
									ilptmp92 = n;
									ilptmp93 = ILP_Integer2ILP(1);
									ilptmp91 = ILP_Minus(ilptmp92, ilptmp93);
								}
								ilptmp83 = ILP_invoke(odd, 1, ilptmp91);
							}

						}
					}

				}
			}
			ilptmp69 = ILP_invoke(ilptmp82, 1, ilptmp83);
		}
		{
			ILP_Object	ilptmp94;
			{
				ILP_Object	ilptmp95;
				ilptmp95 = ILP_Integer2ILP(56);
				ilptmp94 = ILP_invoke(odd, 1, ilptmp95);
			}
			ilptmp69 = ILP_Not(ilptmp94);
		}
		return ilptmp69;
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
