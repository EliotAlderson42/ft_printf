#include <stdarg.h>
#include <unistd.h>

void	u_types(va_list *arg_list)
{
	
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
	return ;
}
