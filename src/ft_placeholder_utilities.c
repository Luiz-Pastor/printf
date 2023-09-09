#include "../include/modules.h"

size_t	placeholder_count(const char *text)
{
	size_t		index;
	long long	count;

	index = 0;
	count = 0;
	while (text[index])
	{
		if (text[index] == '%' && is_placeholder(text[index + 1]))
		{
			count++;
			if (text[index + 1] == '%')
				index++;
		}
		else if (text[index] == '%' && !is_placeholder(text[index + 1]))
			return (-1);
		index++;
	}
	return (count);
}

char	get_nplaceholder(const char *text, long long position)
{
	size_t		index;
	long long	count;

	index = 0;
	count = 0;
	while (text[index])
	{
		if (text[index] == '%')
		{
			count++;
			if (count == position)
				return (text[index + 1]);
			if (text[index + 1] == '%')
				index++;
		}
		index++;
	}
	return ('\0');
}

int	is_placeholder(char ph)
{
	size_t	index;

	index = 0;
	while (PLACEHOLDERS[index])
	{
		if (PLACEHOLDERS[index] == ph)
			return (1);
		index++;
	}
	return (0);
}

static void	reverse_string(char *str)
{
	int		start;
	int		end;
	char	aux;

	start = 0;
	end = 0;
	while (str[end])
		end++;
	end--;
	while (start < end)
	{
		aux = str[start];
		str[start] = str[end];
		str[end] = aux;
		start++;
		end--;
	}
}

void	to_hexa(unsigned long long number, char *buffer, char *dict)
{
	int		i;

	i = 0;
	if (number == 0)
		buffer[i++] = dict[number % 16];
	while (number > 0)
	{
		buffer[i] = dict[number % 16];
		i++;
		number /= 16;
	}
	buffer[i] = '\0';
	reverse_string(buffer);
}
