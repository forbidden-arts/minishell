/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_filenames.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjaasalo <tjaasalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 11:18:42 by dpalmer           #+#    #+#             */
/*   Updated: 2023/05/25 13:43:58 by tjaasalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <dirent.h>
#include <stdio.h>
#include "libft.h"
#include "parse.h"

static t_vector	*files_try_push(
					t_tokens *matches,
					const char *pattern,
					const char *string);
static BOOL		_pattern_match(
					const char *pattern,
					const char *string,
					int idx_pat,
					int idx_str);
static BOOL		pattern_match(const char *pattern, const char *string);

t_tokens	*token_filenames(const char *pattern)
{
	DIR				*dirp;
	t_tokens		*filenames;
	struct dirent	*dirent;

	filenames = vector_with_capacity(1, sizeof(t_token));
	if (!filenames)
		return (NULL);
	dirp = opendir(".");
	if (!dirp)
	{
		tokens_free(filenames);
		perror("minishell");
		return (NULL);
	}
	dirent = readdir(dirp);
	while (dirent && filenames)
	{
		if (dirent->d_name[0] != '.')
			filenames = files_try_push(filenames, pattern, dirent->d_name);
		dirent = readdir(dirp);
	}
	closedir(dirp);
	return (filenames);
}

static BOOL	pattern_match(const char *pattern, const char *string)
{
	return (_pattern_match(pattern, string, 0, 0));
}

static BOOL	_pattern_match(
	const char *pattern,
	const char *string,
	int idx_pat,
	int idx_str)
{
	if (pattern[idx_pat] == '\0')
		return (string[idx_str] == '\0');
	else if (pattern[idx_pat] == '*')
	{
		while (string[idx_str] != '\0')
		{
			if (_pattern_match(pattern, string, idx_pat + 1, idx_str))
				return (TRUE);
			idx_str++;
		}
		return (_pattern_match(pattern, string, idx_pat + 1, idx_str));
	}
	else if (pattern[idx_pat] != string[idx_str])
		return (FALSE);
	else
		return (_pattern_match(pattern, string, idx_pat + 1, idx_str + 1));
}

static t_vector	*files_try_push(
	t_tokens *matches,
	const char *pattern,
	const char *string)
{
	t_token	token;

	if (pattern_match(pattern, string))
	{
		token.type = token_type_word;
		token.word = ft_strdup(string);
		if (!token.word)
			return (NULL);
		if (!vector_push(matches, &token))
		{
			tokens_free(matches);
			return (NULL);
		}
	}
	return (matches);
}
