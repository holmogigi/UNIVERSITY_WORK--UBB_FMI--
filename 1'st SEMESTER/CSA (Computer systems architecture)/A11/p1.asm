bits 32 
global start        

extern exit, scanf, fopen, fprintf, fclose            
import exit msvcrt.dll
import scanf msvcrt.dll
import fopen msvcrt.dll
import fprintf msvcrt.dll
import fclose msvcrt.dll

extern maximum
                         
segment data use32 class=data
    file_name db "max.txt", 0   ;filename to be created   
    access_mode db "w", 0   ;file access mode: w - creates an empty file for writing
    file_descriptor dd -1   ;variable to hold the file descriptor 
    n dd 0   ;variable to read the values
    format1 db "%d", 0   ;%d <=> a decimal number (base 10)
    format2 db "%x", 0   ;%x <=> a hexadecimal number (base 16)

segment code use32 class=code
start:
    ;Read a string of signed numbers in base 10 from keyboard.Determine the minimum value of the string and write it in the file min.txt(it will be created) in 16 base
    ;call fopen() to create the file
    ;eax = fopen(file_name, access_mode)
    push dword access_mode     
    push dword file_name
    call [fopen]
    add esp, 4*2    ;clean-up the stack
        
    mov [file_descriptor], eax    ;store the file descriptor returned by fopen 
        
    cmp eax, 0    ;check if fopen() has successfully created the file (EAX != 0)
    je final    ;if not jump to final
        
    mov ebx, 0    ;variabile to hold the maximum
    
    repeta:
    
        push dword n    ;address of n, not value
        push dword format1
        call [scanf]    ;call function scanf for reading 
        add esp, 4*2    ;clean-up the stack
            
        cmp dword[n], 0    ;check if n is 0
        je opreste     ;if it is then jump to opreste
        
        mov eax, [n]    ;put n in eax
        push eax    ;push the value on the stack
        
        call maximum    ;call maximum function
            
    jmp repeta
        
    opreste:
    
    ;write to file using fprintf()
    ;fprintf(file_descriptor, text)
    push dword ebx
    push dword format2
    push dword [file_descriptor]
    call [fprintf]
    add esp, 4*3    ;clean-up the stack
    
    ;call fclose() to close the file
    ;fclose(file_descriptor)
    push dword [file_descriptor]
    call [fclose]
    add esp, 4    ;clean-up the stack
    
    final:
    
    push    dword 0      
    call    [exit]
