/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddychus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 15:50:10 by ddychus           #+#    #+#             */
/*   Updated: 2022/12/16 14:30:35 by ddychus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <stdio.h>
# include <sys/wait.h>
# include <fcntl.h>

void	error_msg(char *error);
void	exec(char *argv, char **env);
int		msg(char *err);
void	usage(void);
int		open_file(char *argv, int i);
char	*get_path(char *cmd, char **env);

char	**ft_split(char const *s, char c);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strnstr(const char *big, const char *little, size_t len);
size_t	ft_strlen(const char *str);
int		ft_strchr(const char *str, int searchedChar);
char	**ft_split_quote(char const *s, char c);
char	**ft_split_doublequote(char const *s, char c);
int		ft_strncmp(char *str1, char *str2, size_t len);
void	ft_putstr_fd(char *s, int fd);

#endif
