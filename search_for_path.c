/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_for_path.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jait-chd <jait-chd@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 13:41:44 by jait-chd          #+#    #+#             */
/*   Updated: 2025/02/10 21:39:38 by jait-chd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_free(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

char	*jo_in(char const *s1, char conect, char const *s2)
{
	char	*str;
	size_t	x;
	size_t	y;

	if (!s1 || !s2 || !conect)
		return (NULL);
	str = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 2));
	if (!str)
		return (NULL);
	x = 0;
	y = 0;
	while (s1[y])
		str[x++] = s1[y++];
	str[x++] = conect;
	y = 0;
	while (s2[y])
		str[x++] = s2[y++];
	str[x] = '\0';
	return (str);
}

char	**cut_paths(char *envp[])
{
	int		i;
	char	**paths;

	i = 0;
	while (envp[i])
	{
		if (!ft_strncmp(envp[i], "PATH=", 5))
		{
			paths = ft_split(envp[i] + 5, ':');
			return (paths);
		}
		i++;
	}
	return (NULL);
}

void	execute_cmd(char *cmd, char *envp[])
{
	int		i;
	char	**command;
	char	**paths;
	char	*way;

	i = 0;
	command = ft_split(cmd, ' ');
	paths = cut_paths(envp);
	while (paths[i])
	{
		way = jo_in(paths[i], '/', command[0]);
		if (access(way, F_OK | X_OK) == 0)
		{
			if (execve(way, command, NULL) == -1)
				perror("ERROR in execve func");
			exit(EXIT_FAILURE);
		}
		free(way);
		i++;
	}
	ft_free(command);
	ft_free(paths);
	perror("ERROR");
}
