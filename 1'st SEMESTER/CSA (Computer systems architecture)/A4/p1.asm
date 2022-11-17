bits 32 

global start        

extern exit               
import exit msvcrt.dll    
                          
segment data use32 class=data
b db 01011010b
a dw 1001101110111110b
c db 0

segment code use32 class=code
    start:
    ;Replace the bits 0-3 of the byte B by the bits 8-11 of the word A.   
    mov bl, 0
    mov ax, 0
    mov cl, 0
    
    mov bl, [b] ; bl = 01011010
    mov bh, 0; bx = 0000000001011010
    mov ax, [a] ; ax = 1001101110111110
    
    and bl, 11110000b ; bits 0-3 of b now have the value 0
    
    and ax, 0000111100000000b ; bits 8-11 of a are now isolated
    mov cl, 8
    ror ax, cl ; rotate 8 times to the right
    or bx, ax ; bx = 0000000001011011 = 91
    
    mov [b], bl ; c = 01011011 = 91
        
    push    dword 0      
    call    [exit]       
