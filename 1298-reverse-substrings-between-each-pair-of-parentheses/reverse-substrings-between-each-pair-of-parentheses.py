class Solution:
    def reverseParentheses(self, s: str) -> str:
        stack = []
        
        for char in s:
            if char == ')':
                temp = []
                # Pop characters until we hit the open parenthesis
                while stack and stack[-1] != '(':
                    temp.append(stack.pop())
                
                # Remove the '(' itself
                stack.pop() 
                
                # Push the reversed characters back onto the stack
                stack.extend(temp)
            else:
                stack.append(char)
                
        return "".join(stack)