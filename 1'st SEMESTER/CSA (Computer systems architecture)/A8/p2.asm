bits 32 

global start        

extern exit, fopen, fclose, fprintf       
import exit msvcrt.dll
import fopen msvcrt.dll
import fclose msvcrt.dll  
import fprintf msvcrt.dll

segment data use32 class=data
    name_file db "problem25.txt", 0
    mode_acces db "w", 0
    descriptor_file dd -1
    text db "Ar trebui sa existe ciment cu numele Ana"
    len equ $-text
    ftext times len db 0
    
segment code use32 class=code
    start:  
        ;A file name and a text (defined in data segment) are given. The text contains lowercase letters, uppercase letters, digits and special characters. 
        ;Replace all spaces from the text with character 'S'. Create a file with the given name and write the generated text to file.
        cld 
        mov ecx, len
        mov ebx, 0
        repeatt:
            lodsb; each carachter from text will be stored in Al
            cmp Al, ' '
            jne other_than_space
                mov Al, 'S'; we change the space into the character S
            other_than_space:
            mov [ftext+ebx], Al; here we move the string text in the string ftext with the proper changes
            inc ebx
        loop repeatt
        ; here starts the file work
        push dword mode_acces
        push dword name_file
        call [fopen]
        add esp, 4*2
        
        mov [descriptor_file], eax
        cmp eax, 0
        je final
            ;here we write the new text in the file
            push dword ftext
            push dword [descriptor_file]
            call [fprintf]
            add esp, 4*2
            
            ; here we close the file
            push dword [descriptor_file]
            call [fclose]
            add esp, 4
            
        final:
 
        push    dword 0      
        call    [exit]       
