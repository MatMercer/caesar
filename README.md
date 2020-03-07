# Caesar cipher command line implementation

## Usage

### Simple encryption (without dictionary)
```bash
$ echo "This is the usage" | caesar 12
Ftue ue ftq gemsq

$ echo "Ftue ue ftq gemsq" | caesar -12
This is the usage
```

### Dictionary encryption
```bash
$ echo "This is the usage" | caesar 12 "More Advanced Tutorial"
ahTs Ts chM nsAgM

$ echo "ahTs Ts chM nsAgM" | caesar -12 "More Advanced Tutorial"
This is the usage
```

### Mixing everything up!
```bash
$ echo "This is the usage" | ./caesar 16 "Dictionary" | ./caesar 22 | ./caesar 3 "super"

Pdro ro uda qokca

$ echo "Pdro ro uda qokca" | ./caesar -3 "super" | ./caesar -22 | ./caesar -16 "Dictionary"
This is the usage
```

### Interactive binary

```
$ make caesar-interactive
gcc -o caesarinteractive caesarinteractive.c caesar.c caesar.h
$ caesarinteractive
Specify the data: This is a phrase! Even with ÚTF-8
Specify the key (negative for reverse): 10
Using 10 as the key
Transformed data:

Drsc sc k zrbkco! Ofox gsdr ÚDP-8

$ caesarinteractive
Specify the data: Drsc sc k zrbkco! Ofox gsdr ÚDP-8
Specify the key (negative for reverse): -10
Using -10 as the key
Transformed data:

This is a phrase! Even with ÚTF-8
```
