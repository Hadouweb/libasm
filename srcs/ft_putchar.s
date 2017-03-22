; Prototype : void ft_putchar(int c)
;

%define MACH_SYSCALL(nb)	0x2000000 | nb
%define WRITE				4

section .bss
	caractere: resb 1

section .text
	global _ft_putchar

_ft_putchar:
	push rbp
	mov rbp, rsp

	lea rcx, [rel caractere]		; Met dans rcx l'adresse de la variable caractere
	mov rax, rdi					; Copie le caractere dans rax pour recuperer al
	mov [rcx], al					; Stock le caractere a l'adresse pointee par rcx
	
	mov rdi, 1						; Sortie standard
	lea rsi, [rel caractere]		; Adresse du caractere
	mov rdx, 1						; 1 seul caractere
	mov rax, MACH_SYSCALL(WRITE)
	syscall

	leave
	ret
