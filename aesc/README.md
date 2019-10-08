# <ins>A</ins>nsi<ins>ESC</ins>ape Module Designs

## Modules

- [csi.h](#csi_hpp)

<a name="csi_hpp"></a>
## [CSI sequences](csi.hpp)

### Namespaces and Functions

namespaces are underlined and functions are not

<ins>aesc</ins>:
- <ins>cursor</ins>:
    - up(n)
    - down(n)
    - forward(n)
    - back(n)
    - next\_line(n)
    - prev\_line(n)
    - EL
    - save\_pos
    - restore\_pos
- <ins>SGR</ins>:
    - reset
    - bold
    - faint
    - italic
    - underline
    - <ins>blink</ins>
        - slow
        - rapid
    - reverse\_color
    - cross\_out
    - reset\_intensity
    - cancel\_underline
    - cancel\_blink
    - cancel\_inverse
    - cancel\_cross\_out
- <ins>color</ins>:
    - black
    - red
    - green
    - yellow
    - blue
    - magenta
    - cyan
    - white
    - <ins>backgound</ins>:
        - black
        - red
        - green
        - yellow
        - blue
        - magenta
        - cyan
        - white
    - <ins>bright</ins>:
        - black
        - red
        - green
        - yellow
        - blue
        - magenta
        - cyan
        - white
        - <ins>background</ins>:
            - black
            - red
            - green
            - yellow
            - blue
            - magenta
            - cyan
            - white
- <ins>color256</ins>:
    - <ins>RGB</ins>:
        - foreground
        - background
    - <ins>grey</ins>:
        - foreground
        - background
- <ins>truecolor</ins>
    - <ins>RGB</ins>:
        - foreground
        - background

