/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddychus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 14:31:37 by ddychus           #+#    #+#             */
/*   Updated: 2022/12/13 15:20:03 by ddychus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	error_msg(char *error)
{
	perror(error);
	exit(EXIT_FAILURE);
}

int	msg(char *err)
{
	write(2, err, ft_strlen(err));
	return (1);
}

char	*get_path(char *cmd, char **env)
{
	int		i;
	char	**paths;
	char	*path;
	char	*temp;

	i = 0;
	while (ft_strnstr(env[i], "PATH", 4) == 0)
		i++;
	paths = ft_split(env[i] + 5, ':');
	i = 0;
	while (paths[i])
	{
		temp = ft_strjoin(paths[i], "/");
		path = ft_strjoin(temp, cmd);
		free(temp);
		if (access(path, F_OK) == 0)
			return (path);
		free(path);
		i++;
	}
	return (0);
}

char	**get_cmd(char *argv)
{
	char	**cmd;

	if (ft_strchr(argv, 39) && ft_strchr(argv, 34))
	{
		if (ft_strchr(argv, 39) > ft_strchr(argv, 34))
			cmd = ft_split_doublequote(argv, ' ');
		else
			cmd = ft_split_quote(argv, ' ');
	}
	else if (ft_strchr(argv, 39))
		cmd = ft_split_quote(argv, ' ');
	else if (ft_strchr(argv, 34))
		cmd = ft_split_doublequote(argv, ' ');
	else
		cmd = ft_split(argv, ' ');
	return (cmd);
}

void	exec(char *argv, char **env)
{
	char	**cmd;
	char	*path;
	int		i;

	i = -1;
	cmd = get_cmd(argv);
	path = get_path(cmd[0], env);
	if (!path)
	{
		while (cmd[++i])
			free(cmd[i]);
		free(cmd);
		if (argv[0] == 'f')
			msg("pipex: fizzBuzz: command not found\n");
		else if (argv[0] == 'b')
			msg("pipex: buzzFizz: command not found\n");
		exit(127);
	}
	if (execve(path, cmd, env) == -1)
		error_msg("Couldn't execute.");
}
