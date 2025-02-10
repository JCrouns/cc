/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmdds_exec.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jait-chd <jait-chd@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 13:41:18 by jait-chd          #+#    #+#             */
/*   Updated: 2025/02/10 21:00:50 by jait-chd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	first_cmd_execute(int *fd, char **v, char **env)
{
	int	infile;

	infile = open(v[1], O_RDONLY);
	if (infile < 0)
		perror("Eroor in infile");
	if (dup2(infile, STDIN_FILENO) == -1)
		perror("error on infile (dup2)");
	close(infile);
	if (dup2(fd[1], STDOUT_FILENO) == -1)
		perror("error on fd1 (dup2)");
	close(fd[0]);
	close(fd[1]);
	execute_cmd(v[2], env);
}

void	second_cmd_execute(int *fd, char **v, char **env)
{
	int	outfile;

	outfile = open(v[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (outfile < 0)
		perror("error in outfile");
	if (dup2(fd[0], STDIN_FILENO) == -1)
		perror("error on fd0 (dup2)");
	close(fd[1]);
	close(fd[0]);
	if (dup2(outfile, STDOUT_FILENO) == -1)
		perror("error on outfile (dup2)");
	close(outfile);
	execute_cmd(v[3], env);
}
