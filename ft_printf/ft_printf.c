/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 07:16:01 by rbutzke           #+#    #+#             */
/*   Updated: 2024/06/20 07:46:05 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_putnbr_b(unsigned int nb, int *x, char *base);
static void	ft_manager(char c, va_list *ap, int *x);
static void	ft_putstr(char *str, int *x);
static void	ft_putchar(char c, int *x);
static void	ft_putnbr(int nb, int *x);

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	int		x;
	int		i;

	if (!str)
		return (-1);
	x = 0;
	i = 0;
	va_start(ap, str);
	while (str[i])
	{
		if (str[i] == '%')
			ft_manager(str[++i],  &ap, &x);
		else
			ft_putchar(str[i], &x);
		i++;
	}
	va_end(ap);
	return (x);
}

static void	ft_manager(char c, va_list *ap, int *x)
{
	if (c == 's')
		ft_putstr(va_arg(*ap, char *), x);	
	if (c == 'd')
		ft_putnbr(va_arg(*ap, int), x);
	if (c == 'x')
		ft_putnbr_b(va_arg(*ap, unsigned int), x, "0123456789abcdef");
}

static void	ft_putchar(char c, int *x)
{
	(*x)++;
	write(1, &c, 1);
}

static void	ft_putstr(char *str, int *x)
{
	if (!str)
		ft_putstr("(null)", x);
	else
	{
		while (*str)
			ft_putchar(*str++, x);
	}
}

static void	ft_putnbr(int nb, int *x)
{
	long	nbr;

	nbr = (long) nb;
	if (nbr < 0)
	{
		ft_putchar('-', x);
		nbr = -nbr;
	}
	if (nbr > 9)
	{
		ft_putnbr(nbr / 10, x);
		ft_putnbr(nbr % 10, x);
	}
	else
		ft_putchar(nbr + '0', x);
}


static void	ft_putnbr_b(unsigned int nb, int *x, char *base)
{
	if (nb > 15)
	{
		ft_putnbr_b(nb / 16, x, base);
		ft_putnbr_b(nb % 16, x, base);
	}
	else
		ft_putchar(base[nb], x);
}