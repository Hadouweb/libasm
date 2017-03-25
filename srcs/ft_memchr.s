section .text
	global _ft_memchr

_ft_memchr:
	push	rbp
	mov		rbp, rsp
	mov		r10, rdi		; r10 = param1
	mov		rax, rsi		; rax = param2
	mov		rcx, rdx		; rcx = param3
	repnz	scasb			; while (rcx != 0) { rdi++; rcx--; }
	sub		rdx, rcx 		; param3 - rcx
	mov		rax, r10		; rax = ptr param1
	add		rax, rdx		; rax += rdx
	sub		rax, 1
	cmp		[rax], sil 
	jne		not_found
	jmp		end
	
not_found:
	mov		rax, 0
	jmp		end

end:
	leave
	ret
