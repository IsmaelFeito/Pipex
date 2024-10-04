/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifeito-m <ifeito-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 16:05:41 by ifeito-m          #+#    #+#             */
/*   Updated: 2024/10/04 18:41:41 by ifeito-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/pipex.h"

int main(int argc, char **argv, char **envp)
{
    int fd1[2], fd2;
    __pid_t pid1;
    
    if (argc == 5)
    {
        if(pipe == -1)//comunica entre comandos
            error();
        pid1 = fork();
        if (fork == -1)
            error();
        if(pid1 == 0)//1st son exe 1st command
        {
            close(fd1[WRITE_END]);

            dup2(fd1[WRITE_END], STDOUT_FILENO);
            close(fd1[WRITE_END]);
            
            execlp("/bin/ls", "ls", "-l", NULL);
        }
    }
    else
        ft_putstr_fd("\033[31mError: Bad arguments\n\e[0m", 2);
    return (0);
}