/*
 * memsimu.c memory file for simulation. The simulate of LoadAddr, WriteMem,
 * WriteLatch, ReadLatch, ResetDevice functions,  for simulate the memory
 * write, and read due bootloader task.
 * TODO This is a file for simulating only !!
 */

void LoadAddr()
{

}

void WriteMem()
{

}

void WriteLatch()
{

}

void ReadLatch()
{

}

void ResetDevice()
{

}
/*.include "p30Fxxxx.inc"

.global _LoadAddr,_WriteMem,_WriteLatch,_ReadLatch,_ResetDevice	;C called

_LoadAddr:	;W0=NVMADRU,W1=NVMADR - no return values
	mov	W0,NVMADRU
	mov	W1,NVMADR

	return

;***************************************************************
_WriteMem:	;W0=NVMCON - no return values
	mov	W0,NVMCON
	mov	#0x55,W0	;Unlock sequence - interrupts need to be off
	mov	W0,NVMKEY
	mov	#0xAA,W0
	mov	W0,NVMKEY
	bset NVMCON,#WR
	nop				;Required
	nop
1:	btsc NVMCON,#WR	;Wait for write end
	bra 1b

	return

;***************************************************************
_WriteLatch: ;W0=TBLPAG,W1=Wn,W2=WordHi,W3=WordLo - no return values
	mov	W0,TBLPAG
	tblwtl W3,[W1]
	tblwth W2,[W1]

	return

;***************************************************************
_ReadLatch: ;W0=TBLPAG,W1=Wn - data in W1:W0
	mov	W0,TBLPAG
	tblrdl [W1],W0
	tblrdh [W1],W1

	return


;***************************************************************
_ResetDevice:

	goto 0x702

	return
.end


;***************************************************************
*/