# sfwbar-configs

My custom configuration files for `sfwbar`

The git repository for `sfwbar` can be found [here].

## Overview

Many of these configs demonstrate the usage of `sfwbar` config language.

### Conditionals

- If()
- Map()
- Lookup()

### String mangling

- Grab()
- Str()
- Pad()
- ReGex()

### Images

- inline svg
- images from GTK icon theme

### Widgets

- chart
- image
- button
- clock

There are many more. Consult the [sfwbar manpage] for more information.

## Configs

Note that some of these are specific to [Puppy Linux] but could easily
be adapted to any system. 

### Grouped configs

- `includes.widget`
- `launcher.widget` and `launcher.css` (separate launcher)

### Individual widgets

|Widget            | Widget type                 | Description
| ---------------- | --------------------------- | -----------
|barlauncher.widget| button and image            | launches menu and apps
|bat.widget        | image - inline svg          | battery monitor
|clock.widget      | clock (puppy specific)      | digital clock
|cpu.widget        | chart                       | CPU usage graph
|firewall.widget   | image (puppy specific)      | state of firewall
|idle.widget       | image - sfwbar idleinhibit  | state of swayidle
|logout.widget     | image (puppy specific)      | raises logout GUI
|network.widget    | image                       | network state and monitor
|pulse.widget      | image                       | pulse audio volume control
|pupusage.widget   | image (puppy specific)      | usage stats
|temp.widget       | image                       | CPU temperature in celcius

### Main config

- `sfwbar.config`

The single main config is responsible for launching the main bar and the
launcher.

## Scripts

These are a few helper scripts for sfwbar.

#### buildmenu.sh

A script that supplies the menu for the `firewall.widget` and the
`network.widget`. You can change the calls to your distro specific
firewall manager and network tools respectively.

#### powerapplet.sh

`bat.widget` depends on this script. There is a *puppyism* in there
calling `gtkdialog-splash`. You can re-work this to use `xmessage`
or even `xterm -e`.

#### vol.sh

This is entirely uneccesary for the `pulse.widget` but is nice to
have for a bit more graphical feedback or if you don't have a scroll-wheel
on your mouse. It depends on [gtkdialog]. Please use the latest stable
version as it has `gtk-layer-shell` support when compiled with GTK3.

[here]: https://github.com/LBCrion/sfwbar
[sfwbar manpage]: https://github.com/LBCrion/sfwbar/blob/main/doc/sfwbar.rst
[Puppy Linux]: https://github.com/puppylinux-woof-CE/woof-CE
[gtkdialog]: https://github.com/puppylinux-woof-CE/gtkdialog
