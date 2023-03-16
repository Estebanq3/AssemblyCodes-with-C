.section .text
    .globl _fibonacci
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