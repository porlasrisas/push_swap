/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guigonza <guigonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 14:58:55 by guigonza          #+#    #+#             */
/*   Updated: 2024/11/13 13:30:50 by guigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# ifndef MAX_FD
#  define MAX_FD 1024
# endif

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(int fd);
char	*ft_strdup_gnl(const char *s);
size_t	ft_strlen_gnl(const char *s);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_gnljoin(char *s1, char *s2);
char	*ft_strchr_gnl(const char *s, int c);
#endif
