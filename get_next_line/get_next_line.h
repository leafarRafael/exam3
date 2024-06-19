/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 11:16:10 by rbutzke           #+#    #+#             */
/*   Updated: 2024/06/19 11:33:30 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
 #define GET_NEXT_LINE_H
 
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>

#ifndef BUFFER_SIZE 
 #define BUFFER_SIZE 10

char	*get_next_line(int fd);

#endif
#endif