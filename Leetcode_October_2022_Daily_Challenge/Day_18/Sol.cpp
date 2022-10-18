/*
Here n is just for number of iterations 
Here we are required to count the characters and in next step again count number of characters until n becomes 0
*/

// TC: O(n*n*n)
// sc: O(n)
class Solution {
public:
   string countAndSay(int n)
{
    string curr_str;

	// The initial case, when n = 1
	curr_str += '1';
       
	// The iterative case, when n > 1
	for (int i = 0; i < n - 1; i++) // O(n)
	{
		string buffer; // buffer is reintialised every time 

		// Handle the current string
		int index = 0;                                      // reintialised everytime to start from starting of string 
		for (int index = 0; index < curr_str.size(); ++index) // O(n)
		{
			// Count the occurance of each digit
			int cnt = 1; // At least one occurance
			 
			while (index + 1 < curr_str.size() and curr_str[index + 1] == curr_str[index]) // O(n)
			{
				index++; // for moving to next character
				cnt++;   // for cnt of similar characters
			}

			buffer.push_back(cnt + '0');      // first storing count of character in char form
			buffer.push_back(curr_str[index]);// then storing that character 
		}

		// Update the current string
		curr_str = buffer;
	}

	return curr_str;
  }
};


/* n = 8
1
1 1
2 1
1 2 1 1
1 1 1 2 2 1
3 1 2 2 1 1
1 3 1 1 2 2 2 1
1 1 1 3 2 1 3 2 1 1
*/