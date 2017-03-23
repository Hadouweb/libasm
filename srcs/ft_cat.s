%define MACH_SYSCALL(nb)	0x2000000 | nb
%define READ				3
%define WRITE				4
%define BUFF_SIZE			1024

section .bss
	buff: resb BUFF_SIZE

section .text
	global _ft_cat

_ft_cat:
	push	rbp
	mov		rbp, rsp					; Sauvegarde de la pile

	push	rbx
	mov		rbx, rdi

loop:
	mov		rdi, rbx
	lea		rsi, [rel buff]				; Load Effective Address
	mov		rdx, BUFF_SIZE				; Nombre de byte au'on souhaite lire
	mov		rax, MACH_SYSCALL(READ)		; On place l'indice du syscall read dans rax
	syscall
	jc		end							; Jump if carry (error)


	mov		rdi, 1						; Param 1 = stdout
	lea		rsi, [rel buff]				; Param 2 = buff
	mov		rdx, rax					; Param 3 = size
	mov		rax, MACH_SYSCALL(WRITE)	; On place l'indice du syscall write dans rax
	syscall
	jc		end							; Jump if carry (error)

	cmp		rax, 0						; Si le retour de read vaut 0
	jle		end							; On sort de la boucle
	
	jmp loop							; On continue la boule read et write

end:
	pop		rbx
	leave
	ret
