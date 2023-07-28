/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aech-che <aech-che@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 14:14:38 by aech-che          #+#    #+#             */
/*   Updated: 2023/07/28 18:51:20 by aech-che         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
#define CUB_H

#include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

typedef struct t_cub_data
{
	char *map_name;
}	t_cub_data;



size_t	ft_strlen(char *s);
char	*ft_substr(char *s, int start, size_t len);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strdup(char *s1);
void    show_errors(char *message);
int    start_game(t_cub_data *cb_data);
int    read_map(t_cub_data *cb_data);
#endif