bits 32 

global start        

extern exit               
import exit msvcrt.dll    

segment data use32 class=data
M dd 01110111010101111001101110111110b
N dd 01110100010111010101001011010001b
P dd 00000000000000000000000000000000b

segment code use32 class=code
    start:
    ;Given the doublewords M and N, compute the doubleword P as follows.
    ;the bits 0-6 of P are the same as the bits 10-16 of M
    ;the bits 7-20 of P are the same as the bits 7-20 of (M AND N).
    ;the bits 21-31 of P are the same as the bits 1-11 of N.
    mov ebx, 0 ; the result is going to be in ebx
    mov eax, 0;
    
    mov eax, [M]
    and eax, 00000000000000011111110000000000b ; we isolate the 10-16 bits from M to add in P
    mov cl,10
    ror eax,cl ; rotating 10 bits to the right
    or ebx,eax ; putting the result in ebx
    
    mov eax,[M]
    mov ecx,[N]
    
    and eax,ecx ; result is in eax
    and eax, 00000000000111111111111110000000b ; we isolate bits 7-20 
    or ebx,eax ; putting the result in ebx
    
    mov eax, [N]
    and eax, 00000000000000000000111111111110b ; we isolate bits 1-11
    mov cl, 20
    rol eax,cl ; rotating to the left
    or ebx,eax 
    
    mov [P],ebx ; result is in P
        
    push    dword 0      
    call    [exit]       
