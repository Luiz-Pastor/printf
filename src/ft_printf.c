#include "../include/modules.h"

static int	print_ph(char ph, va_list arguments)
{
	if (ph == 'c')
		return (ft_print_c(arguments));
	if (ph == 's')
		return (ft_print_s(arguments));
	if (ph == 'd' || ph == 'i')
		return (ft_print_d(arguments));
	if (ph == 'p')
		return (ft_print_p(arguments));
	// if (ph == 'i')
	// 	return (ft_print_i(arguments));
	if (ph == 'u')
		return (ft_print_u(arguments));
	if (ph == 'x')
		return (ft_print_x(arguments));
	if (ph == 'X')
		return (ft_print_xx(arguments));
	if (ph == '%')
		return (write(1, "%", 1));
	return (0);
}

static int	manage(const char *text, va_list variables)
{
	size_t	index;
	int		count;

	index = 0;
	count = 0;
	while (text[index])
	{
		while (text[index] && text[index] != '%')
		{
			count += write(1, &text[index], 1);
			index++;
		}
		if (text[index])
		{
			count += print_ph(text[index + 1], variables);
			index += 2;
		}
	}
	return (count);
}

int	ft_printf(const char *text, ...)
{
	va_list	variables;
	size_t	ph_count;
	int		count;

	if (!text)
		return (0);
	ph_count = placeholder_count(text);
	if ((long long)ph_count == -1)
		return (-1);
	va_start(variables, text);
	count = manage(text, variables);
	va_end(variables);
	return (count);
}
