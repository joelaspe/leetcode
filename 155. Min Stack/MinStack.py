class MinStack:
    valueStack = []
 
    def __init__(self):
        self.valueStack.append([0, 2147483647])
  
    def push(self, val: int) -> None:
        if val < self.valueStack[-1][1]:
            self.valueStack.append([val, val])
        else:
            self.valueStack.append([val, self.valueStack[-1][1]])

    def pop(self) -> None:
        self.valueStack.pop()

    def top(self) -> int:
        return self.valueStack[-1][0]

    def getMin(self) -> int:
        return self.valueStack[-1][1]


# Your MinStack object will be instantiated and called as such:
# obj = MinStack()
# obj.push(val)
# obj.pop()
# param_3 = obj.top()
# param_4 = obj.getMin()

# Intuition: We must implement a stack that can perform the normal stack functions, as well as retrieve the minimum element in constant time. When pushing, we will push a the input value and the minimum value so far which is either the existing min value being stored or if the input value is smaller, we will use that.  This way, when an element is popped, even if that value is the current minimum, the next element on the stack will have a record of the new minimum. The getMin() method will need to assume that the stack will only hold numbers, so normal arithemtical comparisons will be sufficient to determine the minimum value. The other methods will be relatively straight forward. Push will simply append to the end of the array. Pop will remove from the end of the array and top will just return the value at the end of the array. 

#Approach:  We will need a previous minvalue variable stored, so when we pop, we know what to set it to. We also define a list that will store each value pushed or popped from the stack. 
#Next in the push() method, we will add onto the next element available of the array an object {value: val, min: <logic to calculate current minimum}
#On to the pop() method, we simply pop() from the list.
#The top() method is also simple, it simply returns the value of the last element value.
#getMin() is also simple, just return the value being stored in the object, that is the last element of this.min;
#Because the problem statement is that all functions must have time complexity of $$O(1)$$ the initial allocation of the stack will be the maximum size.

#Complexity: 
#-Time: Operations like getMin() are $$O(1)$$. push() and pop() are generally $$O(1)$$ unless they require reallocation of memory, in which case it will be $$O(n)$$ where n is the current size of the array. 
#-Space: The main values are able to store can be as large -2^31 to 2^31 so this is a signed long int. We also have a second stack that maintains the minimum number. This is $$O(2n)$$ or $$O(n)$$*/

minStackObj = MinStack()
minStackObj.push(-2)
minStackObj.push(0)
minStackObj.push(-3)
print("minStack #1 Expecting -3 got: " + str(minStackObj.getMin()))
minStackObj.pop();
print("minStack #1 Expecting 0 got: " + str(minStackObj.top()))
print("minStack #1 Expecting -2 got: " + str(minStackObj.getMin()))

minStackObj2 = MinStack();
minStackObj2.push(0);
minStackObj2.push(1);
minStackObj2.push(0);
print("minStack #2 Expecting 0 got: " + str(minStackObj2.getMin()))
minStackObj2.pop();
print("minStack #2 Expecting 0 got: " + str(minStackObj2.getMin()))

minStackObj3 = MinStack()
minStackObj3.push(214783646)
minStackObj3.push(214783646)
minStackObj3.push(214783647)
print("minStack #3 Expecting 214743647 got: " + str(minStackObj3.top()))
minStackObj3.pop()
print("minStack #3 Expecting 214783646 got: " + str(minStackObj3.getMin()))
minStackObj3.pop()
print("minStack #3 Expecting 214783646 got: " + str(minStackObj3.getMin()))
minStackObj3.pop()
minStackObj3.push(2147483647)
print("minStack #3 Expecting 214783647 got: " + str(minStackObj3.top()))
print("minStack #3 Expecting 214783647 got: " + str(minStackObj3.getMin()))
minStackObj3.push(-214783648)
print("minStack #3 Expecting -214783648 got: " + str(minStackObj3.top()))
print("minStack #3 Expecting -214783648 got: " + str(minStackObj3.getMin()))
minStackObj3.pop();
print("minStack #3 Expecting 214783647 got: " + str(minStackObj3.getMin()))