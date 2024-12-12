from os.path import join, isfile, isdir
from pycdlib import PyCdlib
from io import BytesIO
from os import stat, listdir

def add_directory_to_iso(iso, source_dir, iso_path="/"):
  for entry in listdir(source_dir):
    full_path = join(source_dir, entry)
    iso_entry_path = f"{iso_path}/{entry}"

    if isdir(full_path):
      # Add directory to ISO
      iso.add_directory(iso_entry_path)
      # Recursively add the contents of the directory
      add_directory_to_iso(iso, full_path, iso_entry_path)
    elif isfile(full_path):
      iso.add_file(full_path, iso_entry_path.upper())
    else:
      print(f"Skipping unsupported file type: {full_path}")

# Example usage
def create_iso_with_directory(source_dir, output_iso):
  iso = PyCdlib()
  iso.new()

  add_directory_to_iso(iso, source_dir)

  # Write the ISO to the specified output file
  iso.write(output_iso)
  iso.close()

create_iso_with_directory('dist/bootfs', './dist/bootfs.iso')
