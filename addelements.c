#include "push_swap.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
int main(int argc, char *argv[]) {
    int i;
    int split_check;
    i = 1;
    split_check = 0;

    if (argc < 2)
        return 0;

    char **split_result = NULL;

    if (argc == 2) {
        split_result = ft_split(argv[i], ' ');

        if (split_result == NULL) {
            printf("Memory allocation error");
            return 1;
        }

        split_check = 1;
    }

    if (split_check == 1)
        i--;

    while (split_result != NULL && split_result[i] != NULL) {
        if (!ft_atoi(split_result[i])) {
            printf("Error");
            return 1;
        } 

	else {
            printf("%s\n", split_result[i]);
        }

        i++;
    }

    // Free the memory allocated for split_result if it was assigned
    if (split_check == 1) {
        // Implement the function to free the memory allocated for split_result
        // Example: free_split_result(split_result);
    }

    return 0;
}
*/


int main(int argc, char *argv[])
{
    int		i;
    int		split_check;
    char**	split_res;
    
    i = 1;
    split_check = 0;
    if (argc < 2)
        return (0);
    if (argc == 2)
    {
	    split_res = ft_split(argv[i], ' ');
	    split_check += 1;
	    i--;
    }
    if (split_check == 1)
    {
	    while (split_res && split_res[i])
	    {
		    if (!ft_atoi(split_res[i]))
		    {
			    printf("Error");
			    return (0);
		    }
		    else (printf("%s\n", split_res[i]));
		    i++;
	    }
    }
    else
    { 
	    while (i < argc)
	    {
		    if (!ft_atoi(argv[i]))
		    {
			    printf("Error");
			    return (0);
		    }
		    else (printf("%s\n", argv[i]));
		    i++;
	    }
    }
    return (0);
}

/*
typedef struct s_list
{
    void    *content;
    struct s_list *next;
} t_list;
*/


/*
void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*temp;

	if (!lst || !new)
		return ;
	if (!(*lst))
	{
		*lst = new;
		return ;
	}
	temp = *lst;
	while (temp -> next)
		temp = temp -> next;
	temp -> next = new;
}

int main(int argc, char *argv[])
{
    int i;
    i = 1;
    t_list *root = NULL;

    if (argc < 2)
        return (0);
    while (i < argc)
    {
        t_list *new_node = malloc(sizeof(t_list));
        if (!new_node)
            return (0);
        new_node->content = ft_strdup(argv[i]);
        if (!new_node->content)
        {
            free(new_node);
            return (0);
        }
        new_node->next = NULL;
        ft_lstadd_back(&root, new_node);
        i++;
    }
    //for printing
    t_list *current = root;
    while (current != NULL)
    {
        printf("%s\n", (char *)current->content);
        current = current->next;
    }
    current = root;
    while (current != NULL)
    {
        t_list *temp = current;
        current = current->next;
        free(temp->content);
        free(temp);
    }
    return (0);
}

*/
