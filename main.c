/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: a <a@student.42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/08/19 14:58:54 by elacombe          #+#    #+#             */
/*   Updated: 2014/09/20 06:16:54 by a                ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int main(int argc, char const *argv[])
{
	if (argc == 1)
	{
		/* traitement de l'entrée standard */
		ft_stdin_handle();
	}
	return 0;
}

void	ft_stdin_handle()
{
	int		offset;
	char	buffer[4069];
	read ();
}