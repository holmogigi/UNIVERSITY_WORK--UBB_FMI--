bits 32 

global start        

extern exit               
import exit msvcrt.dll    

segment data use32 class=data
    S db 01011100b , 10001001b , 11100101b; 5C | 89 | E5
    L equ $-S
    D times L db 0; we should get here A7 | 91 | 3A

segment code use32 class=code
    start:
        ;A string of bytes is given. Obtain the mirror image of the binary representation of this string of bytes
        mov ecx , 0
        mov cl , L  ; we keep the length of S in CL
        mov esi , S     ; we keep the offset from the beggining of S in esi
        mov edi , D+L-1     ; we keep the offset from the final of D in edi
        
        loop_string:
            cld     ; we go through S from left to right, DF = 0
            lodsb   ; we put element from S in AL 
            
            mov dl , cl     ; we save the position from S in which we remain
            mov cl , 8      ; we do the mirror image for 8 bits  (a byte)
            mov ebx , 0     ; we clear EBX , in which we will keep the mirror image
            
            mirror_image:
                rcl al , 1      ; we take the bits one by one by using the carry flag
                rcr bl , 1      ; we put the bits one by one in reverse order in BL
            loop mirror_image     ; loop will be done 8 times for each bit in the byte
            
            mov al , bl     ; we put the palindrome into AL
            mov cl , dl     ; we resume to the outer loop
            
            std    ; we go through D from right to left because DF = 1
            stosb   ; we put element from AL in D
        loop loop_string
        
        push    dword 0     
        call    [exit]
