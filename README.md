# MLIC-tools

## Overview
This repository should provide tools that can be used for capturing and processing Multi Light Image Collections (MLICs).

## Capturing
Captuing ideally happens with a fixed lighting setup. This way it is not necessary to image reference spheres for each image collection. The light directions are stored in text files (light point files) – there are different conventions, depending on the software to use.
The light point files can easily be retrieved through the GUI version of [Relight](https://github.com/cnr-isti-vclab/relight).

I constructed a ring light with 8 LED lamps that can be controlled individually using a Raspberry Pi Pico, which also receives and sends signals through camera trigger cables. This way, the entire process of lighting and camera captures can be automated and included in commercially available focus-stacking and panoramic capturing devices.
The entire setup can be fixed onto the hot shoe of a camera (where usually the flash goes). The image below shows the wiring and the components used in this setup. The total cost of components is about 100 Euros (excluding shipping and tools).

![Wiring diagram](wiring_diagram.png)

The micropython code [mlic_ringlight.py](mlic_ringlight.py) is developed to be used with a DSLR. For mirrorless cameras, the timings can be set faster.

### 3D printable parts
- Ring light housing for a Laowa 25 mm 2.5x objective
- Hot shoe adapter for a Nikon D7200 DSLR

## Processing
For processing of the MLICs the GUI or command line version of [Relight](https://github.com/cnr-isti-vclab/relight) can be used. For combining MLIC capturing with focus stacking, the command line version can be called from a Bash or Python script.

