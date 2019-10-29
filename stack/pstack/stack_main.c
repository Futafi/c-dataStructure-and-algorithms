#include "stack.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define assertEqual(a, b) assert((a) == (b))
#define assertNotEqual(a, b) assert((a) != (b))
#define assertFalse(a) assert(!(a))
void test_stack_init();
void test_istack_push();
void test_pstack_push();
void test_stack_pop();
void test_stack_dup();
void test_stack_top();
void test_stack_swap();
void test_stack_rrotate2();
void test_stack_rrotate3();
void test_stack_lrotate2();
void test_stack_lrotate3();
void test_stack_isEmpty();
void test_stack_size();

int itestdata[3] = {23, 45, 67};
char stestdata[3][5] = {"mario", "peach", "kuppa"};
int main(int argc, char const *argv[])
{
	test_stack_init();
	test_istack_push();
	test_pstack_push();
	test_stack_pop();
	test_stack_dup();
	test_stack_top();
	test_stack_swap();
	test_stack_rrotate2();
	test_stack_rrotate3();
	test_stack_lrotate2();
	test_stack_lrotate3();
	test_stack_isEmpty();
	test_stack_size();
	printf("TEST CLEAR\n");
	return 0;
}

void test_stack_init()
{
	stack *stk = stack_init();
	assert(stk);
	assertFalse(stk->size);
}

void test_istack_push()
{
	stack *stk = stack_init();
	for (int i = 0; i < 3; i++) {
		stack_push(stk, itestdata[i]);
		assertEqual(*(int *)stk->top->key, itestdata[i]);
	}
	assertEqual(stk->size, 3);
}

void test_pstack_push()
{
	stack *stk = stack_init();
	for (int i = 0; i < 3; i++) {
		stack_push(stk, stestdata[i]);
		assertEqual(stk->top->key, stestdata[i]);
	}
	assertEqual(stk->size, 3);
}

void test_stack_pop()
{
	stack *stk = stack_init();
	void *p;
	stack_push(stk, p);
	/* printf("%p\n",stk->top->key); */
	/* printf("%p\n",p); */
	/* printf("%p\n",stack_pop(stk)); */
	assertEqual(p, stack_pop(stk));
	assert(!stk->size);
}

void test_stack_dup()
{
	stack *stk = stack_init();
	stack_push(stk, 2);
	stack_dup(stk, sizeof(int));
	assertEqual(stk->size, 2);
	assertEqual(*(int *)stack_pop(stk), 2);
	assertEqual(*(int *)stack_pop(stk), 2);

	char mario[] = "Mario";
	stack_push(stk, mario);
	stack_dup(stk, sizeof(mario));
	assertEqual(stk->size, 2);
	assert(!strcmp((char *)stack_pop(stk), "Mario"));
	assert(!strcmp((char *)stack_pop(stk), "Mario"));
}

void test_stack_top()
{
	stack *stk = stack_init();
	void *p;
	stack_push(stk, p);
	assertEqual(stack_top(stk), p);
}

void test_stack_swap()
{
	stack *stk = stack_init();
	void *p1, *p2;
	stack_push(stk, p1);
	stack_push(stk, p2);
	/* before Last |p1|p2| First -> after Last |p2|p1| First */
	stack_swap(stk);
	assertEqual(stack_pop(stk), p1);
	assertEqual(stack_pop(stk), p2);
}

void test_stack_rrotate2()
{
	stack *stk = stack_init();
	void *p1, *p2;
	stack_push(stk, p1);
	stack_push(stk, p2);
	/* before Last |p1|p2| First -> after Last |p2|p1| First */
	stack_rrotate(stk);
	assertEqual(stack_pop(stk), p1);
	assertEqual(stack_pop(stk), p2);
}

void test_stack_rrotate3()
{
	stack *stk = stack_init();
	void *p1, *p2, *p3;
	stack_push(stk, p1);
	stack_push(stk, p2);
	stack_push(stk, p3);
	/* before Last |p1|p2|p3| First -> after Last |p3|p1|p2| First */
	stack_rrotate(stk);
	assertEqual(stack_pop(stk), p2);
	assertEqual(stack_pop(stk), p1);
	assertEqual(stack_pop(stk), p3);
}

void test_stack_lrotate2()
{
	stack *stk = stack_init();
	void *p1, *p2;
	stack_push(stk, p1);
	stack_push(stk, p2);
	/* before Last |p1|p2| First -> after Last |p2|p1| First */
	stack_lrotate(stk);
	assertEqual(stack_pop(stk), p1);
	assertEqual(stack_pop(stk), p2);
}

void test_stack_lrotate3()
{
	stack *stk = stack_init();
	void *p1, *p2, *p3;
	stack_push(stk, p1);
	stack_push(stk, p2);
	stack_push(stk, p3);
	/* before Last |p1|p2|p3| First -> after Last |p2|p3|p1| First */
	stack_lrotate(stk);
	assertEqual(stack_pop(stk), p1);
	assertEqual(stack_pop(stk), p3);
	assertEqual(stack_pop(stk), p2);
}
void test_stack_isEmpty(){
	stack *stk = stack_init();
	assert(stack_isEmpty(stk));
	stack_push(stk, 1);
	assertFalse(stack_isEmpty(stk));
}
void test_stack_size(){
	stack *stk = stack_init();
	for (int i = 0; i < 3; i++) {
		assertEqual(stack_size(stk), i);
		stack_push(stk, 1);
	}
}
