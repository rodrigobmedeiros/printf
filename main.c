#include <stdio.h>
#include <limits.h>
int     main()
{
        // Teste com argumento nulo para strings
        ft_printf("Teste with argument \"(NULL)\"\n");
        printf("number of printed chars - system: %d\n", printf(" NULL %s NULL ", NULL));
        printf("number of printed chars - custom: %d\n", ft_printf(" NULL %s NULL ", NULL));
        ft_printf("\n");

        // Teste with input "(NULL)" without other parameters
        ft_printf("Teste with input \"(NULL)\"\n");
        printf("number of printed chars - system: %d\n", printf((NULL)));
        printf("number of printed chars - custom: %d\n", ft_printf((NULL)));
        ft_printf("\n");

        // Teste pointer with LONG_MIN and LONG_MAX
        ft_printf("Test with with p and LONG_MIN and LONG_MAX\n");
        printf("number of printed chars - system: %d\n", printf(" %p %p ", LONG_MIN, LONG_MAX));
        printf("number of printed chars - custom: %d\n", ft_printf(" %p %p ", LONG_MIN, LONG_MAX));
        ft_printf("\n");

        // Teste pointer with LONG_MIN and LONG_MAX
        ft_printf("Test with with p and ULONG_MAX\n");
        printf("number of printed chars - system: %d\n", printf(" %p %p ", ULONG_MAX, -ULONG_MAX));
        printf("number of printed chars - custom: %d\n", ft_printf(" %p %p ", ULONG_MAX, -ULONG_MAX));
        ft_printf("\n");

        // Teste pointer with value 0
        ft_printf("Test with pointer value 0\n");
        printf("number of printed chars - system: %d\n", printf(" %p ", 0));
        printf("number of printed chars - custom: %d\n", ft_printf(" %p ", 0));
        ft_printf("\n");

	// Teste with input "(NULL)" and char0
        ft_printf("Teste with input \"(NULL)\" and (char)0\n");
        printf("number of printed chars - system: %d\n", printf((NULL), (char)0));
        printf("number of printed chars - custom: %d\n", ft_printf((NULL), (char)0));
        ft_printf("\n");

	// Teste c null
	ft_printf("Teste com c e input nulo (char)0\n");
        printf("number of printed chars - system: %d\n", printf("rodrigo%c bernardo\n", (char)0));
        printf("number of printed chars - custom: %d\n", ft_printf("rodrigo%c bernardo\n", (char)0));
	ft_printf("\n");
	// Teste para multiplos caracteres
	printf("number of printed chars - system: %d\n", printf("rodrigo%c - %c\n", 'A', 'B'));
	printf("number of printed chars - custom: %d\n", ft_printf("rodrigo%c - %c\n", 'A', 'B'));

	// Teste para uma string
	printf("number of printed chars - system: %d\n", printf("rodrigo - %s\n", "RODRIGO"));
	printf("number of printed chars - custom: %d\n", ft_printf("rodrigo - %s\n", "RODRIGO"));

 	// Teste para multiplas string
 	printf("number of printed chars - system: %d\n", printf("rodrigo - %s %s\n", "RODRIGO", "BERNARDO"));
 	printf("number of printed chars - custom: %d\n", ft_printf("rodrigo - %s %s\n", "RODRIGO", "BERNARDO"));

	// Teste para imprimir percentual
 	printf("number of printed chars - system: %d\n", printf("rodrigo - %%\n"));
 	printf("number of printed chars - custom: %d\n", ft_printf("rodrigo - %%\n"));

	// Teste para imprimir inteiros com %d
	printf("number of printed chars - system: %d\n", printf("rodrigo - %d\n", 11));
	printf("number of printed chars - custom: %d\n", ft_printf("rodrigo - %d\n", 11));

        // Teste para imprimir multiplos inteiros com %d
        printf("number of printed chars - system: %d\n", printf("rodrigo - %d %d\n", 11, 123));
        printf("number of printed chars - custom: %d\n", ft_printf("rodrigo - %d %d\n", 11, 123));

        int num = 10;
        // Teste para imprimir endereco na memoria
        printf("number of printed chars - system: %d\n", printf("address: %p\n", &num));
        printf("number of printed chars - custom: %d\n", ft_printf("address: %p\n", &num));

        num = 0xabcdef;
        // Teste para imprimir hexadecimal lower case
        printf("number of printed chars - system: %d\n", printf("address: %x\n", num));
        printf("number of printed chars - custom: %d\n", ft_printf("address: %x\n", num));

        // Teste para imprimir hexadecimal upper case
        printf("number of printed chars - system: %d\n", printf("address: %X\n", num));
        printf("number of printed chars - custom: %d\n", ft_printf("address: %X\n", num));

        // Teste para imprimir inteiros com %i
        printf("number of printed chars - system: %d\n", printf("rodrigo - %i\n", 11));
        printf("number of printed chars - custom: %d\n", ft_printf("rodrigo - %i\n", 11));

        // Teste para imprimir multiplos inteiros com %i
        printf("number of printed chars - system: %d\n", printf("rodrigo - %i %i\n", 11, 123));
        printf("number of printed chars - custom: %d\n", ft_printf("rodrigo - %i %i\n", 11, 123));

        // Teste para imprimir inteiros com %u
        printf("number of printed chars - system: %d\n", printf("rodrigo - %u\n", 11));
        printf("number of printed chars - custom: %d\n", ft_printf("rodrigo - %u\n", 11));

        // Teste para imprimir inteiros com %u passando numeros negativos
	printf("Test with negative numbers\n");
        printf("number of printed chars - system: %d\n", printf("rodrigo - %u\n", -1));
        printf("number of printed chars - custom: %d\n", ft_printf("rodrigo - %u\n", -1));

        // Teste para imprimir inteiros com %u passando numeros negativos
        printf("Test with negative numbers\n");
        printf("number of printed chars - system: %d\n", printf("rodrigo - %u\n", -9));
        printf("number of printed chars - custom: %d\n", ft_printf("rodrigo - %u\n", -9));

        // Teste para imprimir multiplos inteiros com %i
        printf("number of printed chars - system: %d\n", printf("rodrigo - %i %i\n", 11, 123));
        printf("number of printed chars - custom: %d\n", ft_printf("rodrigo - %i %i\n", 11, 123));

        // Teste para imprimir hexadecimal lower case extreme case
        printf("number of printed chars - system: %d\n", printf("address: %x\n", INT_MAX));
        printf("number of printed chars - custom: %d\n", ft_printf("address: %x\n", INT_MAX));

        // Teste para imprimir hexadecimal lower case extreme case
        printf("number of printed chars - system: %d\n", printf("address: %x\n", LONG_MAX));
        printf("number of printed chars - custom: %d\n", ft_printf("address: %x\n", LONG_MAX));
}
