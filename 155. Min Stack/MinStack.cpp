#include <iostream>

using namespace std;

class MinStack {

    struct stackValue {
        int value;
        int minValue;
    };  
    stackValue customStack[30000];
    int stackIndex;
    public:
    MinStack() {
        
        stackIndex = 0;
        customStack[0].value = 0;
        customStack[0].minValue = 2147483647;
    }
    
    void push(int val) {
        stackIndex++;
        (val < customStack[stackIndex-1].minValue) ? customStack[stackIndex] = (stackValue){val, val} : customStack[stackIndex] = (stackValue){val, customStack[stackIndex-1].minValue};
    }
    
    void pop() {
        stackIndex--;        
    }
    
    int top() {
        return customStack[stackIndex].value;
    }
    
    int getMin() {
        return customStack[stackIndex].minValue;        
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

/* Intuition: We must implement a stack that can perform the normal stack functions, as well as retrieve the minimum element in constant time. When pushing, we will push a struct containing the input value and the minimum value so far which is either the existing min value being stored or if the input value is smaller, we will use that.  This way, when an element is popped, even if that value is the current minimum, the next element on the stack will have a record of the new minimum. The getMin() method will need to assume that the stack will only hold numbers, so normal arithemtical comparisons will be sufficient to determine the minimum value. The other methods will be relatively straight forward. Push will simply append to the end of the array. Pop will remove from the end of the array and top will just return the value at the end of the array. 

Approach: In the struct definition, define a variable minValue that stores the minimum value encountered. By accessing minValue we can get the minimum value in constant O(1) time. We will need a previous minvalue variable stored, so when we pop, we know what to set it to. We also define an array that will store each value pushed or popped from the stack, and a stackIndex to let us know where the "top" of the stack is in relation to the total size of the stack.  In the constructor function, create a new MinStack obj and allocate memory for it. Because our array will not shrink when we pop from it, we will use another variable to track how many active elements are in the stack. 
Next in the push() method, we will add onto the next element available of the array an object {value: val, min: <logic to calculate current minimum} and then increment the stackSize counter. 
On to the pop() method, we simply decrement the stackSize counter ignoring the elements in the stack array. 
The top() method is also simple, it simply returns the value of the last element.
getMin() is also simple, just return the value being stored in the object, that is the last element of this.min;
Because the problem statement is that all functions must have time complexity of $$O(1)$$ the initial allocation of the stack will be the maximum size.

Complexity: 
-Time: Operations like getMin() are $$O(1)$$. push() and pop() are generally $$O(1)$$ unless they require reallocation of memory, in which case it will be $$O(n)$$ where n is the current size of the array. 
-Space: The main values are able to store can be as large -2^31 to 2^31 so this is a signed long int. We also have a second stack that maintains the minimum number. This is $$O(2n)$$ or $$O(n)$$*/

int main() {
    MinStack minStackObj;
    minStackObj.push(-2);
    minStackObj.push(0);
    minStackObj.push(-3);
    cout << "minStack #1 Expecting -3 got: " << minStackObj.getMin() << "\n";
    minStackObj.pop();
    cout << "minStack #1 Expecting 0 got: " << minStackObj.top() << "\n";
    cout << "minStack #1 Expecting -2 got: " << minStackObj.getMin() << "\n";

    MinStack minStackObj2;
    minStackObj2.push(0);
    minStackObj2.push(1);
    minStackObj2.push(0);
    cout << "minStack #2 Expecting 0 got: " << minStackObj2.getMin() << "\n";
    minStackObj2.pop();
    cout << "minStack #2 Expecting 0 got: " << minStackObj2.getMin() << "\n";

    MinStack minStackObj3;
    minStackObj3.push(214783646);
    minStackObj3.push(214783646);
    minStackObj3.push(214783647);
    cout << "minStack #3 Expecting 214743647 got: " << minStackObj3.top() << "\n";
    minStackObj3.pop();
    cout << "minStack #3 Expecting 214783646 got: " << minStackObj3.getMin() << "\n";
    minStackObj3.pop();
    cout << "minStack #3 Expecting 214783646 got: " << minStackObj3.getMin() << "\n";
    minStackObj3.pop();
    minStackObj3.push(2147483647);
    cout << "minStack #3 Expecting 214783647 got: " << minStackObj3.top() << "\n";
    cout << "minStack #3 Expecting 214783647 got: " << minStackObj3.getMin() << "\n";
    minStackObj3.push(-214783648);    
    cout << "minStack #3 Expecting -214783648 got: " << minStackObj3.top() << "\n";
    cout << "minStack #3 Expecting -214783648 got: " << minStackObj3.getMin() << "\n";
    minStackObj3.pop();
    cout << "minStack #3 Expecting 214783647 got: " << minStackObj3.getMin() << "\n";    

}