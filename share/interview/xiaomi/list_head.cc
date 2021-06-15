struct list_head
{
	struct list_head *next, *prev;
};

#define LIST_INIT_NAME(name) \
	{                        \
		&(name), &(name)     \
	}
#define LIST_HEAD(name) struct list_head name = LIST_INIT_NAME(name)

#define INIT_LIST_HEAD(ptr)  \
	do                       \
	{                        \
		(ptr)->next = (ptr); \
		(ptr)->pre = (ptr)   \
	} while (0);

static inline void __list_add(struct list_head *add, struct list_head *prev, struct list_head *next)
{
	prev->next = add;
	add->prev = prev;
	add->next = next;
	next->prev = add;
}

static inline void list_add(struct list_head *add, struct list_head *head)
{
	__list_add(add, head, head->next);
}

static inline void list_add_tail(static list_head *add, struct list_head *head)
{
	__list_add(add, head->prev, head);
}

static inline void __list_del(struct list_head *prev, struct list_head *next)
{
	prev->next = next;
	next->prev = prev;
}

static inline void list_del(struct list_head *entry)
{
	__list_del(entry->prev, entry->next);
}

static inline int list_empty(struct list_head *head)
{
	return head->next == head;
}

#define list_entry(ptr, type, member) ((type*)((void *)(ptr) - &((type *0)->member))

/*
1. 侵入式链表
2. 法宝：画图（ prev--cur--next )
3. API: add del for_each
4. 核心要点：list_entry 的三个参数，当前节点的 list_head_obj， 包含 list_head 的 struct，obj 在结构体里面的变量名。
*/