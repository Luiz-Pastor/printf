#include "../include/modules.h"

int	ft_print_x(va_list argument)
{
	unsigned long long	number;
	char				text[33];
	size_t				index;
	int					count;

	index = 0;
	count = 0;
	number = va_arg(argument, unsigned int);
	to_hexa(number, text, HEXA_MIN);
	while (text[index])
	{
		count += write(1, &text[index], 1);
		index++;
	}
	return (count);
}

int	ft_print_xx(va_list argument)
{
	unsigned long long	number;
	char				text[33];
	size_t				index;
	int					count;

	index = 0;
	count = 0;
	number = va_arg(argument, unsigned int);
	to_hexa(number, text, HEXA_MAX);
	while (text[index])
	{
		count += write(1, &text[index], 1);
		index++;
	}
	return (count);
}
