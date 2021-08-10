class Solution(object):
    def addStrings(self, num1, num2):
        """
        :type num1: str
        :type num2: str
        :rtype: str
        """
        num1, num2 = list(num1), list(num2)
        carry, res = 0, []
        while len(num2) > 0 or len(num1) > 0:
            digit1 = ord(num1.pop())-ord('0') if len(num1) > 0 else 0
            digit2 = ord(num2.pop())-ord('0') if len(num2) > 0 else 0
            
            temp = digit1 + digit2 + carry 
            res.append(temp % 10)
            carry = temp // 10
        if carry: res.append(carry)
        return ''.join([str(i) for i in res])[::-1]