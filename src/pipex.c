/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifeito-m <ifeito-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 16:05:41 by ifeito-m          #+#    #+#             */
/*   Updated: 2024/11/18 14:13:37 by ifeito-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/pipex.h"

void run_parent(char **av, char **env, int *pipefd)
{
	int	output_fd;

	output_fd=open(av[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (output_fd<0)
	{
		perror("ERROR OPENING OUTPUT FILE");
		close(pipefd[RD]);
		close(pipefd[WRT]);
		exit(1);
	}
	dup2(output_fd, STDIN_FILENO);
	dup2(pipefd[RD], STDOUT_FILENO);
	close(pipefd[RD]);
	close(pipefd[WRT]);
	close(output_fd);
	run_command(av[3], env);
}

void run_child(char **av, char **env, int *pipefd)
{
	int		input_fd;
	
	input_fd=open(av[WRT], O_RDONLY);
	if (input_fd<0)
	{
		perror("ERROR OPENING INPUT FILE");
		close(pipefd[RD]);
		close(pipefd[WRT]);
		exit(1);
	}
	dup2(input_fd, STDIN_FILENO);
	dup2(pipefd[WRT], STDOUT_FILENO);
	close(pipefd[RD]);
	close(pipefd[WRT]);
	run_command(av[2], env);
}
void	exec_pipes_lines(char **av, char **env)
{
	int 	pipefd[2];
	pid_t	child_pid;

	if(pipe(pipefd) < 0)
		pipe_err();
	child_pid= fork();
	if (child_pid<0)
	{
		close(pipefd[RD]);
		close(pipefd[WRT]);
		perror("FORK ERROR");
		exit(1);
	}
	if (child_pid==0)
		run_child(av, env, pipefd);
	close(pipefd[1]);
	waitpid(child_pid, NULL, 0);
	run_parent(av, env, pipefd);
}

int	main(int ac, char **av, char **env)
{
	if (ac==5)
		exec_pipes_lines(av, env);
	else
		av_error();
	return 0;
}