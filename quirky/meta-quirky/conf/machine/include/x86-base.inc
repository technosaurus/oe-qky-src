#
# Base machine settings for X86 architecture BSPs
#

#
# common settings for X86 machines
#
MACHINE_FEATURES += "screen keyboard pci usbhost ext2 ext3 x86 \
                     acpi serial usbgadget alsa"

MACHINE_EXTRA_RRECOMMENDS += "kernel-modules"

IMAGE_FSTYPES += "live"

KERNEL_IMAGETYPE ?= "bzImage"

SERIAL_CONSOLE ?= "115200 ttyS0"

#
# kernel-related variables
#
PREFERRED_PROVIDER_virtual/kernel ??= "linux-quirky"
PREFERRED_VERSION_linux-quirky ??= "4.10%"

#
# XSERVER subcomponents, used to build the XSERVER variable
# BK ref: https://patchwork.openembedded.org/patch/133129/
XSERVER_X86_BASE = "xserver-xorg \
           xf86-input-mouse \
           xf86-input-keyboard \
           xf86-input-evdev \
           xf86-input-synaptics \
           "

XSERVER_X86_EXT = " \
           ${@bb.utils.contains('DISTRO_FEATURES', 'opengl', 'xserver-xorg-extension-glx', '', d)} \
           xserver-xorg-module-libint10 \
           "

XSERVER_X86_I915 = "xf86-video-intel \
           ${@bb.utils.contains('DISTRO_FEATURES', 'opengl', 'mesa-driver-i915', '', d)} \
           "

XSERVER_X86_I965 = "xf86-video-intel \
           ${@bb.utils.contains('DISTRO_FEATURES', 'opengl', 'mesa-driver-i965', '', d)} \
           "

XSERVER_X86_VESA = "xf86-video-vesa"

XSERVER_X86_FBDEV = "xf86-video-fbdev"

XSERVER_X86_MODESETTING = "xf86-video-modesetting"
