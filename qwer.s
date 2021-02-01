.name           "champion executable" #commentaire
.comment        "men neyytk baghi terbe7ni ?" #wa33333

loop:
        sti r1, %:live, %1
live:
        live %0
        ld %0, r2
        zjmp %:loop
