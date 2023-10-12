#include <stdlib.h>
#include <stdio.h>

typedef struct {
   int minValueStack[30000];
   int values[30000];
   int stackIndex;

} MinStack;


MinStack* minStackCreate() {
    MinStack *stackObj;
    stackObj = malloc(sizeof(MinStack));
    if(stackObj == NULL) {
        printf("Error allocating memory.\n");
        return NULL;
    }
    stackObj->stackIndex = 0;
    stackObj->values[0] = 0;
    stackObj->minValueStack[0] = 2147483647; // initially set to maximum value that int can hold. This is ok because the problem statement says we will never call minStackGetMin() on an empty stack.
    return stackObj; 
}

void minStackPush(MinStack* obj, int val) {
    obj->stackIndex++;
    obj->values[obj->stackIndex] = val;
    
    if(val < obj->minValueStack[obj->stackIndex-1]) {
        obj->minValueStack[obj->stackIndex] = val;
    }
    else {
        obj->minValueStack[obj->stackIndex] = obj->minValueStack[obj->stackIndex-1];
    }
}

void minStackPop(MinStack* obj) {
    obj->stackIndex--;
    //edge case, don't want to check for new minValue if stack is empty
    if(obj->stackIndex == 0) {
        return;
    }
    
}

int minStackTop(MinStack* obj) {
    return obj->values[obj->stackIndex];
}

int minStackGetMin(MinStack* obj) {
    return obj->minValueStack[obj->stackIndex];
}

void minStackFree(MinStack* obj) {
    free(obj);
}

/**
 * Your MinStack struct will be instantiated and called as such:
 * MinStack* obj = minStackCreate();
 * minStackPush(obj, val);
 
 * minStackPop(obj);
 
 * int param_3 = minStackTop(obj);
 
 * int param_4 = minStackGetMin(obj);
 
 * minStackFree(obj);
*/


/* Intuition: We must implement a stack that can perform the normal stack functions, as well as retrieve the minimum element in constant time. When pushing, we will push an object containing the input value and the minimum value so far which is either the existing min value being stored or if the input value is smaller, we will use that.  This way, when an element is popped, even if that value is the current minimum, the next element on the stack will have a record of the new minimum. The getMin() method will need to assume that the stack will only hold numbers, so normal arithemtical comparisons will be sufficient to determine the minimum value. The other methods will be relatively straight forward. Push will simply append to the end of the array. Pop will remove from the end of the array and top will just return the value at the end of the array. 

Approach: In the struct definition, define a variable minValue that stores the minimum value encountered. By accessing minValue we can get the minimum value in constant O(1) time. We will need a previous minvalue variable stored, so when we pop, we know what to set it to. We also define an array that will store each value pushed or popped from the stack, and a stackIndex to let us know where the "top" of the stack is in relation to the total size of the stack.  In the constructor function, create a new MinStack obj and allocate memory for it. Because our array will not shrink when we pop from it, we will use another variable to track how many active elements are in the stack. 
Next in the push() method, we will add onto the next element available of the array an object {value: val, min: <logic to calculate current minimum} and then increment the stackSize counter. 
On to the pop() method, we simply decrement the stackSize counter ignoring the elements in the stack array. 
The top() method is also simple, it simply returns the value of the last element.
getMin() is also simple, just return the value being stored in the object, that is the last element of this.min;
Because the problem statement is that all functions must have time complexity of $$O(1)$$ the initial allocation of the stack will be the maximum size.

Complexity: 
-Time: Operations like getMin() are $$O(1)$$. push() and pop() are generally $$O(1)$$ unless they require reallocation of memory, in which case it will be $$O(n)$$ where n is the current size of the array. 
-Space: The main stack is initially declared as able to store can be as large -2^31 to 2^31 so this is a signed long int. We also have a second stack that maintains the minimum number. This is $$O(2n)$$ or $$O(n)$$*/


int main() {
    MinStack* obj = minStackCreate();
    
    minStackPush(obj, -2);
    minStackPush(obj,0);
    minStackPush(obj, -3);
    printf("minStack #1 Expecting -3 got: %d\n", minStackGetMin(obj)); 
    minStackPop(obj);
    printf("minStack #1 Expecting 0 got: %d\n", minStackTop(obj)); 

    printf("minStack #1 Expecting -2 got: %d\n",minStackGetMin(obj));
  

    minStackFree(obj);

    MinStack* obj2 = minStackCreate();
    minStackPush(obj2, 0);
    minStackPush(obj2, 1);
    minStackPush(obj2, 0);
    printf("minStack #2 Expecting 0 got: %d\n", minStackGetMin(obj2));
    minStackPop(obj2);
    printf("minStack #2 Expecting 0 got: %d\n", minStackGetMin(obj2));

    MinStack* obj3 = minStackCreate();
    minStackPush(obj3, 2147483646);
    minStackPush(obj3, 2147483646);
    minStackPush(obj3, 2147483647);
    printf("minStack #3 Expecting 2147473647 got: %d\n", minStackTop(obj3));
    minStackPop(obj3);
    printf("minStack #3 Expecting 2147483646 got: %d\n", minStackGetMin(obj3));
    minStackPop(obj3);
    printf("minStack #3 Expecting 214783646 got: %d\n", minStackGetMin(obj3));
    minStackPop(obj3);
    minStackPush(obj3, 214783647);
    printf("minStack #3 Expecting 2147483647 got: %d\n", minStackTop(obj3));
    printf("minStack #3 Expecting 2147483647 got: %d\n", minStackGetMin(obj3));
    minStackPush(obj3, -2147483648);
    printf("minStack #3 Expecting -2147483648 got: %d\n", minStackTop(obj3));
    printf("minStack #3 Expecting -2147483648 got: %d\n", minStackGetMin(obj3));
    minStackPop(obj3);
    printf("minStack #3 Expecting 214783647 got: %d\n", minStackGetMin(obj3));
}