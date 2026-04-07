export THEOS_DEVICE_IP = 127.0.0.1
export THEOS_DEVICE_PORT = 2222

# Enable Rootless/Non-Jailbreak Support
THEOS_PACKAGE_SCHEME = rootless
TARGET = iphone:clang:latest:14.0
ARCHS = arm64

DEBUG = 0
FINALPACKAGE = 1

TWEAK_NAME = FF

# Source Files with updated paths for Flat Structure
FF_FILES = $(wildcard *.mm) \
    $(wildcard *.cpp) \
    $(wildcard *.m) \
    $(wildcard *.c)

# Include paths for all components
FF_CFLAGS = -fobjc-arc -I. -DHOOK_NON_JAILBREAK
FF_CCFLAGS = -std=c++17 -fno-rtti -fno-exceptions -DNDEBUG -I.

# Required Frameworks
FF_FRAMEWORKS = UIKit Foundation Security QuartzCore CoreGraphics CoreText Metal MetalKit
FF_LDFLAGS = -Wl,-segalign,4000

include $(THEOS)/makefiles/common.mk
include $(THEOS_MAKE_PATH)/tweak.mk
