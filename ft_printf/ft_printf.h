/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 07:14:20 by rbutzke           #+#    #+#             */
/*   Updated: 2024/06/20 07:15:55 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FT_PRINTF_H
 # define FT_PRINTF_H
#include <unistd.h>
#include <stdarg.h>

int	ft_printf(const char *str, ...);

#endif 