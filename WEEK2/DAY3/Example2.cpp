// How 2 nodes in linked list stored and connected as OS level.

/*
    [0000 0000] 0x100H
    [0000 0000] 0x101H
    [0000 0000] 0x102H
    [0000 1001] 0x103H

    [0000 0000] 0x451H
    [0000 0000] 0x452H
    [0000 0000] 0x453H
    [0000 1010] 0x454H
*/

/*
    OS

    step 1: reserve 4 bytes of memory
            0x100....0x103H
    step 2: Write the data 9  or 0000 0000 0000 1001
                            (10)                    (2)
    step 3: reserve 4 bytes of memory
            0x451H....0x452H
    step 4: Write the data 10  or 0000 0000 0000 1010
                            (10)                     (2)
    OS Automatically does this allocations internally.
*/

// Programming library role starts here
/*
    NODE
    [nullptr |          9         | 0x451H]
    0x92H    0x100H               0x103H    0x1bH

    NODE 0x450H
    [nullptr | 0000 0000 0000 1010 | nullptr]
    0x443H    0x451H                0x454H    0x1bH

*/
