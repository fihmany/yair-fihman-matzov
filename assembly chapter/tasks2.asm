%include "io.inc"

section .data
    msg1 db 'hey', 0
    msg2 db 'Hey', 0

section .text
    global CMAIN
CMAIN:
    mov ebp, esp
    mov esi, msg2
    push esi
    mov esi, msg1
    push esi
    call Strcmp
    PRINT_UDEC 1, eax
    xor eax,eax
    pop esi
    pop esi
    ret
    
Strcmp: ;strcmp(str1, str2) 0 - if equal, not zero if not
    push ebp
    mov ebp, esp
    push edi
    push esi
    push ebx
    xor eax, eax
    xor edi, edi
    mov esi, [ebp + 8];msg1
    mov edi, [ebp + 12];msg2
    dec edi
startcmp:
    inc edi
    lodsb
    mov ebx, [edi]
    cmp bl, al
    jne notEqual
    
    cmp eax ,0;check if str1 end if not keep looping
    jne startcmp
    cmp byte [edi], 0;check if str2 end if not string arent the same
    jne notEqual
    mov eax, 0
    jmp endcmp
notEqual:
    mov eax,[edi]
    sub al, byte [esi]
    jmp endcmp
endcmp:
    pop ebx
    pop esi
    pop edi
    pop ebp
    ret