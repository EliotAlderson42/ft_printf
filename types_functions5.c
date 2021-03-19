#include <stdarg.h>
#include <unistd.h>

int ft_atoi(char *str)
{
	int i;
	int nb;

	i = 0;
	nb = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = nb * 10 + (str[i] - 48);
		i++;
	}
	return (nb);
}

int	pad_zero(char *str)
{
	int i;
	int j;
	char *nb;

	i = 0;
	j = 0;
	nb = 0;
	while (str[i] < 'a' && str[i] > 'z' || str[i] < 'A' && str[i] > 'Z')
	{
		nb[j] = str[i];
		i++;
		j++;
	}
	j = ft_atoi(nb);
	while ((j - 1) > 0)
		write(1, '0', 1);
	return (i);
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
