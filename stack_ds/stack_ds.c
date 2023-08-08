#include "stack_ds.h"

static stack_status_t stack_full(stack_ds_t *my_stack);
static stack_status_t stack_empty(stack_ds_t *my_stack);

/**
 * @brief
 * stack pointer initialization
 *
 * @param my_stack  pointer to the stack
 * @return return_status_t
 */

return_status_t stack_init(stack_ds_t *my_stack)
{
    return_status_t ret = R_NOK;
    if (NULL == my_stack)
    {
        ret = R_NOK;
    }
    else
    {
        my_stack->stack_pointer = -1;
        ret = R_OK;
    }

    return ret;
}
/**
 * @brief
 * push data into the stack
 *
 * @param my_stack  pointer to the stack
 * @param value  data to be pushed into the stack
 * @return return_status_t
 */

return_status_t stack_push(stack_ds_t *my_stack, uint32_t value)
{
    return_status_t ret = R_NOK;
    if ((my_stack == NULL) || (stack_full(my_stack) == STACK_FULL))
    {
        printf("STACK is FULL can't add data !!!!\n");
        ret = R_NOK;
    }
    else
    {
        my_stack->stack_pointer++;
        my_stack->data[my_stack->stack_pointer] = value;
        printf("value (%i) pushed into the stack .\n", value);
        ret = R_OK;
    }

    return ret;
}
/**
 * @brief
 * pop data from the stack
 *
 * @param my_stack  pointer to the stack
 * @param *value  pointer to data location
 * @return return_status_t
 */

return_status_t stack_pop(stack_ds_t *my_stack, uint32_t *value)
{
    return_status_t ret = R_NOK;
    if ((my_stack == NULL) || (value == NULL) || (stack_empty(my_stack) == STACK_EMPTY))
    {
        printf("STACK is empty no data to pop!!!!\n");
        ret = R_NOK;
    }
    else
    {
        *value = my_stack->data[my_stack->stack_pointer];
        my_stack->stack_pointer--;

        printf("value (%i) poped from the stack .\n", *value);
        ret = R_OK;

        return ret;
    }
}
/**
 * @brief
 * display the top value of the stack without deleteing it from the stack
 *
 * @param my_stack  pointer to the stack
 * @return return_status_t
 */

return_status_t stack_top(stack_ds_t *my_stack, uint32_t *value)
{
    return_status_t ret = R_NOK;
    if ((my_stack == NULL) || (value == NULL) || (stack_empty(my_stack) == STACK_EMPTY))
    {
        printf("STACK is empty no data to pop!!!!\n");
        ret = R_NOK;
    }
    else
    {
        *value = my_stack->data[my_stack->stack_pointer];

        printf("stack top value is (%i)  .\n", *value);
        ret = R_OK;

        return ret;
    }
}
/**
 * @brief
 * getting the size of the stack
 *
 * @param my_stack  pointer to the stack
 * @return return_status_t
 */

return_status_t stack_size(stack_ds_t *my_stack, uint32_t *stack_size)
{
    return_status_t ret = R_NOK;
    if ((my_stack == NULL))
    {
        ret = R_NOK;
    }
    else
    {
        *stack_size = my_stack->stack_pointer + 1;
        ret = R_OK;
        return ret;
    }
}
/**
 * @brief
 * prints the stack contents
 *
 * @param my_stack  pointer to the stack
 * @return return_status_t
 */

return_status_t stack_display(stack_ds_t *my_stack)
{
    return_status_t ret = R_NOK;
    sint32_t l_counter = ZERO;
    if ((my_stack == NULL) || (stack_empty(my_stack) == STACK_EMPTY))
    {
        ret = R_NOK;
    }
    else
    {
        printf("STACK DATA :");
        for (l_counter = my_stack->stack_pointer; l_counter >= ZERO; l_counter--)
        {
            printf("%i\t", my_stack->data[l_counter]);
        }
        printf("\n");
        ret = R_OK;
        return ret;
    }

    return ret;
}

/**
 * @brief
 * check if the stack is full
 *
 * @param my_stack  pointer to the stack
 * @return stack_status_t  the status of the stack
 */

static stack_status_t stack_full(stack_ds_t *my_stack)
{
    if (my_stack->stack_pointer == (STACK_MAX_SIZE - 1))
    {
        return STACK_FULL;
    }
    else
    {
        return STACK_NOT_FULL;
    }
}

/**
 * @brief
 * check if the stack is empty
 *
 * @param my_stack  pointer to the stack
 * @return stack_status_t  the status of the stack
 */

static stack_status_t stack_empty(stack_ds_t *my_stack)
{
    if (my_stack->stack_pointer == (-1))
    {
        return STACK_EMPTY;
    }
    else
    {
        return STACK_NOT_FULL;
    }
}