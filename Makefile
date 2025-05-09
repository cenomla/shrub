.PHONY: all
all:
	python meson/meson.py install -C build --only-changed
