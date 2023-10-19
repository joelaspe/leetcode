
// This is the older prototype-based way to define classes in Javascript. ES6 introduced more formal class defintion
/** This is my initial version
var MinStack = function() {
    this.min = [];
    this.stack = [];
    this.minSize = 0;
    this.stackSize = 0;
};

/** /*
 * @param {number} val
 * @return {void}
 */ /*
MinStack.prototype.push = function(val) {
    if(this.minSize === 0) {
        this.min[0] = val;
        this.minSize++;
    } else if (val <= this.min[this.minSize-1]) {
        this.min[this.minSize] = val;
        this.minSize++;
    }
    this.stack[this.stackSize] = val;
    this.stackSize++;
};

/**
 * @return {void}
 */ /*
MinStack.prototype.pop = function() {
    if(this.min[this.minSize-1] === this.stack[this.stackSize-1]) {
        this.minSize--;
    }
    this.stack[this.stackSize-1] = null;
    this.stackSize--;
    
};

/**
 * @return {number}
 */ /*
MinStack.prototype.top = function() {

   return this.stack[this.stackSize-1];

};

/**
 * @return {number}
 */ /*
MinStack.prototype.getMin = function() {
    return this.min[this.minSize-1];    
};
*/
/** 
 * Your MinStack object will be instantiated and called as such:
 * var obj = new MinStack()
 * obj.push(val)
 * obj.pop()
 * var param_3 = obj.top()
 * var param_4 = obj.getMin()
 */


/** Internet solution gave me a hint to improve, is better as a whole object is pushed onto one array, so we don't need 2 arrays and the additional min size tracker. */


var MinStack = function() {
    this.stack = [];
    this.stackSize = 0;
};

/** 
 * @param {number} val
 * @return {void}
 */
MinStack.prototype.push = function(val) {
    this.stack[this.stackSize] = {value: val, min: this.stackSize == 0 ? val : Math.min(val, this.getMin())};
    this.stackSize++;
};

/**
 * @return {void}
 */
MinStack.prototype.pop = function() {
    //this.stack[this.stackSize-1] = null;
    this.stackSize--;
    
};

/**
 * @return {number}
 */
MinStack.prototype.top = function() {
    return this.stack[this.stackSize-1].value;
};

/**
 * @return {number}
 */
MinStack.prototype.getMin = function() {
    return this.stack[this.stackSize-1].min; 
};


/* Intuition: I've been seeing solutions that use Javascripts array helper functions pop() and push() which seems like cheating, so this solution will not use these array helpers. We must implement a stack that can perform the normal stack functions, as well as retrieve the minimum element in constant time. We will push an object containing the input value and the minimum value so far which is either the existing min value being stored or if the input value is smaller, we will use that. This way, when an element is popped, even if that value is the current minimum, the next element on the stack will have a record of the new minimum. The getMin() method will need to assume that the stack will only hold numbers, so normal arithemtical comparisons will be sufficient to determine the minimum value. The other methods will be relatively straight forward. Push will simply append to the end of the array. Pop will remove from the end of the array and top will just return the value at the end of the array.

Approach: In the constructor function, We will use a array to act as our stack. Because our array will not shrink when we pop from it, we will use another variable to track how many active elements are in the stack. (.length property will not work as the array will not shrink)
Next in the push() method, we will add onto the next element available of the array an object {value: val, min: <logic to calculate current minimum} and then increment the stackSize counter.
On to the pop() method, we simply decrement the stackSize counter ignoring the elements in the stack array. 
The top() method is also simple, it simply returns the value of the last element.
getMin() is also simple, just return the value being stored in the object, that is the last element of this.min;

Complexity: 
-Time: All operations do not resize any of our arrays so $$O(1)$$
-Space: The main stack can be as large as N so $$O(n)$$ */


var obj = new MinStack();
obj.push(-2);
obj.push(0);
obj.push(-3);
console.log("minStack #1 Expecting 3 got: " + obj.getMin()); // return -3
obj.pop();
console.log("minStack #1 Expecting 0 got: " + obj.top()); // return 0
console.log("minStack #1 Expecting -2 got: " + obj.getMin()); // return -2

var obj2 = new MinStack();
obj2.push(0);
obj2.push(1);
obj2.push(0);
console.log("minStack #2 Expecting 0 got: " + obj2.getMin());
obj2.pop();
console.log("minStack #2 Expecting 0 got: " + obj2.getMin());

var obj3 = new MinStack();
obj3.push(2147483646);
obj3.push(2147483646);
obj3.push(2147483647);
console.log("minStack #3 Expecting 2147483647 got: " + obj3.top());
obj3.pop();
console.log("minStack #3 Expecting 2147483646 got: " + obj3.getMin());
obj3.pop();
console.log("minStack #3 Expecting 2147483646 got: " + obj3.getMin());
obj3.pop();
obj3.push(2147483647);
console.log("minStack #3 Expecting 2147483647 got: " + obj3.top());
console.log("minStack #3 Expecting 2147483647 got: " + obj3.getMin());
obj3.push(-2147483648);
console.log("minStack #3 Expecting -2147483648 got: " + obj3.top());
console.log("minStack #3 Expecting -2147483648 got: " + obj3.getMin());
obj3.pop();
console.log("minStack #3 Expecting 2147483647 got: " + obj3.getMin());


