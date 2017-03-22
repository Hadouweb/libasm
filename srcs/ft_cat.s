; Prototype : void ft_cat(int fd);
;

%define MACH_SYSCALL(nb)	0x2000000 | nb
%define READ				3
%define WRITE				4
%define BUFF_SIZE			1024

section .bss
	buffer: resb BUFF_SIZE

section .text
	global _ft_cat

_ft_cat:
	push rbp
	mov rbp, rsp

	; Sauvegarde de rbx, utilise pour memoriser le file descriptor
	push rbx
	mov rbx, rdi

boucle:
	; Lecture...
	mov rdi, rbx
	lea rsi, [rel buffer]
	mov rdx, BUFF_SIZE
	mov rax, MACH_SYSCALL(READ)
	syscall

	; En cas d'erreur, le bit carry est set
	jc fin

	; Detection de la fin de lecture
	cmp rax, 0
	jle fin

	; Ecriture
	mov rdi, 1
	lea rsi, [rel buffer]
	mov rdx, rax
	mov rax, MACH_SYSCALL(WRITE)
	syscall
	
	; En cas d'erreur, le bit carry est set
	jc fin
	
	jmp boucle ; Recommence jusqu'a la fin de la lecture

fin:
	; Restauration de rbx
	pop rbx

	leave
	ret
