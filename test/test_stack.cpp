#include "stack.h"
#include <gtest.h>

TEST(Stack, can_create_stack) {
	ASSERT_NO_THROW(Stack a);
}
TEST(Stack, can_create_stack_whith_size) {
	ASSERT_NO_THROW(Stack a(20));
}
TEST(Stack, can_not_create_stack_whith_negativ_length) {
	ASSERT_ANY_THROW(Stack a(-10));
}
TEST(Stack, can_add_element) {
	Stack a(10);
	int b=1;	
	ASSERT_NO_THROW(a.Push(b););
}
TEST(Stack, can_not_add_element_in_full_stack) {
	Stack a(10);
	int b = 1;
	for (int i = 0; i < 10; i++)
	{
		a.Push(i);
	}
	ASSERT_ANY_THROW(a.Push(b));
}
TEST(Stack, can_pick_element) {
	Stack a(10);
	int b = 1;
	a.Push(b);
	EXPECT_EQ(b, a.Put());
}
TEST(Stack, can_pick_and_not_delete_element) {

	Stack a(10);
	int b = 1;
	int c;
	a.Push(b);
	c = a.Peek();
	EXPECT_EQ(b, a.Put());
}
TEST(Stack, can_not_put_from_empty_stack) {
	Stack a(10);
	int b;
	ASSERT_ANY_THROW(b = a.Put());
}
TEST(Stack, can_copy_Stack) {
	Stack a(10);
	ASSERT_NO_THROW(Stack b(a));
}
TEST(Stack, copied_stack_are_equal) {
	Stack a(10);
	Stack b(a);
	EXPECT_EQ(b, a);
}
TEST(Stack, copied_pMem_are_not_equal) {
	Stack a(10);
	Stack b(a);
	a.Push(1);
	b.Push(2);
	EXPECT_NE(b.Put(), a.Put());
}

TEST(Stack, can_not_SetSize_negativ_length) {
	Stack a(10);
	a.SetSize(15);
	ASSERT_ANY_THROW(a.SetSize(-10));
}
TEST(Stack, can_SetSize_then_Size_larger_n) {
	Stack a(10);
	for (int i = 0; i < 10; i++)
	{
		a.Push(i);
	}
	ASSERT_ANY_THROW(a.SetSize(5));
}
TEST(Stack, can_SetSize) {
	Stack a(10);
	for (int i = 0; i < 10; i++) {
		a.Push(i);
	}
	a.SetSize(11);
	ASSERT_NO_THROW(a.Push(1));
}
TEST(Stack, can_assign_stacks) {
	Stack a(2);
	for (int i = 0; i < 2; i++) {
		a.Push(i);
	}
	Stack b(2);
	b = a;
	EXPECT_EQ(1, b.Put());
	EXPECT_EQ(0, b.Put());
}
TEST(Stack, assign_stacks_are_equal) {
	Stack a(10);
	Stack b(10);

	for (int i = 0; i < 10; i++) {
		a.Push(i);
	}
	
	b = a;
	EXPECT_EQ(a,b);
}
TEST(Stack, stack_equal_itself) {
	Stack a(10);
	for (int i = 0; i < 10; i++) {
		a.Push(i);
	}
	EXPECT_EQ(a, a);
}
TEST(Stack, stacks_whith_different_size_not_equal) {
	Stack a(10);
	Stack b(5);
	EXPECT_NE(a, b);
}
TEST(Stack, different_stacks_not_equal) {
	Stack a(10);
	Stack b(10);

	a.Push(1);

	EXPECT_NE(a, b);
}
TEST(Stack, stacks_whith_different_Top_not_equal) {
	Stack a(10);
	Stack b(10);
	b.Push(0);
	EXPECT_NE(a, b);
}

