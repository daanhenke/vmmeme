.PHONY: hypervisor configure

configure:
	@[ ! -d "./build" ] && meson setup build --cross-file ./meson/x86_64-uefi-windows.cross.ini || true

hypervisor: configure
	@cd build && ninja
