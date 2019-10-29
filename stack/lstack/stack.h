#ifndef __STACK__
#define __STACK__
#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define stack_init(size) _istack_init(size)
#define stack_push(stk, key)                                                   \
	_Generic((key), int : _istack_push, default : _pstack_push)(stk, key)
#define stack_up_rotate(stk) stack_rrotate(stk)
#define stack_down_rotate(stk) stack_lrotate(stk)
typedef struct _stack stack;
typedef struct _node node;

struct _stack {
	size_t size;
	size_t next_top;
	void **array;
};

/* extern stack *_vstack_init(void); */
extern stack *_istack_init(size_t size);
extern void *stack_expand(stack *stk, size_t size);
extern void stack_free(stack *stk);
extern void _pstack_push(stack *stk, void *key);
extern void _istack_push(stack *stk, int key);
extern void *stack_pop(stack *stk);
extern void *stack_dup(stack *stk, size_t key_size);
extern void *stack_top(stack *stk);
extern void stack_swap(stack *stk);
extern void stack_rrotate(stack *stk);
extern void stack_lrotate(stack *stk);
extern bool stack_isEmpty(stack *stk);
extern size_t stack_size(stack *stk);
#endif
