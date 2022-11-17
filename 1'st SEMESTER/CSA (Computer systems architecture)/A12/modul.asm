bits 32 
global _compare_max      
segment data public data use32
segment code public code use32
_compare_max:
    ;Read a string of signed numbers in base 10 from keyboard.Determine the maximum value of the string and write it in the file max.txt(it will be created) in 16  base
    push ebp
    mov ebp,esp
    
    mov eax,[ebp+8] ; eax takes the value of a in the funciton
    mov ebx,[ebp+12] ; ebx takes the value of b in the funciton
    
    ; comparing the two values 
    cmp eax,ebx
    ; jumping if a>b
    jl .change
    jmp .exit_
    
    ;moving the max into eax if a>b
    .change:
        mov eax, ebx
    .exit_:
    mov esp,ebp
    pop ebp
    ret
