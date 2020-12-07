#include <stdio.h>
#include <unistd.h>

int ft_get_size2(float nb)
{
	int i;
	int n;

	i = 0;
	n = nb;
	while (nb != n)
	{
		printf("%d , %f\n", n, nb);
		nb *= 10;
		n = nb;
		i++;
	}
	return i;
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

/*static int		ft_get_size(unsigned int n)
{
	int		size;

	size = 0;
	while (n >= 10)
	{
		n /= 10;
		size++;
	}
	size++;
	return (size);
}

char			*ft_itoa(float n)
{
	float	nb;
	char			*str;
	int				size;

	size = 0;
	if (n >= 0)
		nb = n;
	if (n < 0)
	{
		nb = -1 * n;
		size++;
	}
	size = size + ft_get_size(nb);
	if (!(str = malloc(size * sizeof(char) + 1)))
		return (0);
	str[size] = '\0';
	while (size--)
	{
		if (nb >= 0)
			str[size] = (nb % 10) + '0';
		if (size == 0 && n < 0)
			str[size] = '-';
		nb /= 10;
	}
	return (str);
}
*/
int main()
{
	float a = 12.54;
	int b = a;
	//if (a != b)
	printf("%o", -25);
	//printf("%d", o_type(255));
//	o_type(255);
	return 0;	
}
