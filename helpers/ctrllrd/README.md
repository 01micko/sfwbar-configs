# ctrllrd

This is a daemon that runs to simulate the key presses of `C-l` and
`C-r` - hence the name.

It is only needed for the `desktop_labwc.widget` as `sfwbar` doesn't
support desktop switching in `labwc`. This also needs the appropriate
configuration in `labwc/rc.xml`

### Why a daemon?

This uses low level kernel code to create the keyboard devices
needed to simulate the 'left control' key, the 'l' key and 'r' key.

This process takes time and would be rather cumbersome to use in a 
graphical environment waiting several seconds each time to create
and destroy the devices.

Instead we create the device once and send `SIGUSR1` to the process to
tell it the we want the 'l' key and `SIGUSR2` for the 'r' key. This
needs elevated privileges for access to `/dev/uinput` to create devices.

---

### Usage

* Compile and place in `PATH`
* Start as a service. You may need to consult your OS docs to do this.

---

Based on [altf1d]

[altf1d]: https://github.com/puppylinux-woof-CE/woof-CE/blob/testing/woof-code/rootfs-petbuilds/labwc/altf1d.c
