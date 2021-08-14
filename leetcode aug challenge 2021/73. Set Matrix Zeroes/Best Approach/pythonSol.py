class Solution:
    def setZeroes(self, matrix: List[List[int]]) -> None:
        H = len(matrix)
        W = len(matrix[0])
        first_row_zero = False
        
        for col in range(0,W):
            if matrix[0][col] == 0:
                first_row_zero = True
                
        for row in range(0, H):
            for col in range(0, W):
                if matrix[row][col] == 0:
                    matrix[0][col] =0
                    
                    
        for row in range(1,H):
            contains_zero = False
            for col in range(0,W):
                if matrix[row][col] == 0:
                    contains_zero = True
                    break
          
            for col in range(0,W):
                if contains_zero or matrix[0][col] == 0:
                    matrix[row][col] = 0
                    
                    
                    
        if first_row_zero == True:
            for col in range(0,W):
                matrix[0][col] = 0
                    
        
                
            
        
                    
    
        
        
        
        
      
    
    
    
    
    
    
    
        