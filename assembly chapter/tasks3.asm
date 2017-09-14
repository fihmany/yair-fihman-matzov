%include "io.inc"

section .text
global CMAIN
CMAIN:
    mov ebp, esp; for correct debugging
    push 10
    call fib
    pop ebx
    PRINT_UDEC 1, eax
    xor eax, eax
    ret
    
fib: ;fib(int n) n- the requsted element in the series
    push ebp
    mov ebp, esp
    push edi
    push esi
    push ebx
    push ecx
    mov ecx, [ebp + 8];n
    xor eax,eax
    xor ebx,ebx
    ;if (n == 1 || n == 2) {return 1;}
    cmp ecx,1 
    je one_or_two
    cmp ecx,2 
    je one_or_two
    dec ecx
    push ecx
    call fib ;(fib(n-1))
    add ebx, eax
    pop eax
    dec ecx
    push ecx
    call fib; (fib(n-2))
    pop ecx
    add ebx, eax
    mov eax, ebx
    jmp end_fib
one_or_two:
    mov eax, 1
    jmp end_fib
    
end_fib:
    pop ecx
    pop ebx
    pop esi
    pop edi
    pop ebp
    ret
    
    
    
    
    
    
    
    
    
    