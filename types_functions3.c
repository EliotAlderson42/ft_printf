#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(long int nb)
{
	if (nb < 0)
	{
		nb = -nb;
	}
	if (nb >= 10)
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
	else
		ft_putchar(nb + '0');
}

void ft_putnbroctal(int nb)
{
	int n;

	n = 8;
	if (nb < 0)
		n *= -1;
	if (nb >= 8)
	{
		ft_putnbroctal(nb / 8);
		ft_putnbroctal(nb % 8);
	}
	else
		ft_putchar(nb + '0');
}

void o_type(va_list *arg_list)
{
	int nbr;

	nbr = va_arg(*arg_list, int);
	ft_putnbroctal(nbr);
}

int main()
{
	printf("%x\n", 2000);
	//ft_putnbroctal(-255);
	return 0;
}


