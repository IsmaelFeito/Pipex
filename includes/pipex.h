/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifeito-m <ifeito-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 15:43:10 by ifeito-m          #+#    #+#             */
/*   Updated: 2025/02/25 16:29:03 by ifeito-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../includes/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <fcntl.h>
# include <sys/wait.h>

void	check_fork_err(pid_t child_pid, int *pipefd);
void	ft_clean_mem(char **result);
char	*search_comm_in_dirs(char **dirs, char *command);
char	*get_path(char *comm, char **env);
void	run_command(char *input, char **env);
void	pipe_error(void);
void	args_error(void);

#endif