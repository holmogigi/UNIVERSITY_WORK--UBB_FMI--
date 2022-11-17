bits 32 

global start        

extern exit, printf, scanf            
import exit msvcrt.dll   
import printf msvcrt.dll
import scanf msvcrt.dll

segment data use32 class=data
    n dd  0; In this variable we'll store the value rode from the keyboard
    message db "n=", 0; 
    format_10 db "%d", 0;
    format_16 db "%x", 0;

segment code use32 class=code
    start:
        ;Read a number in base 10 from the keyboard and display the value of that number in base 16 (Example: Read: 28; display: 1C)
        push dword message; on the stack we'll put the adress of the string
        call [printf]; we call the function printf 
        add esp, 4*1; we free the stack
        
        push dword n; here we have the adress of n
        push dword format_10; 
        call [scanf]; we call the scanf for reading
        add esp, 4*2; we free the stack
        
        push dword [n]; here we have the value of n
        push dword format_16; the format in which we want to print our variable(base 16)
        call [printf]; we call the printf function
        add esp, 4*2; here we free the stack
        
        push    dword 0      
        call    [exit]      
