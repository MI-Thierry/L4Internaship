org 0x7C00
bits 16

%define ENDL 0x0d, 0x0a

start:
    jmp main

;Prints a string to the screen
;Params
    ;- ds:si points to the string
puts:
    ;Save the register we're going to modify on the stack
    push si
    push ax

.loop:
    lodsb ;loads the next character on the al 
    or al, al
    jz .done ;Verify if the character is null.

    mov ah, 0x0e
    mov bh, 0
    int 0x10
    jmp .loop

.done:
    pop ax
    pop si
    ret

main:
    ;Setup data segments
    mov ax, 0
    mov ds, ax
    mov es, ax

    ;Setup stack
    mov ss, ax
    mov sp, 0x7C00

    ;Print message
    mov si, msg_hello
    call puts

    hlt

.halt:
    jmp .halt

msg_hello: db'Hello, world', ENDL, 0

times 510-($-$$) db 0
dw 0AA55h