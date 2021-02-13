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



long int define_negative(long int nb)
{
	long int nb2;
	if (nb < 0)
	{
		nb *= -1;
		nb2 = (4294967295 - nb + 1);
		return (nb2);
	}
	return(nb);
}

void x_types(va_list *arg_list)
{
	unsigned int nb;
	long int nb2;
	int i;
	int cmpt;
	
	nb2 = va_arg(*arg_list, int);
	nb = define_negative(nb2);
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
