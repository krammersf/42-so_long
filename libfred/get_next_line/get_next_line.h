/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-carv <fde-carv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 17:04:25 by fde-carv          #+#    #+#             */
/*   Updated: 2023/07/28 18:49:43 by fde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif
// GET NEXT LINE UTILS
int		strlen_at(char *s, char c);
int		have_newline(char *s);
char	*ft_strncpy(char *dst, char *src, int n);
char	*ft_strjoin2(char *prev, char *curr);
// GET NEXT LINE
char	*get_keep(char *buffer);
char	*get_line(char *buffer);
char	*get_next_line(int fd);

#endif
