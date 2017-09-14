.486
.model flat, stdcall
option casemap :none ;case sensitive

;;------------------macros-----------------
include \masm32\include\masm32.inc
include \masm32\include\kernel32.inc
includelib \masm32\lib\masm32.lib
includelib \masm32\lib\kernel32.lib


.code
_start: 
	mov ecx, 32
    jmp task4
task1:
    mov eax,0
    mov ecx, 100
start_loop:
    add eax, ecx
    loop start_loop

task2:
    cmp eax, ebx
    ja eax_bigger_ebx
    cmp ecx, ebx
    ja ecx_bigger_ebx
    mov eax, ebx
    jmp end_prog

eax_bigger_ebx:
    cmp eax, ecx
    ja end_prog
    mov eax, ecx
    jmp end_prog

ecx_bigger_ebx:
    mov eax, ecx
    jmp end_prog

	
task3:
	mov eax, 0AABBCCDDh
	mov bl, al
	mov al, ah
	mov ah, bl
	mov bx, ax
	rol eax, 16
	mov bl, al
	mov al, ah
	mov ah, bl
	mov bx, ax
	
task4:
	mov eax, ecx
	xor ebx, ebx
	mov ecx, 32
start4_loop:
	shl eax, 1
	JNC start4N_loop
	inc ebx
start4N_loop:
	loop start4_loop
	cmp ebx, 1
	je succes4
	mov eax, 0FFFFFFFFh
	jmp end_prog
succes4:
	mov ax, 0
	jmp end_prog
	
end_prog:
	push eax
    call ExitProcess
end _start