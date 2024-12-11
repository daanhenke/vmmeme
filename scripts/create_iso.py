from os.path import join
from pycdlib import PyCdlib
from io import BytesIO
from os import stat


def add_file_to_iso(iso: PyCdlib, source_path: str, file_path: str):
    full_path = join(source_path, file_path)
    file_stats = stat(full_path)
    with open(full_path, 'rb') as file:
        buf = BytesIO(file.read())
        iso.add_fp(buf, file_stats.st_size, '/' + file_path)

def create_iso(output_path: str, source_path: str):
    iso = PyCdlib()
    iso.new()
    add_file_to_iso(iso, source_path, 'EFI/BOOT/BOOTX64.EFI')

    with open(output_path, 'wb') as output_file:
      iso.write_fp(output_file)

create_iso('./build/rootfs.iso', './dist')
