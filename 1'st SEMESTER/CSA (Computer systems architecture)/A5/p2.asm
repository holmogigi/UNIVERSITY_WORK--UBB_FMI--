bits 32 

global start        

extern exit               
import exit msvcrt.dll    

segment data use32 class=data
S1 db '+', '4', '2', 'a', '8', '4', 'X', '5' 
len1 equ $-S1  
S2 db 'a', '4', '5'
len2 equ $-S2
counter dd 0
D times len1 db 0
bool db 0
result_counter dd 0

segment code use32 class=code
start:
    ;Two character strings S1 and S2 are given. Obtain the string D which contains all the elements of S1 that do not appear in S2
    mov ecx, len1; in ecx I have the length of our first string
    first_loop:; in this loop i go through every element of s1
        mov ebx, S1; here I have the address of s1
        add ebx, len1; 
        sub ebx, ecx ; I add the len1 and sub the ecx in order to have the address from s1 where I want to start from
        mov bl, [ebx]; I move in bl the first byte that starts at address ebx
        mov [counter], ecx; I save in counter the ecx of the first string so that i can continue the first loop after doing the second
        mov ecx, len2; in ecx I have the lenght of our second string
        mov BYTE [bool], 0; here i have a boolean variable
        
        second_loop:; in this loop, for every element in s1 i go through all the elements in s2
            mov edx, S2; here I have the address of s1
            add edx, len2 
            sub edx, ecx; I add the len2 and sub the ecx in order to have the address from s2 where I want to start from
            cmp bl, [edx]; I compare bl with the first byte that starts at address edx
            jne not_equal
                mov BYTE [bool], 1; This instruction will be done only if the character form s1 is the same with the character from s2
            not_equal:    
        loop second_loop
        
        mov ecx, [counter]; I get back to my ecx to continue the first loop
        cmp BYTE [bool], 1; I check if i entered on the not equal which means that i found the character from s2 in s1
        je not_good; jump if we found the character from s2 in s1
            mov edx, D; here I have the address of D
            add edx, [result_counter]
            mov [edx], bl; if the character in s1 is correct I put it in d
            inc DWORD [result_counter]; I increse the variable that remembers the position in string d
        not_good:  
    loop first_loop 
    
  push dword 0      
  call [exit]
