#include <string.h>

typedef struct node
{
	int val;
	node_t *next;
} node_t;

static node_t dummy_head = {.val = 0, .next = NULL};
static int size = 0;

int add_at_tail(node_t *p_new_node)
{
	node_t *p_node = &dummy_head;
	while (p_node->next != NULL)
	{
		p_node = p_node->next;
	}
	p_node->next = p_node;
	size++;
	return 0;
}

int add_at_head(node_t *p_node)
{
	p_node->next = dummy_head.next;
	dummy_head.next = p_node;
	size++;
	return 0;
}
