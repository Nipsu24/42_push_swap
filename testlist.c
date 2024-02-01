#include <stdio.h>
#include <stdlib.h>

typedef struct s_list
{
    void *content;
    struct s_list *next;
} t_list;

void ft_lstadd_front(t_list **lst, t_list *new)
{
    if (lst && new)
    {
        new->next = *lst;
        *lst = new;
    }
}

int main()
{
    // Create a sample list
    t_list *head = NULL;

    // Create new nodes
    t_list *node1 = malloc(sizeof(t_list));
    node1->content = "Node 1";
    node1->next = NULL;

    t_list *node2 = malloc(sizeof(t_list));
    node2->content = "Node 2";
    node2->next = NULL;

	t_list	*node3 = malloc(sizeof(t_list));
	node3->content = "Node 3";
	node3->next = NULL;

    // Add nodes to the front of the list
    ft_lstadd_front(&head, node2);
    ft_lstadd_front(&head, node1);
	ft_lstadd_front(&head, node3);

    // Print the elements of the list
    t_list *current = head;
    while (current != NULL)
    {
        printf("%s\n", (char *)current->content);
        current = current->next;
    }

    // Don't forget to free allocated memory
    free(node1);
    free(node2);
	free(node3);

    return 0;
}

