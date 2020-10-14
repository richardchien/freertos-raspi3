.section ".text.boot"

.globl _boot
_boot:
	// use core 0 only, hang core 1-3
	mrs		x1, mpidr_el1
	and		x1, x1, #3
	cmp		x1, #0
	bne		hang

	// drop to el1
	bl		elX_to_el1

	// setup stack
	ldr		x1, =_boot
	mov		sp, x1

	// clear bss
	ldr		x1, =__bss_start
	ldr		w2, =__bss_size
1:	cbz		w2, 2f
	str		xzr, [x1], #8
	sub		w2, w2, #1
	cbnz	w2, 1b

2:	bl		main

hang:
	b		hang

elX_to_el1:
	adr		x8, .Ltarget
	mov		x9, #0x3c5 // D=1, A=1, I=1, F=1, M=EL1h

	mrs		x0, CurrentEL
	cmp		x0, #(0b01 << 2) // EL1
	beq		.Ltarget
	cmp		x0, #(0b10 << 2) // EL2
	beq		.Lin_el2

.Lin_el3:
	mov		x2, #0x5b1 // RW=1, HCE=1, SMD=1, RES=1, NS=1
	msr		scr_el3, x2
	msr		elr_el3, x8
	msr		spsr_el3, x9

.Lin_el2:
	mov		x2, #(1 << 31) // Set EL1 to AArch64
	msr		hcr_el2, x2
	msr		elr_el2, x8
	msr		spsr_el2, x9

	isb
	eret

.Ltarget:
	ret
