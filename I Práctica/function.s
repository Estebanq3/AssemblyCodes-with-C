.section .text    	 	# inicia la seccion de codigo
    .globl _sum     	# declara sum como nombre global
    .globl _prime
	.globl _fibonacci

_sum:	
	movl 0x4(%esp),%ecx
	movl $0,%eax
Sumar:
	cmpl $0,%ecx
	je EndSum
	addl %ecx,%eax
	subl $1,%ecx
	jne  Sumar

EndSum: 
	ret

_prime:
	movl 0x4(%esp),%eax		
Especiales:
	cmpl $0,%eax
	je NotPrime
	cmpl $1,%eax
	je NotPrime
	cmpl $4,%eax
	je NotPrime
	jmp CheckPrime
NotPrime:
	movl $0, %eax
	jmp End
CheckPrime:
	movl $2, %ecx
	movl $2, %ebx		
Ciclo:
	movl 0x4(%esp),%eax
	cdq
	divl %ebx
	cmpl %eax,%ecx
	jl AccionFor
	movl $1,%eax
	jmp End
AccionFor:
	addl $1,%ecx
	movl 0x4(%esp),%eax
	cdq
	divl %ecx
	cmpl $0,%edx
	je NotPrime
	jmp Ciclo

End: 
	ret



_fibonacci:
    pushl %ebp
    pushl %edi
    pushl %esi
    pushl %ebx
    movl 0x14(%esp),%eax
    cmpl $1,%eax
    jle PopSection
    movl 0x14(%esp),%ebx
    subl $1,%ebx
    pushl %ebx
    call _fibonacci
    popl %ebx
    movl %eax,%esi
    subl $1,%ebx
    pushl %ebx
    call _fibonacci
    popl %ebx
    addl %esi,%eax
    jmp PopSection
PopSection:
    popl %ebx
    popl %esi
    popl %edi
    popl %ebp
    ret





