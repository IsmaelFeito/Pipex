/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifeito-m <ifeito-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 14:11:49 by ifeito-m          #+#    #+#             */
/*   Updated: 2024/11/18 15:31:11 by ifeito-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../includes/pipex.h>

char **search_comm_in_dirs(char ** dirs, char *command)
{
	char	*temp_pth;
	char	*full_pth;
	int		i;

	i = 0;
	while (dirs[i])
	{
		temp_pth = ft_strjoin(dirs[i], '/');
		full_pth = ft_strjoin(temp_pth, command);
		free(temp_pth);
		if (access(full_pth, F_OK) == 0)
			return (full_pth);
		free(full_pth);
		i++;
	}
	return (NULL);
}

char **get_path(char *comm, char **env)
{
	char **dirs;
	char **full_pth;
	int i;

	i=0;
	while (env[i] && !ft_strnstr(env[i], "PATH", 4))
		i++;
	if (!env[i])
		return (NULL);
	dirs = ft_split(env[i] + 5, ':');
	if (!dirs)
		return (NULL);
	full_pth = search_comm_in_dirs(dirs, comm);
	i = 0;
	while (dirs[i])
		free(dirs[i++]);
	free(dirs);
	return (full_pth);
}

void run_command(char *input, char **env)
{
	char **comm;
	char **comm_pth;

	comm = ft_split(input, ' ');
	comm_pth = get_path(comm[0], env);

	if (!comm_pth)
	{
		while (*comm)
			free(*comm);
		free(comm);
		perror("Command not found");
		exit(127);
	}
	execve(comm_pth, comm, env);
	perror("Exec failed");
	free(comm_pth);
	while (*comm)
		free(*comm++);
	free(comm);
	exit(1);
}