#include "stack.h"

stack *stack_init(size_t size)
{
	stack *stk = calloc(1, sizeof(stack));
	stk->size = size;
	stk->array = malloc(size * sizeof(void *));
	return stk;
}

void *stack_expand(stack *stk, size_t size)
{
	void *tmp = realloc(stk->array, sizeof(void *) * size);
	if (tmp == NULL)
		return NULL;
	else {
		stk->size = size;
		return stk->array = tmp;
	}
}

void stack_free(stack *stk)
{
	free(stk->array);
	free(stk);
}

void _pstack_push(stack *stk, void *key)
{
	if (stk->next_top == stk->size)
		stack_expand(stk, stk->size + 1);
	stk->array[stk->next_top++] = key;
}

void _istack_push(stack *stk, int key)
{
	int *pkey = (int *)malloc(sizeof(int));
	*pkey = key;
	_pstack_push(stk, pkey);
}

void *stack_pop(stack *stk) { return stk->array[stk->next_top-- - 1]; }

void *stack_dup(stack *stk, size_t key_size)
{
	void *add_key = malloc(key_size);
	memcpy(add_key, stk->array[stk->next_top - 1], key_size);
	_pstack_push(stk, add_key);
	return add_key;
}

void *stack_top(stack *stk) { return stk->array[stk->next_top-- - 1]; }

void stack_swap(stack *stk)
{
	if (stk->next_top > 1) {
		size_t top = stk->next_top - 1;
		void *tmp;
		tmp = stk->array[top];
		stk->array[top] = stk->array[top - 1];
		stk->array[top - 1] = tmp;
	}
}

void stack_rrotate(stack *stk)
{
	void *top = stk->array[stk->next_top - 1];
	for (int i = stk->next_top - 2; i >= 0; i--)
		stk->array[i + 1] = stk->array[i];
	stk->array[0] = top;
}

void stack_lrotate(stack *stk)
{
	void *bottom = stk->array[0];
	for (int i = 0; i < stk->next_top - 1; i++)
		stk->array[i] = stk->array[i + 1];
	stk->array[stk->next_top - 1] = bottom;
}

bool stack_isEmpty(stack *stk) { return !stk->next_top; }

size_t stack_size(stack *stk) { return stk->next_top; }
