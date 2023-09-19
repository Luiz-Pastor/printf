#include "../include/modules.h"

int	ft_print_p(va_list arguments)
{
	void	*elem;
	char	text[100];
	int		count;
	size_t	index;

	index = 0;
	elem = va_arg(arguments, void *);
	if (!elem)
		return (write(1, "(nil)", 5));
	to_hexa((unsigned long long) elem, text, HEXA_MIN);
	write(1, "0x", 2);
	count = 2;
	while (text[index])
	{
		count += write(1, &text[index], 1);
		index++;
	}
	return (count);
}
