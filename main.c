/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jait-chd <jait-chd@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 13:41:33 by jait-chd          #+#    #+#             */
/*   Updated: 2025/02/10 21:25:44 by jait-chd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int c, char **v, char **env)
{
	int	pid1;
	int	pid2;
	int	fd[2];

	if (c != 5)
		perror("Number of Args are not on Point");
	if (pipe(fd) == -1)
		perror("error on pipe");
	pid1 = fork();
	if (pid1 < 0)
		perror("error on pid1");
	if (pid1 == 0)
		first_cmd_execute(fd, v, env);
	pid2 = fork();
	if (pid2 < 0)
		perror("error on pid2");
	if (pid2 == 0)
		second_cmd_execute(fd, v, env);
	close(fd[1]);
	close(fd[0]);
	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);
}
