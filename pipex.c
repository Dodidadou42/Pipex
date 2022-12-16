/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddychus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 14:26:37 by ddychus           #+#    #+#             */
/*   Updated: 2022/12/13 15:13:03 by ddychus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child_process(char **argv, char **env, int *fd)
{
	int	fdin;

	fdin = open(argv[1], O_RDONLY);
	if (fdin == -1)
		error_msg("pipex: input");
	dup2(fd[1], STDOUT_FILENO);
	dup2(fdin, STDIN_FILENO);
	close(fd[0]);
	exec(argv[2], env);
}

void	parent_process(char **argv, char **env, int *fd)
{
	int	fdout;

	fdout = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0000644);
	if (fdout == -1)
		error_msg("Can't open parent file.");
	dup2(fd[0], STDIN_FILENO);
	dup2(fdout, STDOUT_FILENO);
	close(fd[1]);
	exec(argv[3], env);
}

int	main(int argc, char **argv, char **env )
{
	int		fd[2];
	pid_t	pid1;

	if (env[0] == NULL)
		env[0] = "PATH=/usr/local/bin:/usr/bin:/bin:/usr/sbin:/sbin";
	if (argc != 5)
		return (msg("Wrong argument number."));
	if (pipe(fd) < 0)
		error_msg("Pipe error.");
	pid1 = fork();
	if (pid1 == -1)
		error_msg("Fork error.");
	if (pid1 == 0)
		child_process(argv, env, fd);
	parent_process(argv, env, fd);
	return (0);
}
