section .text
	global _ft_memcmp

_ft_memcmp:
	push	rbp
	mov		rbp, rsp
	mov		rax, 0				; ret = 0
	cmp		rdx, 0				; if param3 == 0
	je		end					; return 0
	cmp		rdi, 0				; if param1 == null
	je		end					; return 0
	cmp		rsi, 0				; if param2 == null
	je		end					; return 0
	
loop:
	mov		rcx, rdx			; rcx = n
	rep		cmpsb				; while (*rdi == *rsi && rcx != 0) { rdi++; rsi++; rcx--; }
	mov		rax, [rdi - 1]		; revenir sur la diff
	mov		rbx, [rsi - 1]		; revenir sur la diff
	and		rax, 0xff			; ascii - 0xff
	and		rbx, 0xff			; ascii - 0xff
	sub		eax, ebx

end:
	leave
	ret
