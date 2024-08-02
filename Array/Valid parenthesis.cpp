Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Every close bracket has a corresponding open bracket of the same type.
 

Example 1:

Input: s = "()"
Output: true
Example 2:

Input: s = "()[]{}"
Output: true
Example 3:

Input: s = "(]"
Output: false


Intuition
 - The problem requires us to determine if the given string of brackets is valid or not.
 - We can use a stack data structure to keep track of opening brackets encountered and check if they match with
   the corresponding closing brackets.

Approach
Here is the step-by-step approach of the algorithm:

 - Initialize an empty stack.
 - Traverse the input string character by character.
 - If the current character is an opening bracket (i.e., '(', '{', '['), push it onto the stack.
 - If the current character is a closing bracket (i.e., ')', '}', ']'), check if the stack is empty.
 - If it is empty, return false, because the closing bracket does not have a corresponding opening bracket. 
 - Otherwise, pop the top element from the stack and check if it matches the current closing bracket. 
 - If it does not match, return false, because the brackets are not valid.
 - After traversing the entire input string, if the stack is empty, return true, because all opening brackets have been
   matched with their corresponding closing brackets.
 - Otherwise, return false, because some opening brackets have not been matched with their corresponding closing brackets.



 NOTE ::: 
* take care of edge cases.
1. s = "]"
2. s = "["
3. s = "(]"



class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        int n = s.size();
        for(int i = 0; i<n; i++){
            if(s[i] == '{' || s[i] == '[' || s[i] == '('){
                st.push(s[i]);
            }
            else{
                if(st.empty()){
                    return false;
                }
                char t = st.top();
                if((t == '{' && s[i] != '}') || (t == '(' && s[i] != ')') || (t == '[' && s[i] != ']')){
                    return false;
                }
                st.pop();
            }
        }
        return st.empty();
    }
};