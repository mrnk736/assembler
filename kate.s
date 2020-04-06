.data
str_d:			
.asciz "%d\n"              
array:
.long 3, 4, 5, 13, 2, 0, 1, 6, 8, 5 

.set elem_in_array, (.-array)/4    


.globl main
.type main, @function
.text                         

main:  

movl $0, %ecx     
movl $0, %ebx 			
movl array, %eax	
jmp end_of_array 		
			


calculating:  		
movl array(,%ecx,4), %eax   
				 
or $0b00000000000000000000000000010000, %eax  
addl %eax, %ebx		
jge adding 

		
adding:			
inc %ecx			
	

end_of_array:  		
cmpl $elem_in_array, %ecx	
jl calculating
pushl %ebx  
pushl $str_d  
call printf  
addl $8, %esp
ret
