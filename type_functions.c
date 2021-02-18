/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhouari <yhouari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 06:17:36 by yhouari           #+#    #+#             */
/*   Updated: 2021/02/14 18:42:02 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>

void	x_types(va_list *arg_list);
void	p_types(va_list *arg_list);

void	ft_putchar(char c)
{
	write (1, &c, 1);
}

void	ft_putstr(char *str)
{
	int i;

	i = 0;
	while(str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

void	ft_putnbr(int nb)
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

void	nbr_function(va_list *arg_list)
{
	int nbr;

	nbr = va_arg(*arg_list, int);
	ft_putnbr(nbr);
}

void	charactere_function(va_list *arg_list)
{
	char c;

	c = va_arg(*arg_list, int);
	write(1, &c, 1);
}

void	str_function(va_list *arg_list)
{
	char *string;

	string = va_arg(*arg_list, char *);
	ft_putstr(string);
}

int	find_index(char *tab, char c)
{
	int i;

	i = 0;
	if (c == 'i')
		return (0);
	while (tab[i] != 0)
	{
		if(tab[i] == c)
			return(i);
		i++;
	}
	return (-1);
}


int	ft_printf(const char *src, ...)
{
	char tabIndex[6] = {'d', 'c', 's', 'x', 'p', 0};
	void (*tabFunctions[5])(va_list *) = {nbr_function, charactere_function, str_function, x_types, p_types};
	va_list arg_list;
	int i;
	int tmp;

	va_start(arg_list, src);
	i = 0;
	while (src[i])
	{
		if (src[i] == '%')
		{
			tmp = find_index(tabIndex, src[i + 1]);
			if (tmp != -1)
				(*tabFunctions[tmp])(&arg_list);
			i++;
		}
		else if (src[i] != '%')
			write(1, &src[i], 1);
		i++;
	}
	return (0);
}

int main()
{
	int nbr = 21;
	char c = 'y';
	char *str = "saint-denis";
	//ft_printf("%p*\n", str);
	
	//nbr = printf("%i %c %s", 43, c, str);
	printf("%u/", -10);
	return (0);
}
