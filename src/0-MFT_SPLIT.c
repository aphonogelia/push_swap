/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0-MFT_SPLIT.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htharrau <htharrau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 10:35:22 by htharrau          #+#    #+#             */
/*   Updated: 2024/07/05 19:58:16 by htharrau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* char **ft_split(char const *s, char c);
Parameters s: The string to be split. c: The delimiter character.
Return value The array of new strings resulting from the split.
NULL if the allocation fails.
External functs. malloc, free
Description Allocates (with malloc(3)) and returns an array of strings obtained 
by splitting ’s’ using the character ’c’ as a delimiter. The array must end
with a NULL pointer. */

#include "push_swap.h"

static int	ft_nbarray(const char *s, char c)
{
	int		count;
	size_t	i;

	count = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] && s[i] != c)
			count++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (count);
}

static void	free_matrix(char **matrix, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		free(matrix[i]);
		i++;
	}
	free(matrix);
}

static char	**sub_matrix(char **matrix, char const *s, char c, int count)
{
	int		j;
	size_t	substring;

	j = 0;
	while (j < count && *s)
	{
		while (*s == c)
			s++;
		if (!*s)
			break ;
		substring = 0;
		while (s[substring] && s[substring] != c)
			substring++;
		matrix[j] = (char *)malloc((substring + 1) * sizeof(char));
		if (matrix[j] == NULL)
			return (free_matrix(matrix, j), NULL);
		j++;
		s += substring;
	}
	return (matrix);
}

static char	**fill_matrix(char **matrix, char const *s, char c, int count)
{
	int		j;
	size_t	k;
	size_t	substring;

	j = 0;
	while (j < count && *s)
	{
		while (*s == c)
			s++;
		substring = 0;
		while (s[substring] && s[substring] != c)
			substring++;
		k = 0;
		while (k < substring)
		{
			matrix[j][k] = s[k];
			k++;
		}
		matrix[j][k] = '\0';
		j++;
		s += substring;
	}
	matrix[j] = NULL;
	return (matrix);
}

char	**ft_split(char const *s, char c)
{
	char	**matrix;
	int		count;

	if (!s || !*s)
		return (NULL);
	count = ft_nbarray(s, c);
	matrix = (char **)malloc((count + 1) * sizeof(char *));
	if (!matrix)
		return (NULL);
	if (!sub_matrix(matrix, s, c, count) || !fill_matrix(matrix, s, c, count))
		return (NULL);
	return (matrix);
}
