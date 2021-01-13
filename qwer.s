.name           "champion executable" #commentaire
.comment        "men neyytk baghi terbe7ni ?" #wa33333

entree:	live	%42		# entree
	ld	%0,r5
	ld	%0,r5
	zjmp	%:bite

tir:	sti	r1,%:tirb,%1
	ld	%2304,r10
	ld	%1,r5
	ld	%0,r11

	ld	%4,r3
tirf:	live	%42
	fork	%:tirop
	live	%742
	sub	r3,r5,r3
	zjmp	%:top
	ld	%0,r11
	fork	%:tirvd
	live	%42
	sti	r10,%-510,%0
	sti	r10,%-404,%0
	sti	r10,%-303,%0
	sti	r10,%-202,%0
	ld	%0,r11
	zjmp	%:tirf