xorriso -as mkisofs \
    -R -r -J \
    -e limine-uefi-cd.bin \
    -no-emul-boot \
    -isohybrid-gpt-basdat \
    -o my_os.iso \
    iso_root
