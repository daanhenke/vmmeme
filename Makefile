.PHONY: configure
configure:
	@[ ! -d "./build" ] && meson setup build --cross-file ./meson/x86_64-uefi-windows.cross.ini || true

.PHONY: hypervisor
hypervisor: configure
	@cd build && ninja

.PHONY: qemu
qemu: hypervisor
	@python ./scripts/run_vm.py
