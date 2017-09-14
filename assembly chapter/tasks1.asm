%include "io.inc"

section .text
    global CMAIN
CMAIN:
    mov ebp, esp; for correct debugging
    ;write your code here
    
    push 4
    push 5
    call pow
    PRINT_UDEC 1, eax
    xor eax, eax
    pop ebx
    pop ebx
    ret
    
    pow: ;Pow(base, exponent)
    push ebp
    mov ebp, esp
    push edi
    push esi
    push ecx
    push ebx
    mov eax, [ebp + 8];base
    mov ecx, [ebp + 12];exponent
    mov ebx, eax
    dec ecx
pow_loop:
    mul ebx
    loop pow_loop
    pop ebx
    pop ecx
    pop esi
    pop edi
    pop ebp
    ret