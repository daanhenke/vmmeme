from os import makedirs
from os.path import dirname, exists
from shutil import copyfile
from subprocess import run


def copy(src: str, dest: str):
    parent_dir = dirname(dest)
    if not exists(parent_dir):
        makedirs(parent_dir)

    copyfile(src, dest)


copy('./build/hypervisor/hypervisor.efi', './dist/EFI/BOOT/BOOTX64.EFI')

run([
    'qemu-system-x86_64',
      '-smbios', 'type=0,uefi=on',
      '-bios', './assets/blobs/DEBUGX64_OVMF.fd',
      '-drive', 'format=raw,file=fat:rw:./dist',
      '-net', 'none'
])
