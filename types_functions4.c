#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

void	aff_number(int nb)
{
	char c;

	c = 96;
	if (nb > 9)
	{
		nb -= 9;
		c += nb;
		write(1, &c, 1);
	}
	else
	{
		c = nb + '0';
		write (1, &c, 1);
	}
}

void x_types(va_list *arg_list)
{
	int nb;
	int nb2;
	int i;
	int cmpt;

	nb = va_arg(*arg_list, int);
	nb2 = 1;
	i = 1;
	while (nb2 < nb && (nb2 * 16) <= nb)
	{		
		nb2 *= 16;
		i++;
	}
	while (i-- > 0)
	{
		cmpt = 0;
		while (nb >= nb2 && (nb - nb2) >= 0)
		{
			nb -= nb2;
			cmpt++;
		}
		aff_number(cmpt);
		nb2 /= 16;
	}
}

