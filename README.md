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

These configs and widgets are intended to run on most distros in most compositors
except for some that are specific to `labwc`

#### world clock

See the [world clock](configs/sfwbar/world-clock/Readme-world-clock.md)

#### side bar

See the [side bar](configs/sfwbar/sidebar/Readme-sidebar.md)

### Main config

- `sfwbar.config`

The single main config is responsible for launching the main bar and the
launcher.

[here]: https://github.com/LBCrion/sfwbar
[sfwbar manpage]: https://github.com/LBCrion/sfwbar/blob/main/doc/sfwbar.rst
