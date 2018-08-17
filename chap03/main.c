#include <stdio.h>

int main()
{	
	printf("#include <stdio.h>\n\nint year = 2018;\n\nint main()\n{\n	printf(\"Hello, %%d!\\n\", year);\n	return 0;\n}\n");

	return 0;
}
