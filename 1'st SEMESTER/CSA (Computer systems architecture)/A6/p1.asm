bits 32 

global start        

extern exit               
import exit msvcrt.dll    

segment data use32 class=data
a dw 1234h,1A2Bh,1E98h
len equ ($-a)/2 ; lenght of word string
b1 db 0
b2 db 0

segment code use32 class=code
    start:
        ;Given an array A of words, build two arrays of bytes:  
        ;-array B1 contains as elements the higher part of the words from A
        ;-array B2 contains as elements the lower part of the words from A
        mov esi, a; is esi we keep the offset of string a
        cld ; df=0, the string is parsed from left to right
        mov ecx, len ; we'll have len steps for the loop
        mov ebx, 0 ; index for first string
        mov edx, len - 1; index for second string
    
        repeta: 
            lodsb ; high byte in al
            mov [b1+ebx],al
            lodsb ; low byte in al
            mov [b2+edx],al
            inc ebx
            inc edx
        loop repeta
        
        push    dword 0     
        call    [exit]       
