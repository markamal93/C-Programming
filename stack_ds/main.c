
#include "stack_ds.h"
#include "stack_ds.c"

stack_ds_t stack1;
stack_ds_t stack2;

uint32_t stack_pop_value = ZERO;
uint32_t stack_top_value = ZERO;
uint32_t stack_size_value = ZERO;

int main()
{
    return_status_t ret = R_NOK;
    ret = stack_init(&stack1);
    if (ret = R_NOK)
    {
        printf("stack1 initialization failed");
    }
    else
    {
        ret = stack_push(&stack1, 11); // success
        ret = stack_push(&stack1, 12); // success
        ret = stack_push(&stack1, 13); // success
        ret = stack_push(&stack1, 14); // success
        ret = stack_push(&stack1, 15); // success
        ret = stack_push(&stack1, 16); // fail
        /*ret = stack_pop(&stack1,&stack_pop_value);
        printf("the pop value of the stack is %i\n",(uint32_t *)stack_pop_value);
        ret = stack_pop(&stack1,&stack_pop_value);
        printf("the pop value of the stack is %i\n",(uint32_t *)stack_pop_value);
        ret = stack_pop(&stack1,&stack_pop_value);
        printf("the pop value of the stack is %i\n",(uint32_t *)stack_pop_value);


        */
        stack_top(&stack1, &stack_top_value);
        stack_display(&stack1);
        stack_size(&stack1, &stack_size_value);
        printf("stack size is %i", (uint32_t *)stack_size_value);
    }

    ret = stack_init(&stack2);
    if (ret = R_NOK)
    {
        printf("stack2 initialization failed");
    }
    else
    {
    }

    return 0;
}