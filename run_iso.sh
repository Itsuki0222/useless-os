qemu-system-x86_64   -drive if=pflash,format=raw,readonly=on,file=/usr/share/ovmf/x64/OVMF_CODE.4m.fd   -drive if=pflash,format=raw,file=./MY_VARS.fd   -cdrom my_os.iso   -display gtk   -m 512M
