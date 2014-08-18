/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_header.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollier <pollier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/08/18 15:46:38 by elacombe          #+#    #+#             */
/*   Updated: 2014/08/18 23:56:15 by pollier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		FT_HEADER_H
# define	FT_HEADER_H
# include	<unistd.h>
# include	<stdlib.h>
# include	<sys/types.h>
# include	<sys/stat.h>
# include	<fcntl.h>
# define	BUFF_SIZE	4096

int		ft_atoi(char *s1);
void	ft_putchar(char c);
void	ft_putstr(char *str);
void	ft_putnbr(int x);
char	**ft_make_tab(char *str, int x, int y);
int		ft_check_empty (char **tab, int off_x, int off_y, int size, char empty);
int		ft_biggest_offset_x (int x, int y);
int		ft_biggest_offset_y (int x, int y);
int		ft_biggest_square (int x, int y);
int		ft_gps(char **tab, int size_x, int size_y, int sqr_size, char empty);

#endif
