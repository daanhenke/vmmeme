.PHONY: configure
configure: build/.gitignore

build/.gitignore:
	meson setup build --cross-file ./meson/x86_64-uefi-windows.cross.ini

.PHONY: hypervisor
hypervisor: configure
	@cd build && ninja

.PHONY: qemu
qemu: hypervisor
	@python ./scripts/run_vm.py
