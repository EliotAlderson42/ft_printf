#include <stdarg.h>
#include <unistd.h>

void	putunnbr(unsigned int nbr)
{
	int nb2;
	int i;
	char *res[11];

	nb2 = nbr;
	i = 0;
	res[11] = '\0';

}

void	u_types(va_list *arg_list)
{
	unsigned int nb;
	unsigned int nb2;

	nb = va_arg(*arg_list, unsigned long);
	nb2 = 4294967295;
	if(nb < 0)
	{
		nb *= -1;
		nb2 -= nb;
		ft_putnbr(nb2);
	}
	else
		ft_putnbr(nb);
}

void	p_types(va_list *arg_list)
{
	unsigned long	adr;
	char		*base;
	char		res[13];
	int		i;

	adr = va_arg(*arg_list, unsigned long);
	base = "0123456789abcdef";
	i = 12;
	res[13] = '\0';
	while ((adr / 16) > 0 || i >= 12)
	{
		res[i] = base[(adr % 16)];
		adr /= 16;
		i--;
	}
	res[i] = base[(adr % 16)];
	write(1, "0x", 2);
	while (i <= 12)
		write(1, &res[i++], 1);
}
