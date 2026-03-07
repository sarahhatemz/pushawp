#include <stdlib.h>
#include<stdio.h>
void ps_free_tokens(char **tokens)
{ 
    int i;
    i=0;
    if (!tokens)
        return ;
    while(tokens[i])
    {  
    free(tokens[i]);
    i++;
    }
    free(tokens);
}

    int	ps_count_tokens(int argc, char **argv)
{
	int		i;
	int		j;
	int		total;
	char	**split;

	total = 0;
	i = 1;
	while (i < argc)
	{
		split = ft_split(argv[i], ' ');
		if (!split)
			return (-1);
		if (split[0] == NULL)
		{
			ps_free_tokens(split);
			return (-1);
		}
		j = 0;
		while (split[j])
		{
			total++;
			j++;
		}
		ps_free_tokens(split);
		i++;
	}
	return (total);
}


static void	ps_free_partial(char **tokens, int count)
{
	int	i;

	if (!tokens)
		return;
	i = 0;
	while (i < count)
	{
		free(tokens[i]);
		i++;
	}
	free(tokens);
}

char	**ps_tokenize(int argc, char **argv)
{
	int		total;
	char	**tokens;
	int		i;
	int		j;
	int		k;
	char	**split;

	total = ps_count_tokens(argc, argv);
	if (total == -1)
	{
	ft_putendl_fd("Error",2);
		return (NULL);
	}

	tokens = (char **)malloc((total + 1) * sizeof(char *));
	if (!tokens)
	{
		ft_putendl_fd("Error",2);
		return (NULL);
	}
	i = 1;
	k = 0;
	while (i < argc)
	{
		split = ft_split(argv[i], ' ');
		if (!split || split[0] == NULL)
		{
			if (split)
				ps_free_tokens(split);
			ps_free_partial(tokens, k);
			ft_putendl_fd("Error",2);
			return (NULL);
		}
		j = 0;
		while (split[j])
		{
			tokens[k] = ft_strdup(split[j]);
			if (!tokens[k])
			{
				ps_free_tokens(split);
				ps_free_partial(tokens, k);
				ft_putendl_fd("Error",2);
				return (NULL);
			}
			k++;
			j++;
		}
		ps_free_tokens(split);
		i++;
	}
	tokens[k] = NULL;
	return (tokens);
}
int	check(const char *str)
{
	int	i;

	i = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (!(str[i] >= '0' && str[i] <= '9'))
		return (0);
	while (str[i] >= '0' && str[i] <= '9')
		i++;
	if (str[i] != '\0')
		return (0);
	return (1);
}
long ps_atoi_long(const char *nptr)
{
	int	i;
	long	sum;
	int	sign;
	long result; 

	i = 0;
	sum = 0;
	sign = 1;
	while (nptr[i] == ' ' || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign = -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		sum = (sum * 10) + (nptr[i] - '0');
		i++;
	}
	if(nptr[i] != '\0')
		return(99999999999999);
	result=sum*sign;
	return (result);
}
int	ps_atoi_checked(const char *s, int *out)
{
	long	res;

	if (!check(s))
		return (0);
	res = ps_atoi_long(s);
	if (res > __INT_MAX__ || res < __INT_MIN__)
		return (0);
	*out = (int)res;
	return (1);
}
int	*ps_tokens_to_numbers(char **tokens)
{
	int i;
	int count ;
	int *store;

	i=0;
	count =0;
	while(tokens[i])
	{
		i++;
		count++;
	}
	store=malloc(count *sizeof(int));
	if (!store)
		return (NULL);
	i=0;
	while(tokens[i])
	{
		if (!ps_atoi_checked(tokens[i], &store[i]))
		{
			free(store);
			return (NULL);
		}
		i++;
	}
	return (store);
}
int	ps_has_duplicate(int *numbers, int count)
{
	int i;
	int j;

	i=0;
	while(i<count)
	{j = i + 1;
		while (j < count)
		{
			if (numbers[i] == numbers[j])
				return (1);
			j++;
		}
		i++;
	}
	return(0);
}
int	ps_tokens_len(char **tokens)
{
	int	i;

	i = 0;
	while (tokens[i])
		i++;
	return (i);
}
int	*ps_parse_numbers(int argc, char **argv)
{
	char	**tokens;
	int		*numbers;
	int		count;

	tokens = ps_tokenize(argc, argv);
	if (!tokens)
		return (NULL);
	count = ps_tokens_len(tokens);
	numbers = ps_tokens_to_numbers(tokens);
	ps_free_tokens(tokens);
	if (!numbers)
		return (NULL);
	if (ps_has_duplicate(numbers, count))
	{
		free(numbers);
		ft_putendl_fd("Error", 2);
		return (NULL);
	}
	return (numbers);
}