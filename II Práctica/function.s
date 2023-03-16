.section .text    	 	# inicia la seccion de codigo
    .globl _updateColor # declara sum como nombre global
    .globl _sumColors
	.globl _updateMatrix
	.globl _sumMatrix

#0x4 matriz
#0x8 indice
#0xC columna

#--------------------------------------------------------------
#UPDATE COLOR Pregunta1
_updateColor:	
	movl 0x4(%esp),%ebx  #ebx = matriz de colores
	movl 0x8(%esp),%ecx  #ecx = indice o fila
	movl 0xC(%esp),%edx  #edx = columna
	
CalcularDireccion:
	imul $3,%ecx  #ecx = indice*3
	addl %edx,%ecx #ecx = (indice*3)+columna
	imul $4,%ecx #ecx  = 4*((indice*3)+columna)
	addl %ebx,%ecx #ecx = Matriz + (4*((indice*3)+columna))
	movl 0x10(%esp),%edx #edx = value
	movl %edx, (%ecx)

EndColor: 
	ret

#--------------------------------------------------------------
#SUM COLORS Pregunta2

_sumColors:
	movl 0x4(%esp),%ebx  # ebx = matriz
	movl $0,%edx #edx = 0 fila
	movl $0,%ecx #ecx = 0 columna
	movl $0,%eax #sumaAcumulada
	movl $0,%edi

Comprobar1:
	cmpl $3,%ecx #mientras que columna no sea 3
	jl Comprobar2
	addl $1,%edx
	movl $0, %ecx

Comprobar2:
	cmpl $8,%edx #edx-8
	je EndSumColors

Ciclo:
	movl %edx,%edi #edi = edx indice
	imul $3,%edi  #edi = indice*3
	addl %ecx,%edi #edi = (indice*3)+columna
	imul $4,%edi #edi  = 4*((indice*3)+columna)
	addl %ebx,%edi #edi = Matriz + (4*((indice*3)+columna))
	addl (%edi),%eax
	addl $1,%ecx
	jmp Comprobar1

EndSumColors:
	ret
#-------------------------------------------------------------
#UPDATE MATRIX Pregunta3
_updateMatrix:
	movl 0x4(%esp),%ebx  #ebx = matriz de colores
	movl 0x8(%esp),%ecx  #ecx = indice o fila
	movl 0xC(%esp),%edx  #edx = columna o digit

AccederMemoria:
	imul $4,%ecx # ecx= indice*4
	addl %ebx,%ecx # ecx = (indice*4)+matriz
	movl (%ecx),%ecx #ecx = mem[(indice*4)+matriz]
	movl %edx,%ebx #ebx = digit
	imul $4,%ebx #ebx = 4*digit
	addl %ebx,%ecx # ecx= 4*digit+mem[(indice*4)+matriz]
	movl (%ecx),%eax
	movl 0x10(%esp),%ebx
	movl %ebx,(%ecx)

EndUpdateDin:
	ret
#-------------------------------------------------------------
#SUMMATRIX Pregunta4
_sumMatrix:
	movl 0x4(%esp),%ebx  # ebx = acceso
	movl 0x8(%esp),%edi #edi = numero de filas
	movl 0xC(%esp),%esi # esi = numero de columnas
	movl $0,%ecx #ecx = 0 fila o indice contador
	movl $0,%edx #edx = 0 columna o digit contador
	movl $0,%eax #sumaAcumulada
	

ComprobarSum1:
	cmpl %edi,%ecx #mientras que columna no sea limite
	jl ComprobarSum2
	addl $1,%edx
	movl $0, %ecx

ComprobarSum2:
	cmpl %esi,%edx #edx-8
	je EndSum

CicloSum:
	movl %ecx,%ebx
	imul $4,%ebx # ebx= indice*4
	addl 0x4(%esp),%ebx # ebx = (indice*4)+matriz
	movl (%ebx),%ebx #ebx = mem[(indice*4)+matriz]
	
	movl %edx,%edi
	imul $4,%edi
	addl %edi,%ebx
	movl 0x8(%esp),%edi #edi = numero de filas

	addl (%ebx),%eax
	#addl $1,%eax
	addl $1,%ecx
	jmp ComprobarSum1

EndSum:
	ret


