/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_header.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: a <a@student.42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/08/18 15:46:38 by elacombe          #+#    #+#             */
/*   Updated: 2014/09/20 06:12:09 by a                ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef			FT_HEADER_H
# define		FT_HEADER_H
# include		<unistd.h>
# include		<stdlib.h>
# include		<stdio.h>
# include		<sys/types.h>
# include		<sys/stat.h>
# include		<fcntl.h>
# define		BUFF_SIZE	4096

typedef struct	s_params
{
	int			height;
	int			width;
	int			error;
	int			index_panda;
	char		obstacle;
	char		empty;
	char		full;
	char		*str;
	int			*strint;
	int			max;
	int			pos;
}				t_params;

t_params		*ft_struct(int call);

#endif
